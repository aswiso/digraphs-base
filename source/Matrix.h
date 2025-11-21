#pragma once
#include <cstdint>
#include <vector>
#include <iostream>


template <typename T> class Matrix {
    private:
        T* contents = nullptr;
        const std::int32_t rows;
        const std::int32_t columns;

    // Aufgabe 6) + g) supporting template type
    public:

        // Aufgabe 6a)
        Matrix(std::int32_t rows, std::int32_t columns): rows(rows), columns(columns){

            contents = new T[rows * columns]; 

            for (std::int32_t i = 0; i < rows * columns; i++)
            contents[i] = T(0);
        }

        // Aufgabe 6b)
        ~Matrix(){
            delete[] contents;
            contents = nullptr;
        }

        // Aufgabe 6a)
        std::int32_t get_columns() const { 
            return columns; 
        }
        std::int32_t get_rows() const { 
            return rows;
        }

        // Aufgabe 6d)
        std::vector<T> get_row(std::int32_t row){ 
            if (row < 0 || row >= rows)
                throw std::invalid_argument("Invalid row index");
            
            std::vector<T> result(columns);
           // result.reserve(columns); // wegen effizienz

            for (std::int32_t col = 0; col < columns; ++col) {
                result[col] = contents[row * columns + col];
            }
            return result; 
        }

        std::vector<T> get_column(std::int32_t column){ 
            if (column < 0 || column >= columns)
                throw std::invalid_argument("Invalid column index");

            std::vector<T> result(rows);
           // result.reserve(rows);

            for (std::int32_t row = 0; row < rows; ++row){
                result[row] = contents[row * columns + column];
            }
            return result;; 
        }

        // Aufgabe 6c)
        T get_content(std::int32_t row, std::int32_t column) const {
            if (row < 0 || row >= rows || column < 0 || column >= columns)
                throw std::invalid_argument("Invalid row or column index");
            
            return contents[row * columns + column]; // row-major zugriff
        }

        void set_content(std::int32_t row, std::int32_t column, T value){
            if (row < 0 || row >= rows || column < 0 || column >= columns)
            throw std::invalid_argument("Invalid row or column index");

            contents[row * columns + column] = value;

        }

        //Aufgabe 6e)
        Matrix<T> operator+(const Matrix<T>& other){ 
            if (rows != other.rows || columns != other.columns)
                throw std::invalid_argument("Matrices have incompatible dimensions");
            
            Matrix<T> result(rows, columns);

            for (std::int32_t i = 0; i < rows * columns; ++i) {
                result.contents[i] = contents[i] + other.contents[i];
            }

            return result;
        }

        //Aufgabe 6f)
        Matrix<T> operator*(const Matrix<T>& other){ 
            if (columns != other.rows)
                throw std::invalid_argument("Matrices have incompatible dimensions");

            Matrix<T> result(rows, other.columns);

            for (std::int32_t r = 0; r < rows; r++) {
                for (std::int32_t c = 0; c < other.columns; c++) {
                    T sum = T(0);
                    for (std::int32_t k = 0; k < columns; k++) {
                        sum += this->get_content(r, k) * other.get_content(k, c);
                        
                    }
                    result.set_content(r, c, sum);
                }
            }

            return result;
        }

        /* Do not change the code below here */
        /* These functions are used for testing purposes. */
        T* get_content_ptr(){
            return contents;
        }
};