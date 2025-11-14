#include "test.h"
#include "DiGraph.h"
#include "utils.h"


TEST_F(LabTest, test_conversion) {
    // define graph
    DiGraph D;
    D.add_node();
    D.add_node();
    D.add_node();
    D.add_node();
    D.add_node();
    D.add_node();

    D.add_edge(0,1);
    D.add_edge(0,3);
    D.add_edge(1,2);
    D.add_edge(2,4);
    D.add_edge(2,5);
    D.add_edge(3,4);
    // get adjacency matrix
    auto adj_mat = D.get_adjacency_matrix_from_graph();
    // check dimensions
    ASSERT_EQ(adj_mat.get_rows(), 6);
    ASSERT_EQ(adj_mat.get_columns(), 6);
    // check amount of registered edges
    std::int32_t edge_count = 0;
    for(std::int32_t i = 0; i < adj_mat.get_rows(); ++i){
        for(std::int32_t j = 0; j < adj_mat.get_columns(); ++j){
            if(adj_mat.get_content(i, j) == true){
                edge_count++;
            }
        }
    }
    ASSERT_EQ(edge_count, 6);
    // check values
    ASSERT_EQ(adj_mat.get_content(0,0), false);
    ASSERT_EQ(adj_mat.get_content(0,1), true);
    ASSERT_EQ(adj_mat.get_content(0,2), false);
    ASSERT_EQ(adj_mat.get_content(0,3), true);
    ASSERT_EQ(adj_mat.get_content(0,4), false);
    ASSERT_EQ(adj_mat.get_content(0,5), false);

    ASSERT_EQ(adj_mat.get_content(1,0), false);
    ASSERT_EQ(adj_mat.get_content(1,1), false);
    ASSERT_EQ(adj_mat.get_content(1,2), true);
    ASSERT_EQ(adj_mat.get_content(1,3), false);
    ASSERT_EQ(adj_mat.get_content(1,4), false);
    ASSERT_EQ(adj_mat.get_content(1,5), false);

    ASSERT_EQ(adj_mat.get_content(2,0), false);
    ASSERT_EQ(adj_mat.get_content(2,1), false);
    ASSERT_EQ(adj_mat.get_content(2,2), false);
    ASSERT_EQ(adj_mat.get_content(2,3), false);
    ASSERT_EQ(adj_mat.get_content(2,4), true);
    ASSERT_EQ(adj_mat.get_content(2,5), true);

    ASSERT_EQ(adj_mat.get_content(3,0), false);
    ASSERT_EQ(adj_mat.get_content(3,1), false);
    ASSERT_EQ(adj_mat.get_content(3,2), false);
    ASSERT_EQ(adj_mat.get_content(3,3), false);
    ASSERT_EQ(adj_mat.get_content(3,4), true);
    ASSERT_EQ(adj_mat.get_content(3,5), false);

    ASSERT_EQ(adj_mat.get_content(4,0), false);
    ASSERT_EQ(adj_mat.get_content(4,1), false);
    ASSERT_EQ(adj_mat.get_content(4,2), false);
    ASSERT_EQ(adj_mat.get_content(4,3), false);
    ASSERT_EQ(adj_mat.get_content(4,4), false);
    ASSERT_EQ(adj_mat.get_content(4,5), false);

    ASSERT_EQ(adj_mat.get_content(5,0), false);
    ASSERT_EQ(adj_mat.get_content(5,1), false);
    ASSERT_EQ(adj_mat.get_content(5,2), false);
    ASSERT_EQ(adj_mat.get_content(5,3), false);
    ASSERT_EQ(adj_mat.get_content(5,4), false);
    ASSERT_EQ(adj_mat.get_content(5,5), false);
}
