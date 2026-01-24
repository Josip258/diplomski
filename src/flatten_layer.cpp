#include "../inc/convolutional_nn.hpp"

FlattenLayer::FlattenLayer(){

}

FlattenLayer::~FlattenLayer(){

}

void FlattenLayer::forwardPass(std::vector<Matrix<float>>& input){
    m_output.clear();
    m_last_input = input;
    for (auto i : input)
    {
        for (int y = 0; y < i.m_size.second; y++)
        {
            for (int x = 0; x < i.m_size.first; x++)
            {
                m_output.push_back(i.m_data[y][x]);
            }
        }
    }
}

void FlattenLayer::backPropagation(std::vector<float>& error){
    m_last_input_error.clear();
    m_last_input_error = m_last_input;

    int x_size = m_last_input[0].m_data[0].size();
    int y_size = m_last_input[0].m_data.size();
    int mat_size = x_size * y_size;

    for (int i = 0; i < error.size(); i++)
    {
        int mat = i / mat_size;
        int y = (i % mat_size) / x_size;
        int x = (i % mat_size) - (y * x_size);

        m_last_input_error[mat].m_data[y][x] = error[i];
    }
}

const std::vector<float>& FlattenLayer::getOutput() const{
    return m_output;
}

const std::vector<Matrix<float>>& FlattenLayer::getLastInputError() const{
    return m_last_input_error;
}

void FlattenLayer::printOutput(){
    for (auto out : m_output)
    {
        std::cout << out << " ";
    }
    std::cout << std::endl;
}

void FlattenLayer::printLastInputError(){
    for (auto i : m_last_input_error)
    {
        i.print();
        std::cout << std::endl;
    }
}

void FlattenLayer::printLastInput(){
    for (auto i : m_last_input)
    {
        i.print();
        std::cout << std::endl;
    }
}