#include "test.h"

#include <cstdint>
#include <string>
#include <vector>

#include "Node.h"
#include "DiGraph.h"
#include "Matrix.h"
#include "utils.h"


TEST_F(CompileTest, test_utils) {
    DiGraph D;
    D.add_node();
    D.add_node();
    D.add_edge(0,1);
    Matrix<bool> A = D.get_adjacency_matrix_from_graph();
    DiGraph E = get_graph_from_adjacency_matrix(A);
    Matrix<bool> R = get_reachability_matrix(D);
}
