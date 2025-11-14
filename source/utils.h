#pragma once
#include <functional>
#include <string>
#include <fstream>

#include "Matrix.h"
#include "DiGraph.h"
#include "Node.h"

Matrix<bool> get_adjacency_matrix_from_graph(const DiGraph& graph);
DiGraph get_graph_from_adjacency_matrix(const Matrix<bool>& adjacency_matrix);

std::vector<Node*> get_filtered_nodes(const DiGraph& graph, std::function<bool(Node*)> filter_function); 

Matrix<bool> get_reachability_matrix(const DiGraph& graph);

