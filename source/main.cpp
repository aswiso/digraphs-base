#include <cstdint>
#include <iostream>
#include "Matrix.h"
#include "DiGraph.h"
#include "Node.h"
#include "utils.h"

int main(int argc, char** argv) {
	std::cout << "Please feel free to implement your own code in the main.cpp." << std::endl;

	DiGraph D;
    D.add_node();
    D.add_node();
    D.add_edge(0,1);
    Matrix<bool> A = D.get_adjacency_matrix_from_graph();
    std::cout << "adjacency matrix" << std::endl;
    for (int i = 0; i < A.get_rows(); ++i) {
        for (int j = 0; j < A.get_columns(); ++j) {
            std::cout << A.get_content(i, j) << " ";
        }
        std::cout << std::endl;
    }

    DiGraph E = get_graph_from_adjacency_matrix(A);
    Matrix<bool> R = get_reachability_matrix(D);
    std::cout << "reachability matrix" << std::endl;
    for (int i = 0; i < R.get_rows(); ++i) {
        for (int j = 0; j < R.get_columns(); ++j) {
            std::cout << R.get_content(i, j) << " ";
        }
        std::cout << std::endl;
    }
	return 0;
}
