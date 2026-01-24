#include <cstdlib>
#include <ctime>

#include "../inc/convolutional_nn.hpp"

FullyConnectedLayer::FullyConnectedLayer(unsigned int number_of_inputs, unsigned int number_of_nodes, float learning_rate){
    m_learning_rate = learning_rate;
    m_number_of_inputs = number_of_inputs;
    m_number_of_nodes = number_of_nodes;

    generateRandomWeights(number_of_inputs, number_of_nodes);
}

FullyConnectedLayer::~FullyConnectedLayer(){

}

void FullyConnectedLayer::generateRandomWeights(unsigned int number_of_inputs, unsigned int number_of_nodes){
    srand (static_cast <unsigned> (time(0)));

    m_weights.setSize({number_of_inputs, number_of_nodes});

    for (unsigned int x = 0; x < m_weights.m_size.first; x++)
    {
        for (unsigned int y = 0; y < m_weights.m_size.second; y++)
        {
            float r = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 2)) - 1.0; //Generate a float between [-1, 1]
            m_weights.write(x, y, r);
        }
    }
}

void FullyConnectedLayer::forwardPass(std::vector<float>& input){
    m_output.clear();
    m_last_z.clear();

    m_last_input = input;

    for (unsigned int i_node = 0; i_node < m_number_of_nodes; i_node++)
    {
        float sum = 0.0f;
        for (unsigned int i_input = 0; i_input < m_number_of_inputs; i_input++)
        {
            float z = m_weights.m_data[i_node][i_input] * input[i_input];
            sum += z;
        }

        m_last_z.push_back(sum);
        m_output.push_back(sigmoid(sum));
    }
}

float FullyConnectedLayer::sigmoid(float value){
    return 1.0f / (1.0f + pow(2.718282f,-1.0 * value));
}

const std::vector<float>& FullyConnectedLayer::getOutput() const{
    return m_output;
}

void FullyConnectedLayer::printWeights(){
    m_weights.print();
}

void FullyConnectedLayer::printOutput(){
    for (auto out : m_output)
    {
        std::cout << out << " ";
    }
    std::cout << std::endl;
}

const std::vector<float>& FullyConnectedLayer::getLastInputError() const{
    return m_last_input_error;
}

void FullyConnectedLayer::backPropagation(std::vector<float>& error){
    m_last_input_error.clear();
    m_last_input_error.resize(m_number_of_inputs, 0.0f);

    std::vector<float> error_on_node;
    error_on_node.resize(m_number_of_nodes, 0.0f);

    for (int n = 0; n < m_number_of_nodes; n++)
    {
        error_on_node[n] = derivativeSigmoid(m_output[n]) * error[n];

        for (int i = 0; i < m_number_of_inputs; i++)
        {
            m_last_input_error[i] += m_weights.m_data[n][i] * error_on_node[n];
        }
    }

    for (int n = 0; n < m_number_of_nodes; n++)
    {
        for (int i = 0; i < m_number_of_inputs; i++)
        {
            float delta_weight = m_learning_rate * error_on_node[n] * m_last_input[i];
            m_weights.m_data[n][i] += delta_weight;
        }
    }
}

float FullyConnectedLayer::derivativeSigmoid(float value){
    return value * (1.0f - value);
}

std::vector<float> FullyConnectedLayer::error_delta(std::vector<float> expected_output){
    std::vector<float> error_delta;

    for (unsigned int i = 0; i < expected_output.size(); i++)
    {
        error_delta.push_back(expected_output[i] - m_output[i]);
    }

    return error_delta;
}

void FullyConnectedLayer::printLastInputError(){
    for (auto e : m_last_input_error)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

const std::vector<float>& FullyConnectedLayer::getLastInput() const{
    return m_last_input;
}

const Matrix<float>& FullyConnectedLayer::getWeights() const{
    return m_weights;
}

unsigned int FullyConnectedLayer::getNumberOfFloatsInWeights(){
    return m_weights.m_size.first * m_weights.m_size.second;
}

void FullyConnectedLayer::setWeightsFromVector(std::vector<float> vec){
    m_weights.setMatrixFromVector(vec);
}