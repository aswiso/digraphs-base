#pragma once
#include <cstdint>
#include <vector>
#include <iostream>


template <typename T> class Matrix {
    static_assert(std::is_arithmetic<T>::value, "T must have numeric or boolean values.");
    private:
        T* contents = nullptr;
        const std::int32_t rows;
        const std::int32_t columns;

    public:
        Matrix(std::int32_t rows, std::int32_t columns): rows(rows), columns(columns){
            contents = new T(columns * rows);
            for (int i = 0; i < columns * rows; i++){
                contents[i] = 0;
            }
        }

        ~Matrix(){delete[] contents;}

        std::int32_t get_columns() const { return columns; }
        std::int32_t get_rows() const { return rows; }

        std::vector<T> get_row(std::int32_t row){ 
            if (row >= rows || row < 0) throw std::invalid_argument("Invalid row value");
            std::vector<T> vector_row;
            vector_row.reserve(columns);
            for (int i = row * columns; i < (row + 1) * columns; i++) vector_row.push_back(contents[i]);
            return vector_row;
         }

        std::vector<T> get_column(std::int32_t column){
            if (column >= columns || column < 0) throw std::invalid_argument("Invalid column value");
            std::vector<T> vector_column;
            vector_column.reserve(rows);
            for (int i = 0; i < rows; i++) vector_column.push_back(contents[i * columns + column]);
            return vector_column;
        }

        T get_content(std::int32_t row, std::int32_t column) const {
            if (row >= rows || row < 0 || column >= columns || column < 0) throw std::invalid_argument("Invalid row/column values");
            return contents[row * columns + column]; 
        }

        void set_content(std::int32_t row, std::int32_t column, T value){
            if (row >= rows || row < 0 || column >= columns || column < 0) throw std::invalid_argument("Invalid row/column values");
            contents[row * columns + column] = value;
        }

        Matrix<T> operator+(const Matrix<T>& other){ 
            if (other.get_columns() != columns || other.get_rows() != rows) throw std::invalid_argument("The given dimensions of the matrices do not match.");
            Matrix<T> sum(rows, columns);
            for (int y = 0; y < rows; y++){
                for (int x = 0; x < columns; x++){
                    sum.set_content(y, x, other.get_content(y, x) + get_content(y, x));
                }
            }
            return sum;
        }

        Matrix<T> operator*(const Matrix<T>& other){ 
            if (other.get_rows() != columns) throw std::invalid_argument("The number of rows of the other matrix should equal the number of columns of the given matrix.");
            Matrix<T> product(rows, other.get_columns());
            for (int y = 0; y < rows; y++) {
                for (int x = 0; x < other.get_columns; x++){
                    // T value = multiply(get_row(y), other.get_column(x));
                    T sum{};
                    for (int i = 0; i < columns; i++){
                        sum += get_content(y, i) * other.get_content(i, x);
                    }
                    product.set_content(y, x, sum);
                }
            }
            return product;
        }

        // T multiply(std::vector<T> row, std::vector<T> column){
        //     T sum{};
        //     for (int i = 0; i < row.size(); i++){
        //         sum += row[i] * column[i];
        //     }
        //     return sum;
        // }

        /* Do not change the code below here */
        /* These functions are used for testing purposes. */
        T* get_content_ptr(){
            return contents;
        }
};