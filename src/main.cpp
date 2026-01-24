#include "../inc/convolutional_nn.hpp"
#include "../inc/matrix.hpp"
#include "../inc/car_detection.hpp"
#include "../inc/image.hpp"

void car_detection();

int main(int argc, char const *argv[])
{
    //car_detection();

    CarDetection cd = CarDetection();
    cd.train(100000);
    //cd.loadModel("model/model24Jan2026-02-09-46.dat");

    // cd.forwardPass("db/KR0309SV.png");
    // cd.printOutput();

    //cd.saveModel();
    //cd.train(100000);

    return 0;
}