#pragma once

#include <vector>

#include "matrix.hpp"

class Layer
{
    public:
        void forwardPass(std::vector<Matrix<float>>& input);
        void backPropagation(std::vector<Matrix<float>>& error);
        const std::vector<Matrix<float>>& getOutput() const;
        const std::vector<Matrix<float>>& getLastInputError() const;
};

class ConvolutionalLayer : public virtual Layer
{
private:
    std::vector<Matrix<float>> m_filters;
    std::vector<Matrix<float>> m_output;

    std::pair<unsigned int, unsigned int> m_filter_size;
    unsigned int m_number_of_filters;
    float m_learning_rate;

    std::vector<Matrix<float>> m_last_input;
    std::pair<unsigned int, unsigned int> m_last_input_size;
    std::vector<Matrix<float>> m_last_input_error;

    void generateRandomFilters();
    float derivativeSigmoid(float value);
    float sigmoid(float value);

public:
    ConvolutionalLayer(std::pair<unsigned int, unsigned int> filter_size, unsigned int number_of_filters, float learning_rate);
    ~ConvolutionalLayer();

    const std::vector<Matrix<float>>& getOutput() const;

    const std::vector<Matrix<float>>& getFilters() const;
    
    /* Postavlja output
    \param input vektor matrica prijašnjeg sloja, nad kojim se provodi konvolucija filtrima.
    */
    void forwardPass(std::vector<Matrix<float>>& input);

    void printFilters();

    void printOutput();

    void backPropagation(std::vector<Matrix<float>>& error);

    std::vector<Matrix<float>> dLd0(std::vector<Matrix<float>> expected_output);

    void printLastInput();
    void printLastInputError();

    const std::vector<Matrix<float>>& getLastInputError() const;

    unsigned int getNumberOfFloatsInFilters();
    
    void setFiltersFromVector(std::vector<float> vec);
};

class FullyConnectedLayer : public virtual Layer
{
    private:
        Matrix<float> m_weights;
        float m_learning_rate;

        unsigned int m_number_of_inputs;
        unsigned int m_number_of_nodes;

        std::vector<float> m_output;
        std::vector<float> m_last_z;
        std::vector<float> m_last_input;
        std::vector<float> m_last_input_error;

        void generateRandomWeights(unsigned int number_of_inputs, unsigned int number_of_nodes);
        float sigmoid(float value);
        float derivativeSigmoid(float value);
    public:
        FullyConnectedLayer(unsigned int number_of_inputs, unsigned int number_of_nodes, float learning_rate);
        ~FullyConnectedLayer();

        void forwardPass(std::vector<float>& input);
        void backPropagation(std::vector<float>& error);
        const std::vector<float>& getOutput() const;
        const std::vector<float>& getLastInputError() const;
        const std::vector<float>& getLastInput() const;
        const Matrix<float>& getWeights() const;

        std::vector<float> error_delta(std::vector<float> expected_output);

        void printWeights();
        void printOutput();
        void printLastInputError();

         unsigned int getNumberOfFloatsInWeights();
    
        void setWeightsFromVector(std::vector<float> vec);
};

class MaxPoolLayer : public virtual Layer
{
    private:
        std::vector<Matrix<float>> m_output;
        std::vector<Matrix<float>> m_last_input;
        std::vector<Matrix<float>> m_last_input_error;

        Matrix<float> maxPool(Matrix<float> matrix);

    public:
        MaxPoolLayer();
        ~MaxPoolLayer();

        void forwardPass(std::vector<Matrix<float>>& input);
        void backPropagation(std::vector<Matrix<float>>& error);
        const std::vector<Matrix<float>>& getOutput() const;
        const std::vector<Matrix<float>>& getLastInputError() const;

        void printOutput();
        void printLastInput();
        void printLastInputError();
};

class FlattenLayer : public virtual Layer
{
    private:
        std::vector<float> m_output;
        std::vector<Matrix<float>> m_last_input;
        std::vector<Matrix<float>> m_last_input_error;

    public:
        FlattenLayer();
        ~FlattenLayer();

        void forwardPass(std::vector<Matrix<float>>& input);
        void backPropagation(std::vector<float>& error);
        const std::vector<float>& getOutput() const;
        const std::vector<Matrix<float>>& getLastInputError() const;

        void printOutput();
        void printLastInputError();
        void printLastInput();
};