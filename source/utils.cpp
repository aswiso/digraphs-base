#include "utils.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <unordered_set>


DiGraph get_graph_from_adjacency_matrix(const Matrix<bool>& adjacency_matrix){ 
	std::int32_t n = adjacency_matrix.get_rows();
	std::int32_t m = adjacency_matrix.get_columns();
	if (n != m) {
		throw std::invalid_argument("The given adjacency matrix is not square");
	}
	DiGraph graph;

	//alle Knoten anlegen
	for (std::int32_t id = 0; id < n; ++id) {
		graph.add_node();
	}

	for (std::int32_t r = 0; r < n; ++r) {
		for (std::int32_t c = 0; c < m; ++c) {
			if (adjacency_matrix.get_content(r, c)) {
				graph.add_edge(r, c);
			}
		}
	}

	return graph;
}

Matrix<bool> get_reachability_matrix(const DiGraph& graph){ 
    Matrix<bool> A = graph.get_adjacency_matrix_from_graph();
    int n = A.get_columns();
    for (int i = 0; i < n; i++){
        A.set_content(i, i, true);
    }
    Matrix<bool> reachability_matrix(A);
    Matrix<bool> power(A);
    for (int i = 2; i <= n; i++){
        Matrix<bool> nextPower(A * power);
        {
            Matrix<bool> power(nextPower);
        }
        Matrix<bool> new_reachability_matrix(reachability_matrix + nextPower);
        {
            Matrix<bool> reachability_matrix(new_reachability_matrix);
        }
    }
    
    return reachability_matrix;
}

