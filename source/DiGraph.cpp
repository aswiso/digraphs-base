#include "DiGraph.h"
#include "Matrix.h"
#include <stdexcept>
#include <iostream>
#include <fstream>


DiGraph::DiGraph() : next_free_node_id(0) {}

DiGraph::~DiGraph(){
    for (auto& pair : node_map) {
        delete pair.second;
    }
    node_map.clear();
}

//temporary fix for test_utils.cpp to run: `DiGraph E = get_graph_from_adjacency_matrix(A);`
//caused apparently by double deletion when there are two shallow copies of DiGraph
//destructor tries to free what has already been freed
DiGraph::DiGraph(const DiGraph& other) {
    next_free_node_id = other.next_free_node_id;
    for (auto& [id, node] : other.node_map) {
        node_map[id] = new Node(*node);
    }
}

DiGraph& DiGraph::operator=(const DiGraph& other) {
    if (this != &other) {
        for (auto& [id, node] : node_map) delete node;
        node_map.clear();
        next_free_node_id = other.next_free_node_id;
        for (auto& [id, node] : other.node_map) {
            node_map[id] = new Node(*node);
        }
    }
    return *this;
}



std::int32_t DiGraph::get_node_count() const { 
    return static_cast<std::int32_t>(node_map.size()); 
}

Node* DiGraph::add_node(){ 
    Node* new_node = new Node(next_free_node_id); 
    node_map[next_free_node_id] = new_node;      
    next_free_node_id++;                        
    return new_node;                           
}

Node* DiGraph::add_node_carelessly(std::int32_t new_node_id){ 
    Node* new_node = new Node(new_node_id);
    node_map[new_node_id] = new_node;
    return new_node; 
}

void DiGraph::set_next_free_node_id(std::int32_t value){
    next_free_node_id = value;
}

Node* DiGraph::get_node_by_id(std::int32_t node_id) const { 
    if (!node_map.contains(node_id)) {
        throw std::invalid_argument("Node ID not found");
    }
    return node_map.at(node_id); 
    
}

void DiGraph::add_edge(int32_t source_id, int32_t target_id){
    

    Node* source_node = get_node_by_id(source_id);
    Node* target_node = get_node_by_id(target_id);


    source_node->add_out_edge(target_node); 
    target_node->add_in_edge(source_node); 
    
}


// Aufgabe 4a)
void DiGraph::export_to_dot_file(std::string file_path) const {
    std::ofstream file(file_path);
    
    file << "digraph {\n";

    for (const auto& pair : node_map) {
        Node* node = pair.second;

        for (Node* target : node->get_out_edges()) {
            file << "\t" << node->get_id() << " -> " << target->get_id() << ";\n";
        }
    }

    file << "}\n";

    file.close();


}



Matrix<bool> DiGraph::get_adjacency_matrix_from_graph() const { 
    std::int32_t max_id = 0;            //größte Knoten ID bestimmen
    for (const auto& pair : node_map) {
        if (pair.first > max_id)
            max_id = pair.first;
    }

    Matrix<bool> matrix(max_id + 1, max_id + 1);


    for (const auto& pair : node_map) {
        Node* node = pair.second;

        for (Node* target : node->get_out_edges()) {
            matrix.set_content(node->get_id(), target->get_id(), true);
        }
    }

    return matrix;

}

/* Do not change the code below here */

/* These functions are used for importing graph from .dot files. */
std::int32_t* DiGraph::get_next_free_node_id_ptr(){
    return &next_free_node_id;
}

std::unordered_map<int32_t, Node*>* DiGraph::get_node_map_ptr(){
    return &node_map;
}
