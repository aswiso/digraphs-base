

#include "test.h"
#include "Node.h"


TEST_F(LabTest, test_node) {
    Node a(123);
    Node b(456);
    Node c(789);

    a.add_out_edge(&b);
    a.add_out_edge(&c);
    b.add_out_edge(&c);

    b.add_in_edge(&a);
    c.add_in_edge(&a);
    c.add_in_edge(&b);

    auto a_in = a.get_in_edges();
    auto b_in = b.get_in_edges();
    auto c_in = c.get_in_edges();

    auto a_out = a.get_out_edges();
    auto b_out = b.get_out_edges();
    auto c_out = c.get_out_edges();

    std::vector<Node*> a_in_expected = {};
    std::vector<Node*> b_in_expected = {&a};
    std::vector<Node*> c_in_expected = {&a, &b};

    std::vector<Node*> a_out_expected = {&b, &c};
    std::vector<Node*> b_out_expected = {&c};
    std::vector<Node*> c_out_expected = {};

    ASSERT_EQ(a_in.size(), a_in_expected.size());
    ASSERT_EQ(b_in.size(), b_in_expected.size());
    ASSERT_EQ(c_in.size(), c_in_expected.size());

    ASSERT_EQ(a_out.size(), a_out_expected.size());
    ASSERT_EQ(b_out.size(), b_out_expected.size());
    ASSERT_EQ(c_out.size(), c_out_expected.size());

    // check contents of a_in
    for(auto a : a_in_expected){
        bool found = false;
        for(auto b: a_in){
            if(a == b){
                found = true;
                break;
            }
        }
        ASSERT_TRUE(found);
    }
    // check contents of b_in
    for(auto a : b_in_expected){
        bool found = false;
        for(auto b: b_in){
            if(a == b){
                found = true;
                break;
            }
        }
        ASSERT_TRUE(found);
    }
    // check contents of c_in
    for(auto a : c_in_expected){
        bool found = false;
        for(auto b: c_in){
            if(a == b){
                found = true;
                break;
            }
        }
        ASSERT_TRUE(found);
    }

    // check contents of a_out
    for(auto a : a_out_expected){
        bool found = false;
        for(auto b: a_out){
            if(a == b){
                found = true;
                break;
            }
        }
        ASSERT_TRUE(found);
    }
    // check contents of b_out
    for(auto a : b_out_expected){
        bool found = false;
        for(auto b: b_out){
            if(a == b){
                found = true;
                break;
            }
        }
        ASSERT_TRUE(found);
    }
    // check contents of c_out
    for(auto a : c_out_expected){
        bool found = false;
        for(auto b: c_out){
            if(a == b){
                found = true;
                break;
            }
        }
        ASSERT_TRUE(found);
    }
}

