#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>

#include "../inc/car_detection.hpp"

CarDetection::CarDetection()
{
    cl1 = new ConvolutionalLayer({11, 11}, 3, 0.01);
    mpl1 = new MaxPoolLayer();
    cl2 = new ConvolutionalLayer({6, 6}, 4, 0.01);
    mpl2 = new MaxPoolLayer();
    fl = new FlattenLayer();
    fcl1 = new FullyConnectedLayer(24300, 254, 0.001);
    fcl2 = new FullyConnectedLayer(254, 8, 0.001);
}

CarDetection::~CarDetection()
{
}

void CarDetection::forwardPass(std::vector<Matrix<float>>& input){

    cl1->forwardPass(input);
    auto cl1_output = cl1->getOutput();

    mpl1->forwardPass(cl1_output);
    auto mpl1_output = mpl1->getOutput();

    cl2->forwardPass(mpl1_output);
    auto cl2_output = cl2->getOutput();

    mpl2->forwardPass(cl2_output);
    auto mpl2_output = mpl2->getOutput();
    
    fl->forwardPass(mpl2_output);
    auto fl_output = fl->getOutput();

    fcl1->forwardPass(fl_output);
    auto fcl1_output = fcl1->getOutput();

    fcl2->forwardPass(fcl1_output);
    m_output = fcl2->getOutput();
}

void CarDetection::printOutput(){
    for (auto out : m_output)
    {
        std::cout << out << " ";
    }
    std::cout << std::endl;
}

void CarDetection::printExpectedOutput(){
    for (auto out : m_expected_output)
    {
        std::cout << out << " ";
    }
    std::cout << std::endl;
}

void CarDetection::backPropagation(std::vector<float>& expected){
    m_expected_output = expected;

    std::vector<float> fcl2_error_delta = fcl2->error_delta(expected);
    fcl2->backPropagation(fcl2_error_delta);

    std::vector<float> fcl1_error_delta = fcl2->getLastInputError();
    fcl1->backPropagation(fcl1_error_delta);

    std::vector<float> fl_error_delta = fcl1->getLastInputError();
    fl->backPropagation(fl_error_delta);

    std::vector<Matrix<float>> mpl2_error_delta = fl->getLastInputError();
    mpl2->backPropagation(mpl2_error_delta);

    std::vector<Matrix<float>> cl2_error_delta = mpl2->getLastInputError();
    cl2->backPropagation(cl2_error_delta);

    std::vector<Matrix<float>> mpl1_error_delta = cl2->getLastInputError();
    mpl1->backPropagation(mpl1_error_delta);

    std::vector<Matrix<float>> cl1_error_delta = mpl1->getLastInputError();
    cl1->backPropagation(cl1_error_delta);
}

void CarDetection::train(unsigned int number_of_iterations){
    for (unsigned int i = 0; i < number_of_iterations; i++)
    {
        bool save = false;
        float total_error = 0.0f;

        for (auto carImage : database.getTrainingSet())
        {
            forwardPass(carImage.m_matrix);
            backPropagation(carImage.m_expected_output);

            if (i % 1000 == 0)
            {
                save = true;
                std::cout << i << std::endl;
                printOutput();
                printExpectedOutput();
                std::cout << std::endl;

                total_error += getOutputTotalError();
            }
        }

        if (save)
        {
            saveModel();
        }

        if (total_error != 0.0f)
        {
            std::cout << "Total error: " << total_error << std::endl;
        }
    }
}

void CarDetection::saveModel(){

    std::time_t t = std::time(nullptr);
    std::string datetime(100,0);
    datetime.resize(std::strftime(&datetime[0], datetime.size(), "%d%b%Y-%I-%M-%S", std::localtime(&t)));
    std::string name = std::string("model/model") + datetime + std::string(".dat");

    std::ofstream out;
    out.open( name, std::ios::out | std::ios::binary);

    for (auto filter : cl1->getFilters())
    {
        for (float f : filter.getMatrixAsVector())
        {
            out.write( reinterpret_cast<const char*>( &f ), sizeof( float ));
        }
    }

    for (auto filter : cl2->getFilters())
    {
        for (float f : filter.getMatrixAsVector())
        {
            out.write( reinterpret_cast<const char*>( &f ), sizeof( float ));
        }
    }
    
    Matrix<float> weight = fcl1->getWeights();
    for (float f : weight.getMatrixAsVector())
    {
        out.write( reinterpret_cast<const char*>( &f ), sizeof( float ));
    }

    weight = fcl2->getWeights();
    for (float f : weight.getMatrixAsVector())
    {
        out.write( reinterpret_cast<const char*>( &f ), sizeof( float ));
    }

    out.close();
}

void CarDetection::loadModel(std::string name){
    std::ifstream in;
    in.open( name, std::ios::in | std::ios::binary);

    std::vector<float> vec;
    for (unsigned int i = 0; i < cl1->getNumberOfFloatsInFilters(); i++)
    {
        float f;
        in.read(reinterpret_cast<char*>( &f ), sizeof( float ));
        vec.push_back(f);
    }
    cl1->setFiltersFromVector(vec);

    vec.clear();
    for (unsigned int i = 0; i < cl2->getNumberOfFloatsInFilters(); i++)
    {
        float f;
        in.read(reinterpret_cast<char*>( &f ), sizeof( float ));
        vec.push_back(f);
    }
    cl2->setFiltersFromVector(vec);

    vec.clear();
    for (unsigned int i = 0; i < fcl1->getNumberOfFloatsInWeights(); i++)
    {
        float f;
        in.read(reinterpret_cast<char*>( &f ), sizeof( float ));
        vec.push_back(f);
    }
    fcl1->setWeightsFromVector(vec);

    vec.clear();
    for (unsigned int i = 0; i < fcl2->getNumberOfFloatsInWeights(); i++)
    {
        float f;
        in.read(reinterpret_cast<char*>( &f ), sizeof( float ));
        vec.push_back(f);
    }
    fcl2->setWeightsFromVector(vec);

    in.close();
}

void CarDetection::detectCar(const char* filename){
    Image img = Image(filename);
    std::pair<int, int> resize_value = database.getResizeValue();
    CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "00000000", {0,0}, {0,0}, {0,0}, {0,0});
    forwardPass(car_img.m_matrix);

    std::pair<int, int> car_location = {m_output[0] * car_img.m_img->orginal_w, m_output[1] * car_img.m_img->orginal_h};
    std::pair<int, int> car_size = {m_output[2] * car_img.m_img->orginal_w, m_output[3] * car_img.m_img->orginal_h};
    std::pair<int, int> plate_location = {m_output[4] * car_img.m_img->orginal_w, m_output[5] * car_img.m_img->orginal_h};
    std::pair<int, int> plate_size = {m_output[6] * car_img.m_img->orginal_w, m_output[7] * car_img.m_img->orginal_h};

    std::cout << "Car location: (" << car_location.first << ", " << car_location.second << "), Size: (" << car_size.first << ", " << car_size.second << ")" << std::endl;
    std::cout << "Plate location: (" << plate_location.first << ", " << plate_location.second << "), Size: (" << plate_size.first << ", " << plate_size.second << ")" << std::endl;
}

float CarDetection::getOutputTotalError(){
    float sum = 0.0f;
    for (int i = 0; i < m_output.size(); i++)
    {
        sum += abs(m_output[i] - m_expected_output[i]);
    }

    return sum;
}