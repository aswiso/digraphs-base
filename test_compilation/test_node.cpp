#include "test.h"

#include <cstdint>
#include <string>
#include <vector>

#include "Node.h"



TEST_F(CompileTest, test_node) {
    Node N(42);
    std::int32_t x = N.get_id();
    Node A(21);
    N.add_in_edge(&A);
    N.add_out_edge(&A);
    std::vector<Node*> a = N.get_in_edges();
    std::vector<Node*> b = N.get_out_edges();
}
