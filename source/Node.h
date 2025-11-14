#pragma once
#include <vector>
#include <cstdint>

class Node {
    private:
        std::int32_t id;

    public:
        Node(std::int32_t id);
        ~Node();
        std::vector<Node*> in_edges;
        std::vector<Node*> out_edges;
        std::int32_t get_id();
        void add_in_edge(Node* source);
        void add_out_edge(Node* target);
        std::vector<Node*> get_in_edges();
        std::vector<Node*> get_out_edges();
};