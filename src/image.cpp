#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <iostream>
#include "../inc/image.hpp"
#include "../inc/stb-master/stb_image.h"
#include "../inc/stb-master/stb_image_write.h"
#include "../inc/stb-master/stb_image_resize2.h"

Image::Image(const char* filename){
    if (read(filename))
    {
        std::cout << "Read " << filename << std::endl;
        size = w*h*channels;
    } else {
        std::cout << "Failed to read " << filename << std::endl;
    }
}

Image::Image(int w, int h, int channels) : w(w), h(h), channels(channels){
    size = w*h*channels;
    data = new unsigned char[size];
}

Image::Image(const Image& img) : Image(img.w, img.h, img.channels){
    memcpy(data, img.data, size);
}

Image::Image(){}

Image::~Image(){
    stbi_image_free(data);
}

bool Image::read(const char* filename){
    data = stbi_load(filename, &w, &h, &channels, 0);
    return data != NULL;
}

bool Image::write(const char* filename){
    int success = stbi_write_png(filename, w, h, channels, data, w*channels);
    return success != 0;
}

Image Image::resize(int new_w, int new_h){
    Image img(new_w, new_h, channels);
    stbir_resize_uint8_srgb( data,  w,  h,  w * channels,
                              img.data, img.w, img.h, img.w * img.channels,
                              STBIR_RGB );
    img.orginal_h = h;
    img.orginal_w = w;
    
    return img;
}

Image* Image::resize_pointer(int new_w, int new_h){
    Image* img = new Image(new_w, new_h, channels);
    stbir_resize_uint8_srgb( data,  w,  h,  w * channels,
                              img->data, img->w, img->h, img->w * img->channels,
                              STBIR_RGB );
    img->orginal_h = h;
    img->orginal_w = w;
    
    return img;
}