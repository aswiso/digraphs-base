#include "test.h"

#include <cstdint>
#include <string>
#include <vector>

#include "Matrix.h"


TEST_F(CompileTest, test_matrix) {
    Matrix<bool> A(21,41);
    Matrix<std::int32_t> M(5,3);
    std::int32_t x = M.get_columns();
    std::int32_t y = M.get_rows();
    std::vector<std::int32_t> a = M.get_row(0);
    std::vector<std::int32_t> b = M.get_column(0);
    auto c = M.get_content(0,0);
    M.set_content(0,0, 32);
    Matrix<std::int32_t> Mx(5,5);
    Matrix<std::int32_t> My(5,5);
    auto d = Mx + My;
    auto e = Mx * My;
}
