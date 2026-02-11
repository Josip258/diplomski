#pragma once

struct Image
{
    unsigned char* data = nullptr;
    int size = 0;
    int w;
    int h;
    int channels;

    int orginal_w = 0;
    int orginal_h = 0;

    Image();
    Image(const char* filename);
    Image(int w, int h, int channels);
    Image(const Image& img);
    ~Image();

    bool read(const char* filename);
    bool write(const char* filename);
    
    Image resize(int new_w, int new_h);
    Image* resize_pointer(int new_w, int new_h);
    void grayscale();
    Image crop(int start_x, int start_y, int width, int height);
};
