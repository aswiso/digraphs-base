#pragma once
#include <cstdint>
#include <vector>
#include <iostream>


template <typename T> class Matrix {
    private:
        T* contents = nullptr;
        const std::int32_t rows;
        const std::int32_t columns;

    public:
        Matrix(std::int32_t rows, std::int32_t columns): rows(0), columns(0){}

        ~Matrix(){}

        std::int32_t get_columns() const { return 0; }
        std::int32_t get_rows() const { return 0; }

        std::vector<T> get_row(std::int32_t row){ return std::vector<T>(); }

        std::vector<T> get_column(std::int32_t column){ return std::vector<T>(); }

        T get_content(std::int32_t row, std::int32_t column) const {return T(0); }

        void set_content(std::int32_t row, std::int32_t column, T value){}

        Matrix<T> operator+(const Matrix<T>& other){ return Matrix<T>(1,1); }

        Matrix<T> operator*(const Matrix<T>& other){ return Matrix<T>(1,1); }

        /* Do not change the code below here */
        /* These functions are used for testing purposes. */
        T* get_content_ptr(){
            return contents;
        }
};