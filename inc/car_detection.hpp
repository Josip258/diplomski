#pragma once

#include "convolutional_nn.hpp"
#include "database.hpp"

class CarDetection
{
private:
    ConvolutionalLayer* cl1;
    MaxPoolLayer* mpl1;
    ConvolutionalLayer* cl2;
    MaxPoolLayer* mpl2;
    FlattenLayer* fl;
    FullyConnectedLayer* fcl1;
    FullyConnectedLayer* fcl2;

    FullyConnectedLayer* fcl3;
    FullyConnectedLayer* fcl4;

    std::vector<float> m_output;
    std::vector<float> m_expected_output;

    Database database;

    std::vector<float> current_gradient;
    std::vector<float> momentum = {0, 0, 0, 0, 0, 0, 0, 0};;
    float momentum_beta = 0.9;
    float learning_rate = 0.1;

public:
    CarDetection();
    ~CarDetection();

    void forwardPass(std::vector<Matrix<float>>& input);
    void backPropagation(std::vector<float>& expected);

    void forwardPassTest(std::vector<Matrix<float>>& input);
    void backPropagationTest(std::vector<float>& expected);

    void train(unsigned int number_of_iterations);

    void trainTest(unsigned int number_of_iterations);

    void printOutput();
    void printExpectedOutput();

    void initModel();
    void initModelTest();

    void saveModel();
    void loadModel(std::string name);

    void saveModelTest();
    void loadModelTest(std::string name);

    void detectCar(const char* filename);

    float getOutputTotalError();
    std::vector<float> momentumGradient(std::vector<float> error);
};