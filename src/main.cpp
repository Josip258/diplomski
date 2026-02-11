#include "../inc/convolutional_nn.hpp"
#include "../inc/matrix.hpp"
#include "../inc/car_detection.hpp"
#include "../inc/image.hpp"

void car_detection();

int main(int argc, char const *argv[])
{
    CarDetection cd = CarDetection();
    cd.train(100000);

    // if (argc != 2)
    // {
    //     std::cout << "DetectPlate.exe [img_path]" << std::endl;
    // } else {
    //     cd.detectCar(argv[1]);
    // }


    //cd.loadModelTest("model/final_model.dat");
    //cd.trainTest(100000);

    return 0;
}