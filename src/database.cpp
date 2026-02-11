#include "../inc/database.hpp"
#include "../inc/image.hpp"

#include <iostream>

Database::Database()
{
    db.clear();
    // {
    //     Image img = Image("db/KR0309SV.png");
    //     CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "KR0309SV", {370,200}, {874,808}, {650,564}, {306,78});
    //     db.push_back(car_img);
    // }
    {
        Image img = Image("db/BJ447KH.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "BJ447KH", {228,347}, {933,582}, {762,714}, {220,52});
        db.push_back(car_img);
    }
    // {
    //     Image img = Image("db/CK436DT.png");
    //     CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "CK436DT", {188,250}, {1030,722}, {780,768}, {254,74});
    //     db.push_back(car_img);
    // }
    {
        Image img = Image("db/KR1122NN.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "KR1122NN", {494,386}, {928,784}, {930,744}, {280,82});
        db.push_back(car_img);
    }
    {
        Image img = Image("db/PZ125EP.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "PZ125EP", {110,428}, {1134,588}, {276,840}, {222,62});
        db.push_back(car_img);
    }
    {
        Image img = Image("db/RI7066U.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "RI7066U", {108,210}, {1272,802}, {322,752}, {322,82});
        db.push_back(car_img);
    }
    // {
    //     Image img = Image("db/RI8391L.png");
    //     CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "RI8391L", {128,246}, {1196,714}, {880,736}, {246,70});
    //     db.push_back(car_img);
    // }
    {
        Image img = Image("db/ZG5816JN.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG5816JN", {262,168}, {932,828}, {562,432}, {318,78});
        db.push_back(car_img);
    }
    // {
    //     Image img = Image("db/ZG8888LT.png");
    //     CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG8888LT", {118,308}, {1204,656}, {894,756}, {234,64});
    //     db.push_back(car_img);
    // }
    // { 
    //     Image img = Image("db/ZG9478GV.png");
    //     CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG9478GV", {248,84}, {976,762}, {772,640}, {290,96});
    //     db.push_back(car_img);
    // }
    { 
        Image img = Image("db/ST1020AK.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ST1020AK", {60,41}, {334,279}, {162,264}, {121,29});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ST2020DD.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ST2020DD", {52,30}, {361,283}, {103,221}, {106,46});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ST7289AE.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ST7289AE", {69,45}, {333,265}, {156,257}, {108,27});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ST8458AC.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ST8458AC", {73,100}, {299,219}, {220,208}, {86,30});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ZG3850JM.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG3850JM", {71,40}, {332,271}, {120,214}, {80,32});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/DU8080DU.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "DU8080DU", {64,62}, {333,262}, {162,180}, {117,33});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ZG2238KR.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG2238KR", {68,57}, {332,260}, {200,227}, {101,24});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ZG2412JG.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG2412JG", {50,71}, {355,250}, {211,241}, {101,26});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ZG2452GU.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG2452GU", {26,52}, {390,243}, {264,152}, {92,36});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ZG3369HE.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG3369HE", {70,62}, {316,266}, {172,244}, {112,27});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ZG4125IR.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG4125IR", {73,50}, {309,273}, {170,296}, {117,23});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ZG4485JK.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG4485JK", {74,60}, {314,256}, {206,245}, {106,34});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/KR239HB.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "KR239HB", {86,66}, {279,227}, {144,201}, {68,20});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/KR2005VP.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "KR2005VP", {112,120}, {247,135}, {146,209}, {51,16});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/RI350RH.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "RI350RH", {117,116}, {226,171}, {174,255}, {69,16});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ZG9879JF.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG9879JF", {72,108}, {300,187}, {233,189}, {78,23});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ZG1470FI.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZG1470FI", {71,50}, {302,237}, {116,212}, {85,35});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/KR411JE.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "KR411JE", {107,73}, {251,209}, {193,157}, {80,21});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/OS512RL.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "OS512RL", {105,83}, {253,246}, {211,267}, {77,24});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/OS546KK.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "OS546KK", {58,99}, {339,238}, {112,265}, {90,29});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/OS609LZ.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "OS609LZ", {124,81}, {207,175}, {169,210}, {70,20});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/OS558HS.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "OS558HS", {61,99}, {320,221}, {139,242}, {90,22});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/KR997KD.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "KR997KD", {82,91}, {274,183}, {227,160}, {69,18});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/KR2612ZL.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "KR2612ZL", {36,82}, {386,224}, {306,239}, {65,23});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/ZD272RA.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "ZD272RA", {118,58}, {261,205}, {158,210}, {65,28});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/OS607OA.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "OS607OA", {66,122}, {299,217}, {219,218}, {78,20});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/OS608NT.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "OS608NT", {99,98}, {285,230}, {179,263}, {85,22});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/OS632RK.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "OS632RK", {42,89}, {347,248}, {213,260}, {94,24});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/OS636RB.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "OS636RB", {55,61}, {359,276}, {192,212}, {112,28});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/KR303MJ.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "KR303MJ", {102,112}, {277,150}, {143,202}, {55,14});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/KR398JG.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "KR398JG", {99,112}, {243,149}, {236,169}, {61,17});
        db.push_back(car_img);
    }
    { 
        Image img = Image("db/OS699PC.png");
        CarImage car_img = CarImage(img.resize_pointer(resize_value.first, resize_value.second), "OS699PC", {101,120}, {272,215}, {184,264}, {85,19});
        db.push_back(car_img);
    }
}

Database::~Database(){}

CarImage::CarImage(Image* img, std::string plate, std::pair<int, int> car_location, std::pair<int, int> car_size, std::pair<int, int> plate_location, std::pair<int, int> plate_size){
    m_img = img;
    m_plate = plate;
    m_plate_location = {(float)plate_location.first / (float)img->orginal_w, (float)plate_location.second / (float)img->orginal_h};
    m_plate_size = {(float)plate_size.first / (float)img->orginal_w, (float)plate_size.second / (float)img->orginal_h};
    m_car_location = {(float)car_location.first / (float)img->orginal_w, (float)car_location.second / (float)img->orginal_h};
    m_car_size = {(float)car_size.first / (float)img->orginal_w, (float)car_size.second / (float)img->orginal_h};

    calculateMatrixFromImg();
    calculateOutput();

    //Removes green and blue frames. Only red frame goes into model.
    m_matrix.pop_back();
    m_matrix.pop_back();
}

std::vector<CarImage>& Database::getTrainingSet(){
    return db;
}

void CarImage::calculateMatrixFromImg(){
    Matrix<unsigned char> red;
    Matrix<unsigned char> green;
    Matrix<unsigned char> blue;

    for (int h = 0; h < m_img->h; h++)
    {
        std::vector<unsigned char> red_row;
        std::vector<unsigned char> green_row;
        std::vector<unsigned char> blue_row;

        for (int w = 0; w < m_img->w; w++)
        {
            for (int channels = 0; channels < m_img->channels; channels++)
            {
                if (channels == 0)
                {
                    red_row.push_back(m_img->data[(h * m_img->w * m_img->channels) + (w * m_img->channels) + channels]);
                } else if (channels == 1)
                {
                    green_row.push_back(m_img->data[(h * m_img->w * m_img->channels) + (w * m_img->channels) + channels]);
                } else if (channels == 2)
                {
                    blue_row.push_back(m_img->data[(h * m_img->w * m_img->channels) + (w * m_img->channels) + channels]);
                }
            }
        }

        red.m_data.push_back(red_row);
        green.m_data.push_back(green_row);
        blue.m_data.push_back(blue_row);
    }

    red.m_size = {red.m_data[0].size(), red.m_data.size()};
    green.m_size = {green.m_data[0].size(), green.m_data.size()};
    blue.m_size = {blue.m_data[0].size(), blue.m_data.size()};

    m_matrix.clear();
    m_matrix.resize(3);

    m_matrix[0].m_size = red.m_size;
    m_matrix[1].m_size = red.m_size;
    m_matrix[2].m_size = red.m_size;

    m_matrix[0].setSize(m_matrix[0].m_size);
    m_matrix[1].setSize(m_matrix[1].m_size);
    m_matrix[2].setSize(m_matrix[2].m_size);

    for (int y = 0; y < m_matrix[0].m_size.second; y++)
    {
        for (int x = 0; x < m_matrix[0].m_size.first; x++)
        {
            m_matrix[0].m_data[y][x] = (float)red.m_data[y][x] / (float)256;
            m_matrix[1].m_data[y][x] = (float)green.m_data[y][x] / (float)256;
            m_matrix[2].m_data[y][x] = (float)blue.m_data[y][x] / (float)256;
        }
    }
}

void CarImage::calculateOutput(){
    m_expected_output = {m_car_location.first, m_car_location.second, m_car_size.first, m_car_size.second, m_plate_location.first, m_plate_location.second, m_plate_size.first, m_plate_size.second};
}

std::pair<int, int> Database::getResizeValue(){
    return resize_value;
}