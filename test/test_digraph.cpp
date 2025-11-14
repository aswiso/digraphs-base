

#include "test.h"
#include "DiGraph.h"


TEST_F(LabTest, test_digraph) {
    DiGraph D;
    Node* n1 = D.add_node();
    Node* n2 = D.add_node();
    Node* n3 = D.add_node();

    ASSERT_NE(n1, nullptr);
    ASSERT_NE(n2, nullptr);
    ASSERT_NE(n3, nullptr);

    D.add_edge(0, 1);
    D.add_edge(1, 2);
    D.add_edge(0, 2);

    ASSERT_EQ(n1->get_in_edges().size(), 0);
    ASSERT_EQ(n1->get_out_edges().size(), 2);
    ASSERT_EQ(n2->get_in_edges().size(), 1);
    ASSERT_EQ(n2->get_out_edges().size(), 1);
    ASSERT_EQ(n3->get_in_edges().size(), 2);
    ASSERT_EQ(n3->get_out_edges().size(), 0);

    bool correct = false;

    // check if n1 in n2.in_edges
    correct = false;
    for(auto n : n2->get_in_edges()){
        if(n == n1){
            correct = true;
            break;
        }
    }
    ASSERT_TRUE(correct);

    // check if n1 in n3.in_edges
    correct = false;
    for(auto n : n3->get_in_edges()){
        if(n == n1){
            correct = true;
            break;
        }
    }
    ASSERT_TRUE(correct);

    // check if n2 in n3.in_edges
    correct = false;
    for(auto n : n3->get_in_edges()){
        if(n == n2){
            correct = true;
            break;
        }
    }
    ASSERT_TRUE(correct);

    // check if n2 in n1.out_edges
    correct = false;
    for(auto n : n1->get_out_edges()){
        if(n == n2){
            correct = true;
            break;
        }
    }
    ASSERT_TRUE(correct);

    // check if n3 in n1.out_edges
    correct = false;
    for(auto n : n1->get_out_edges()){
        if(n == n3){
            correct = true;
            break;
        }
    }
    ASSERT_TRUE(correct);

    // check if n3 in n2.out_edges
    correct = false;
    for(auto n : n2->get_out_edges()){
        if(n == n3){
            correct = true;
            break;
        }
    }
    ASSERT_TRUE(correct);
}