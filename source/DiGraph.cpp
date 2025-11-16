#include "DiGraph.h"
#include "Matrix.h"
#include <stdexcept>
#include <iostream>
#include <fstream>


DiGraph::DiGraph(): next_free_node_id{0}{
    ++next_free_node_id;
}

DiGraph::~DiGraph(){
    for (auto &[id, node] : node_map) delete node;
}

std::int32_t DiGraph::get_node_count() const { 
    return node_map.size(); 
}

Node* DiGraph::add_node(){ 
    Node *new_node = new Node(next_free_node_id);
    node_map[next_free_node_id] = new_node;
    ++next_free_node_id;
    return new_node; 
}

Node* DiGraph::add_node_carelessly(std::int32_t new_node_id){ 
    Node *new_node = new Node(new_node_id);
    node_map[new_node_id] = new_node;
    return new_node;
}

void DiGraph::set_next_free_node_id(std::int32_t value){
    next_free_node_id = value;
}

Node* DiGraph::get_node_by_id(std::int32_t node_id) const { 
    auto it = node_map.find(node_id); 
    if (it != node_map.end()) { 
        return it->second; 
    }
    else throw std::invalid_argument("No corresponding node id found");
}

void DiGraph::add_edge(int32_t source_id, int32_t target_id){
    Node *source_node = DiGraph::get_node_by_id(source_id);
    Node *target_node = DiGraph::get_node_by_id(target_id);
    source_node->add_out_edge(target_node); 
    target_node->add_in_edge(source_node);
}

void DiGraph::export_to_dot_file(std::string file_path) const {
    std::fstream dot_file(file_path);
    dot_file << "digraph {\n";
    for (auto node : node_map){
        for (auto target : node.second->get_out_edges()){
            dot_file << "\t" << node.first << " -> " << target->get_id() << ";\n";
        } 
    }
    dot_file << "}\n";
    dot_file.close();
}

Matrix<bool> DiGraph::get_adjacency_matrix_from_graph() const { 
    // rows and columns of non-existant node 0 are reserved for simplicity
    Matrix<bool> adjacency_matrix(get_node_count() + 1, get_node_count() + 1);
    for (auto node : node_map){
        for (auto target : (*node.second).get_out_edges()){
            adjacency_matrix.set_content(node.first, target->get_id(), true);
        }
    }
    return adjacency_matrix;
 }

/* Do not change the code below here */

/* These functions are used for importing graph from .dot files. */
std::int32_t* DiGraph::get_next_free_node_id_ptr(){
    return &next_free_node_id;
}

std::unordered_map<int32_t, Node*>* DiGraph::get_node_map_ptr(){
    return &node_map;
}
