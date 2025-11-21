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
	Matrix<bool> R = graph.get_adjacency_matrix_from_graph();
	std::int32_t n = A.get_rows();

	//Jeder Knoten ist erreichbar von sich selbst aus
	for (int32_t i = 0; i < n; ++i) {
		R.set_content(i, i, true);
	}

	Matrix<bool> power = graph.get_adjacency_matrix_from_graph();

	//R = A + A^2 + ... + A^n
	for (std::int32_t i = 2; i <= n; ++i){
		//Berechne A^i
		Matrix<bool> next_power(power * A);
		

		//Addiere next_power zu R
		for (std::int32_t ro = 0; ro < n; ++ro) {
			for (std::int32_t col = 0; col < n; ++col) {
				R.set_content(ro, col, R.get_content(ro, col) || next_power.get_content(ro, col));
			}
		}

		//Manuelles Kopieren von next_power, damit es f�r die n�chste Iteration zur Verf�gung steht
		for (std::int32_t ro = 0; ro < n; ++ro) {
			for (std::int32_t col = 0; col < n; ++col) {
				power.set_content(ro, col, next_power.get_content(ro, col));
			}
		}
	}
	
	return R;
}

