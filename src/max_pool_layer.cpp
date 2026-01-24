#include <algorithm>

#include "../inc/convolutional_nn.hpp"

MaxPoolLayer::MaxPoolLayer(){

}

MaxPoolLayer::~MaxPoolLayer(){

}

void MaxPoolLayer::forwardPass(std::vector<Matrix<float>>& input){
    m_output.clear();
    m_last_input = input;

    for (auto i : input)
    {
        m_output.push_back(maxPool(i));
    }
}

Matrix<float> MaxPoolLayer::maxPool(Matrix<float> matrix){
    //2*2 square, 2 step

    Matrix<float> output;

    for (int y = 0; y < matrix.m_size.second; y += 2)
    {
        std::vector<float> row;

        for (int x = 0; x < matrix.m_size.first; x += 2)
        {
            float value = matrix.m_data[y][x];
            if (x + 1 < matrix.m_size.first){value = std::max(value, matrix.m_data[y][x + 1]);}

            if (y + 1 < matrix.m_size.second){value = std::max(value, matrix.m_data[y + 1][x]);}

            if (x + 1 < matrix.m_size.first && y + 1 < matrix.m_size.second){value = std::max(value, matrix.m_data[y + 1][x + 1]);}
            
            row.push_back(value);
        }

        output.m_data.push_back(row);
    }

    output.m_size = {output.m_data[0].size(), output.m_data.size()};

    return output;
}

void MaxPoolLayer::backPropagation(std::vector<Matrix<float>>& error){
    m_last_input_error.clear();
    m_last_input_error = m_last_input;

    for (int n = 0; n < m_last_input.size(); n++)
    {
        for (int y = 0; y < m_last_input[0].m_data.size(); y++)
        {
            for (int x = 0; x < m_last_input[0].m_data[0].size(); x++)
            {
                if (m_last_input[n].m_data[y][x] == m_output[n].m_data[y / 2][x / 2])
                {
                    m_last_input_error[n].m_data[y][x] = error[n].m_data[y / 2][x / 2];
                } else {
                    m_last_input_error[n].m_data[y][x] = 0.0f;
                }
            }
        }
    }
}

const std::vector<Matrix<float>>& MaxPoolLayer::getOutput() const{
    return m_output;
}

const std::vector<Matrix<float>>& MaxPoolLayer::getLastInputError() const{
    return m_last_input_error;
}

void MaxPoolLayer::printOutput(){
    for (auto o : m_output)
    {
        o.print();
        std::cout << std::endl;
    }
}

void MaxPoolLayer::printLastInput(){
    for (auto i : m_last_input)
    {
        i.print();
        std::cout << std::endl;
    }
}

void MaxPoolLayer::printLastInputError(){
    for (auto i : m_last_input_error)
    {
        i.print();
        std::cout << std::endl;
    }
}