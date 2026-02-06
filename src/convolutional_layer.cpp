#include <cstdlib>
#include <ctime>

#include "../inc/convolutional_nn.hpp"

ConvolutionalLayer::ConvolutionalLayer(std::pair<unsigned int, unsigned int> filter_size, unsigned int number_of_filters, float learning_rate)
{
    m_filter_size = filter_size;
    m_number_of_filters = number_of_filters;
    m_learning_rate = learning_rate;

    generateRandomFilters();
}

ConvolutionalLayer::~ConvolutionalLayer()
{
}

void ConvolutionalLayer::generateRandomFilters(){
    srand (static_cast <unsigned> (time(0)));

    m_filters.clear();

    for(unsigned int i = 0; i < m_number_of_filters; i++){

        Matrix<float> matrix;
        matrix.setSize(m_filter_size);

        for (unsigned int x = 0; x < m_filter_size.first; x++)
        {
            for (unsigned int y = 0; y < m_filter_size.second; y++)
            {
                float r = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 2)) - 1.0; //Generate a float between [-1, 1]
                matrix.write(x, y, r);
            }
        }

        m_filters.push_back(matrix);
    }
}

void ConvolutionalLayer::printFilters(){
    for (auto filter : m_filters)
    {
        filter.print();
        std::cout << std::endl;
    }
}

const std::vector<Matrix<float>>& ConvolutionalLayer::getOutput() const{
    return m_output;
}

void ConvolutionalLayer::forwardPass(std::vector<Matrix<float>>& input){
    m_output.clear();
    m_last_input = input;
    m_last_input_size = input[0].m_size;

    for (auto i : input)
    {
        for (auto f : m_filters)
        {
            Matrix m = i.convolution(f);
            m.applySigmoid();
            m_output.push_back(m);
        }
    }
}

void ConvolutionalLayer::printOutput(){
    for (auto o : m_output)
    {
        o.print();
        std::cout << std::endl;
    }
}

void ConvolutionalLayer::backPropagation(std::vector<Matrix<float>>& dLd0){
    m_last_input_error.clear();
    m_last_input_error = m_last_input;
    for (int e = 0; e < m_last_input_error.size(); e++){m_last_input_error[e].scalarMultiply(0.0f);}

    std::vector<Matrix<float>> filterDelta = m_filters;
    for (int i = 0; i < filterDelta.size(); i++)
    {
        filterDelta[i].setAll(0.0f);
    }

    for (unsigned i = 0; i < m_last_input.size(); i++)
    {
        for (unsigned f = 0; f < m_filters.size(); f++)
        {
            Matrix<float> delta = m_last_input[i].convolution(dLd0[i * m_filters.size() + f]);
            delta.scalarMultiply(-1.0f * m_learning_rate);
            filterDelta[f].add(delta);

            Matrix<float> filter = m_filters[f];
            Matrix<float> last_input_delta = dLd0[i * m_filters.size() + f].reverseConvolution(filter);
            m_last_input_error[i].add(last_input_delta);
        }
    }

    for (unsigned int f = 0; f < m_filters.size(); f++)
    {
        m_filters[f].add(filterDelta[f]);
        //m_filters[f].limitMatrixValues(1.0f, -1.0f);
    }
}

std::vector<Matrix<float>> ConvolutionalLayer::dLd0(std::vector<Matrix<float>> expected_output){
    std::vector<Matrix<float>> dLd0;

    for (unsigned int i = 0; i < expected_output.size(); i++)
    {
        Matrix<float> value = m_output[i];
        expected_output[i].scalarMultiply(-1.0);
        value.add(expected_output[i]);
        dLd0.push_back(value);
    }

    return dLd0;
}

void ConvolutionalLayer::printLastInputError(){
    for (auto e : m_last_input_error)
    {
        e.print();
        std::cout << std::endl;
    }
}

const std::vector<Matrix<float>>& ConvolutionalLayer::getLastInputError() const{
    return m_last_input_error;
}

float ConvolutionalLayer::derivativeSigmoid(float value){
    return value * (1 - value);
}

float ConvolutionalLayer::sigmoid(float value){
    return 1.0f / (1.0f + pow(2.718282f,-1.0 * value));
}

void ConvolutionalLayer::printLastInput(){
    for (auto i : m_last_input)
    {
        i.print();
        std::cout << std::endl;
    }
}

const std::vector<Matrix<float>>& ConvolutionalLayer::getFilters() const{
    return m_filters;
}

unsigned int ConvolutionalLayer::getNumberOfFloatsInFilters(){
    return m_filters.size() * m_filter_size.first * m_filter_size.second;
}

void ConvolutionalLayer::setFiltersFromVector(std::vector<float> vec){

    for (int i = 0; i < m_filters.size(); i++)
    {
        std::vector<float> filter_vec;

        for (int j = 0; j < m_filter_size.first * m_filter_size.second; j++)
        {
            filter_vec.push_back(vec[0]);
            vec.erase(vec.begin());
        }

        m_filters[i].setMatrixFromVector(filter_vec);
    }
}