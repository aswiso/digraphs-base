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

    // DiGraph E = get_graph_from_adjacency_matrix(A);
    // Matrix<bool> R = get_reachability_matrix(D);
    // std::cout << "reachability matrix" << std::endl;
    // for (int i = 0; i < R.get_rows(); ++i) {
    //     for (int j = 0; j < R.get_columns(); ++j) {
    //         std::cout << R.get_content(i, j) << " ";
    //     }
    //     std::cout << std::endl;
    // }

    DiGraph g;

    // Build a small graph
    // 0 → 1
    // 1 → 2
    // 0 → 2 (optional)
    auto* n0 = g.add_node();
    auto* n1 = g.add_node();
    auto* n2 = g.add_node();

    g.add_edge(n0->get_id(), n1->get_id());
    g.add_edge(n1->get_id(), n2->get_id());
    // g.add_edge(n0->get_id(), n2->get_id());

    // Compute reachability matrix
    Matrix<bool> R = get_reachability_matrix(g);

    // Print matrix
    std::cout << "Reachability matrix:\n";
    for (int r = 0; r < R.get_rows(); r++) {
        for (int c = 0; c < R.get_columns(); c++) {
            std::cout << R.get_content(r, c) << " ";
        }
        std::cout << "\n";
    }

	return 0;
}
