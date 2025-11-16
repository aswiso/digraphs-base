#include "utils.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <unordered_set>


DiGraph get_graph_from_adjacency_matrix(const Matrix<bool>& adjacency_matrix){ 
    DiGraph graph;
    for (int i = 1; i < adjacency_matrix.get_columns(); i++){
        graph.add_node();
        for (int j = 1; j < adjacency_matrix.get_rows(); j++){
            if (adjacency_matrix.get_content(i, j)) graph.add_edge(i, j);
        }
    }
    return graph;
}

Matrix<bool> get_reachability_matrix(const DiGraph& graph){ 
    Matrix<bool> reachability_matrix = graph.get_adjacency_matrix_from_graph();
    int len = reachability_matrix.get_columns();
    for (int i = 0; i < len; i++){
        reachability_matrix.set_content(i, i, true);
    }
    for (int k = 0; k < len; k++) {
        for (int i = 0; i < len; i++) {
            if (reachability_matrix.get_content(i, k)) {
                for (int j = 0; j < len; j++) {
                    if (reachability_matrix.get_content(k, j)) reachability_matrix.set_content(i, j, true);
                }
            }
        }
    return reachability_matrix;
}

