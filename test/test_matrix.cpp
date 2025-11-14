

#include "test.h"
#include "Matrix.h"


TEST_F(LabTest, test_matrix_1) {
    // test get_content 
    // test set_content
    std::int32_t rows = 361;
    std::int32_t columns = 792;
    Matrix<std::int32_t> mat(rows, columns);
    auto content_ptr = mat.get_content_ptr();
    ASSERT_NE(content_ptr, nullptr);

    ASSERT_ANY_THROW(mat.get_content(0, 800));
    ASSERT_ANY_THROW(mat.get_content(800, 0));
    ASSERT_ANY_THROW(mat.get_content(800, 800));

    for(std::int32_t i = 0; i < rows; ++i){
        for(std::int32_t j = 0; j < columns; ++j){
            ASSERT_EQ(mat.get_content(i, j), 0);
        }
    }

    for(std::int32_t i = 0; i < rows; ++i){
        for(std::int32_t j = 0; j < columns; ++j){
            ASSERT_NO_THROW(mat.set_content(i, j, i*columns + j + 71));
        }
    }

    for(std::int32_t i = 0; i < rows; ++i){
        for(std::int32_t j = 0; j < columns; ++j){
            ASSERT_EQ(mat.get_content(i, j), i*columns + j + 71);
        }
    }
}




TEST_F(LabTest, test_matrix_2) {
    // test operator +

    Matrix<bool> a(4,3);
    Matrix<bool> b(6,2);
    ASSERT_ANY_THROW(a+b);
    ASSERT_ANY_THROW(b+a);

    // test numeric values
    Matrix<std::int32_t> A(4,4);
    Matrix<std::int32_t> B(4,4);
    A.set_content(0,0,1);
    A.set_content(1,2,2);
    A.set_content(2,3,4);
    A.set_content(3,1,3);
    B.set_content(0,0,2);
    B.set_content(0,1,2);
    B.set_content(1,1,4);
    B.set_content(1,2,3);
    B.set_content(3,1,1);
    B.set_content(3,3,3);
    auto C = A + B;
    ASSERT_EQ(C.get_columns(), 4);
    ASSERT_EQ(C.get_rows(), 4);

    ASSERT_EQ(C.get_content(0,0), 3);
    ASSERT_EQ(C.get_content(0,1), 2);
    ASSERT_EQ(C.get_content(0,2), 0);
    ASSERT_EQ(C.get_content(0,3), 0);
    ASSERT_EQ(C.get_content(1,0), 0);
    ASSERT_EQ(C.get_content(1,1), 4);
    ASSERT_EQ(C.get_content(1,2), 5);
    ASSERT_EQ(C.get_content(1,3), 0);
    ASSERT_EQ(C.get_content(2,0), 0);
    ASSERT_EQ(C.get_content(2,1), 0);
    ASSERT_EQ(C.get_content(2,2), 0);
    ASSERT_EQ(C.get_content(2,3), 4);
    ASSERT_EQ(C.get_content(3,0), 0);
    ASSERT_EQ(C.get_content(3,1), 4);
    ASSERT_EQ(C.get_content(3,2), 0);
    ASSERT_EQ(C.get_content(3,3), 3);

    // test commutativity
    auto D = B + A;
    ASSERT_EQ(D.get_content(0,0), 3);
    ASSERT_EQ(D.get_content(0,1), 2);
    ASSERT_EQ(D.get_content(0,2), 0);
    ASSERT_EQ(D.get_content(0,3), 0);
    ASSERT_EQ(D.get_content(1,0), 0);
    ASSERT_EQ(D.get_content(1,1), 4);
    ASSERT_EQ(D.get_content(1,2), 5);
    ASSERT_EQ(D.get_content(1,3), 0);
    ASSERT_EQ(D.get_content(2,0), 0);
    ASSERT_EQ(D.get_content(2,1), 0);
    ASSERT_EQ(D.get_content(2,2), 0);
    ASSERT_EQ(D.get_content(2,3), 4);
    ASSERT_EQ(D.get_content(3,0), 0);
    ASSERT_EQ(D.get_content(3,1), 4);
    ASSERT_EQ(D.get_content(3,2), 0);
    ASSERT_EQ(D.get_content(3,3), 3);
    
    // test boolean values
    Matrix<bool> E(3,3);
    Matrix<bool> F(3,3);
    E.set_content(0,0,true);
    E.set_content(0,2,true);
    E.set_content(2,0,true);
    F.set_content(1,1,true);
    F.set_content(2,2,true);
    auto G = E+F;
    ASSERT_EQ(G.get_columns(), 3);
    ASSERT_EQ(G.get_rows(), 3);

    ASSERT_EQ(G.get_content(0,0), true);
    ASSERT_EQ(G.get_content(0,1), false);
    ASSERT_EQ(G.get_content(0,2), true);
    ASSERT_EQ(G.get_content(1,0), false);
    ASSERT_EQ(G.get_content(1,1), true);
    ASSERT_EQ(G.get_content(1,2), false);
    ASSERT_EQ(G.get_content(2,0), true);
    ASSERT_EQ(G.get_content(2,1), false);
    ASSERT_EQ(G.get_content(2,2), true);
}
