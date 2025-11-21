#include "Node.h"

//Aufgabe 2a)

Node::Node(std::int32_t id) : id(id) {} // Member-Initializer-List

Node::~Node(){}

// Aufgabe 2b)

std::int32_t Node::get_id() {
     return id; 
    }

void Node::add_in_edge(Node* source){
    in_edges.push_back(source);
}

void Node::add_out_edge(Node* target){
    out_edges.push_back(target);
}

std::vector<Node*> Node::get_in_edges(){ 
    return in_edges; 
}

std::vector<Node*> Node::get_out_edges(){
    return out_edges; 
}