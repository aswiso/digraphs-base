#include <fstream>
#include <algorithm>
#include "import.h"


DiGraph get_graph_from_file(const std::string path){
    // reading file contents
    std::ifstream ifs(path);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    // split content into lines
    std::vector<std::string> lines;
    size_t pos = 0;
    std::string line;
    std::string delimiter = "\n";
    while ((pos = content.find(delimiter)) != std::string::npos) {
        line = content.substr(0, pos);
        // remove whitespaces
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());    
        // filter out empty lines
        if(line.size() > 0){
            lines.push_back(line);
        }
        content.erase(0, pos + delimiter.length());
    }
    // remove whitespaces from remaining content
    content.erase(remove_if(content.begin(), content.end(), isspace), content.end());
    // filter out empty lines
    if(content.size() > 0){
        lines.push_back(content);
    }    

    // validate file contents
    if(lines.size() < 2){
        throw std::runtime_error("Invalid contents / formatting!");
    }
    bool contents_invalid = false;
    if(lines[0] != "digraph{"){
        contents_invalid = true;
    }
    if(lines[lines.size()-1] != "}"){
        contents_invalid = true;
    }

    if(! contents_invalid){
        int count_digraph = 0;
        int count_closing_braces = 0;
        for(auto l : lines){
            if( l == "digraph{"){
                count_digraph++;
            }
            else if (l == "}"){
                count_closing_braces++;
            }
        }
        if((count_digraph != 1) or (count_closing_braces != 1)){
            contents_invalid = true;
        }
    }
    if(contents_invalid){
        throw std::runtime_error("Invalid contents / formatting!");
    }

    // parse file contents and construct DiGraph
    DiGraph D;
    auto next_free_node_id_ptr = D.get_next_free_node_id_ptr();
    auto node_map_ptr = D.get_node_map_ptr();
    std::int32_t next_free_node_id = *next_free_node_id_ptr;
    for(auto l : lines){
        if((l == "digraph{") or (l == "}")){
            continue;
        }
        // unpack line contents
        delimiter = "->";
        // source
        pos = l.find(delimiter);
        auto source_node_id_str = l.substr(0, pos);
        l = l.substr(pos + delimiter.size(), l.size()-pos);
        // filter out empty entries
        if(source_node_id_str.size() == 0){
            throw std::runtime_error("Invalid contents / formatting!");
        }
        std::int32_t source_node_id = std::stoi(source_node_id_str);
        // target
        delimiter = ";";
        pos = l.find(delimiter);
        auto target_node_id_str = l.substr(0, pos);
        l = l.substr(pos + delimiter.size(), l.size()-pos);
        // filter out empty entries
        if(target_node_id_str.size() == 0){
            throw std::runtime_error("Invalid contents / formatting!");
        }
        std::int32_t target_node_id = std::stoi(target_node_id_str);
        // register nodes and edge
        if (node_map_ptr->find(source_node_id) == node_map_ptr->end()){
            D.add_node_carelessly(source_node_id);
            if(source_node_id > next_free_node_id){
                next_free_node_id = source_node_id + 1;
            }
        }
        if (node_map_ptr->find(target_node_id) == node_map_ptr->end()){
            D.add_node_carelessly(target_node_id);
            if(target_node_id > next_free_node_id){
                next_free_node_id = target_node_id + 1;
            }
        }
        D.add_edge(source_node_id, target_node_id);
        *next_free_node_id_ptr = next_free_node_id;
    }

    return D;
}