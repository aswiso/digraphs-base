#pragma once
#include <cstdint>
#include <unordered_map>
#include <string>

#include "Node.h"
#include "Matrix.h"

class DiGraph {
    private:
        std::int32_t next_free_node_id;
        std::unordered_map<int32_t, Node*> node_map;
    public:
        DiGraph();
        ~DiGraph();
        std::int32_t get_node_count() const;
        Node* add_node();
        Node* add_node_carelessly(std::int32_t new_node_id);
        void set_next_free_node_id(std::int32_t value);
        Node* get_node_by_id(std::int32_t node_id) const;
        void add_edge(std::int32_t source_id, std::int32_t target_id);
        void export_to_dot_file(std::string file_path) const;
        Matrix<bool> get_adjacency_matrix_from_graph() const;

        std::int32_t* get_next_free_node_id_ptr();
        std::unordered_map<int32_t, Node*>* get_node_map_ptr();
};