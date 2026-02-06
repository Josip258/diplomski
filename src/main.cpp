#include "../inc/convolutional_nn.hpp"
#include "../inc/matrix.hpp"
#include "../inc/car_detection.hpp"
#include "../inc/image.hpp"

void car_detection();

int main(int argc, char const *argv[])
{
    CarDetection cd = CarDetection();
    cd.loadModelTest("model04Feb2026-10-23-57.dat");
    //cd.detectCar("db/RI7066U.png");
    //cd.train(100000);

    //Image img = Image("KR643NZ.png");
    //Image img_resize = img.resize(200, 200);
    //img_resize.grayscale();
    //img_resize.write("resize.png");


    cd.trainTest(100000);

    return 0;
}