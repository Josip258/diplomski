#include "../inc/convolutional_nn.hpp"
#include "../inc/matrix.hpp"
#include "../inc/car_detection.hpp"
#include "../inc/image.hpp"

void car_detection();

int main(int argc, char const *argv[])
{
    //car_detection();

    CarDetection cd = CarDetection();
    cd.loadModel("model/model26Jan2026-12-47-22.dat");

    //cd.train(100000);

    cd.detectCar("db/RI7066U.png");
    //cd.printOutput();

    //cd.saveModel();
    //cd.train(100000);

    return 0;
}