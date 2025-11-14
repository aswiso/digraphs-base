#include "test.h"

#include <cstdint>
#include <string>
#include <vector>

#include "DiGraph.h"
#include "Node.h"


TEST_F(CompileTest, test_digraph) {
    DiGraph D;
    std::int32_t x = D.get_node_count();
    Node* y = D.add_node();
    Node* z = D.get_node_by_id(0);
    D.add_node();
    D.add_edge(0, 1);
    D.set_next_free_node_id(42);
}
