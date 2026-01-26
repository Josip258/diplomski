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

    std::vector<float> m_output;
    std::vector<float> m_expected_output;

    Database database = Database();

public:
    CarDetection();
    ~CarDetection();

    void forwardPass(std::vector<Matrix<float>>& input);
    void backPropagation(std::vector<float>& expected);

    void train(unsigned int number_of_iterations);

    void printOutput();
    void printExpectedOutput();

    void saveModel();
    void loadModel(std::string name);

    void detectCar(const char* filename);

    float getOutputTotalError();
};