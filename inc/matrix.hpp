#pragma once

#include <vector>
#include <iostream>
#include <math.h>

template <typename T>
struct Matrix {
    std::vector<std::vector<T>> m_data;
    std::pair<unsigned int, unsigned int> m_size;

    T read(unsigned int x, unsigned int y){
        return m_data[x][y];
    }

    void write(unsigned int x, unsigned int y, T value){
        m_data[y][x] = value;
    }

    void setSize(std::pair<unsigned int, unsigned int> size){
        m_size = size;

        for (int i = 0; i < m_size.second; i++)
        {
            std::vector<T> row = std::vector<T>(m_size.first);
            m_data.push_back(std::move(row));
        }
    }

    void print(){
        for (auto row : m_data)
        {
            for (auto element : row)
            {
                std::cout << element << " ";
            }

            std::cout << std::endl;
        }
    }

    T applyFilterToElement(const Matrix& filter, unsigned int element_x, unsigned int element_y, std::pair<int, int> filter_offset){
        T sum = 0;

        for (unsigned int y = 0; y < filter.m_size.second; y++)
        {
            for (unsigned int x = 0; x < filter.m_size.first; x++)
            {
                sum += m_data[filter_offset.second + element_y + y][filter_offset.first + element_x + x] * filter.m_data[y][x];
            }
        }

        return sum;
    }

    Matrix convolution(const Matrix& filter){
        std::pair<int, int> filter_offset = {(int)filter.m_size.first * -1 + 1, (int)filter.m_size.second * -1 + 1};

        Matrix m;
        m.m_size = {m_size.first + 1 - filter.m_size.first, m_size.second + 1 - filter.m_size.second};

        for (unsigned int y = filter_offset.second * -1; y < filter_offset.second * -1 + (m_size.second - filter.m_size.second) + 1; y++)
        {
            std::vector<T> row;

            for (unsigned int x = filter_offset.first * -1; x < filter_offset.first * -1 + (m_size.first - filter.m_size.first) + 1; x++)
            {
                row.push_back(applyFilterToElement(filter, x, y, filter_offset));
            }

            m.m_data.push_back(row);
        }

        return m;
    }

    void scalarMultiply(T scalar){

        for (unsigned int x = 0; x < m_size.first; x++)
        {
            for (unsigned int y = 0; y < m_size.second; y++)
            {
                m_data[y][x] *= scalar;
            }
        }
    }

    void setAll(T value){

        for (unsigned int x = 0; x < m_size.first; x++)
        {
            for (unsigned int y = 0; y < m_size.second; y++)
            {
                m_data[y][x] = value;
            }
        }
    }

    void add(Matrix<T> matrix){
        for (unsigned int x = 0; x < m_size.first; x++)
        {
            for (unsigned int y = 0; y < m_size.second; y++)
            {
                m_data[y][x] += matrix.m_data[y][x];
            }
        }
    }

    void horizontalFlip(){
        Matrix matrix;
        matrix.setSize(m_size);

        for (unsigned int x = 0; x < m_size.first; x++)
        {
            for (unsigned int y = 0; y < m_size.second; y++)
            {
                matrix.m_data[y][x] = m_data[y][m_size.first - x - 1];
            }
        }

        m_data = matrix.m_data;
    }

    void verticalFlip(){
        Matrix matrix;
        matrix.setSize(m_size);

        for (unsigned int x = 0; x < m_size.first; x++)
        {
            for (unsigned int y = 0; y < m_size.second; y++)
            {
                matrix.m_data[y][x] = m_data[m_size.second - y - 1][x];
            }
        }

        m_data = matrix.m_data;
    }

    T applyFilterToElementFull(const Matrix& filter, unsigned int element_x, unsigned int element_y, std::pair<int, int> filter_offset){
        T sum = 0;

        for (unsigned int y = 0; y < filter.m_size.second; y++)
        {
            for (unsigned int x = 0; x < filter.m_size.first; x++)
            {
                if (element_x + x < 0 || element_y + y < 0 || element_x + x >= m_size.first || element_y + y >= m_size.second)
                {
                    continue;
                }
                
                sum += m_data[element_y + y][element_x + x] * filter.m_data[y][x];
            }
        }

        return sum;
    }

    Matrix fullConvolution(const Matrix& filter){
        std::pair<int, int> filter_offset = {(int)filter.m_size.first - 1, (int)filter.m_size.second - 1};

        Matrix m;
        m.m_size = {(int)m_size.first - 1 + filter.m_size.first, (int)m_size.second - 1 + filter.m_size.second};

        for (int y = filter_offset.second * -1; y < filter_offset.second + ((int)m_size.second - (int)filter.m_size.second) + 1; y++)
        {
            std::vector<T> row;

            for (int x = filter_offset.first * -1; x < filter_offset.first + ((int)m_size.first - (int)filter.m_size.first) + 1; x++)
            {
                row.push_back(applyFilterToElementFull(filter, x, y, filter_offset));
            }

            m.m_data.push_back(row);
        }

        return m;
    }

    Matrix reverseConvolution(const Matrix& filter){
        Matrix m;
        m.m_size = {(int)m_size.first - 1 + filter.m_size.first, (int)m_size.second - 1 + filter.m_size.second};
        for (int i = 0; i < m.m_size.second; i++)
        {
            std::vector<T> row;
            for (int i = 0; i < m.m_size.first; i++)
            {
                row.push_back(0.0f);
            }
            m.m_data.push_back(row);
        }
        

        for (int y = 0; y < m_size.second; y++)
        {
            for (int x = 0; x < m_size.first; x++)
            {
                for (int filter_y = 0; filter_y < filter.m_size.second; filter_y++)
                {
                    for (int filter_x = 0; filter_x < filter.m_size.first; filter_x++)
                    {
                        m.m_data[y + filter_y][x + filter_x] += m_data[y][x] * filter.m_data[filter_y][filter_x];
                    }
                }
            }
        }

        return m;
    }

    Matrix inverse(){
        Matrix mat;
        mat.m_data = getInverse(m_data);
        mat.m_size = {mat.m_data.size(), mat.m_data[0].size()};
        return mat;
    }

    std::vector<T> mulMat(std::vector<T> mat2)
    {
        std::vector<T> result;
        result.resize(m_data.size());

        for (int i = 0; i < m_data.size(); i++) {
            for (int j = 0; j < 1; j++) {
                result[i] = 0;

                for (int k = 0; k < mat2.size(); k++) {
                    result[i] += m_data[i][k] * mat2[k];
                }
            }
        }

        return result;
    }

    void applySigmoid(){
        for (unsigned int x = 0; x < m_size.first; x++)
        {
            for (unsigned int y = 0; y < m_size.second; y++)
            {
                m_data[y][x] = sigmoid(m_data[y][x]);
            }
        }
    }

    void applyDerivativeSigmoid(){
        for (unsigned int x = 0; x < m_size.first; x++)
        {
            for (unsigned int y = 0; y < m_size.second; y++)
            {
                m_data[y][x] = derivativeSigmoid(m_data[y][x]);
            }
        }
    }

    float sigmoid(float value){
        return 1.0f / (1.0f + pow(2.718282f,-1.0 * value));
    }

    float derivativeSigmoid(float value){
        return value * (1.0f - value);
    }

    std::vector<T> getMatrixAsVector(){
        std::vector<T> v;
        
        for (unsigned int y = 0; y < m_size.second; y++)
        {
            for (unsigned int x = 0; x < m_size.first; x++)
            {
                v.push_back(m_data[y][x]);
            }
        }
        
        return v; 
    }

    void setMatrixFromVector(std::vector<T> vec){
        
        for (unsigned int y = 0; y < m_size.second; y++)
        {
            for (unsigned int x = 0; x < m_size.first; x++)
            {
                m_data[y][x] = vec[x + y * m_size.first];
            }
        }
    }
};