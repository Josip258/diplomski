#pragma once

#include <string>
#include <vector>

#include "image.hpp"
#include "matrix.hpp"

struct CarImage{
    Image* m_img;
    std::string m_plate;

    std::pair<float, float> m_car_location;
    std::pair<float, float> m_car_size;

    std::pair<float, float> m_plate_location;
    std::pair<float, float> m_plate_size;

    std::vector<Matrix<float>> m_matrix;
    std::vector<float> m_expected_output;

    CarImage(Image* img, std::string plate, std::pair<int, int> car_location, std::pair<int, int> car_size, std::pair<int, int> plate_location, std::pair<int, int> plate_size);
    void calculateMatrixFromImg();
    void calculateOutput();
};

class Database
{
    private:
        std::vector<CarImage> db;
        std::pair<int, int> resize_value = {100, 100};

    public:
        Database();
        ~Database();

        std::vector<CarImage>& getTrainingSet();
        std::pair<int, int> getResizeValue();
};