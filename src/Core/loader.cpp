#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "loader.hpp"

bool load_image(std::vector<unsigned char>& image, unsigned char* bytes, unsigned int length, int& x, int& y)
{
    int n;
    unsigned char* data = stbi_load_from_memory(bytes, length, &x, &y, &n, 4);
    if (data != nullptr)
    {
        image = std::vector<unsigned char>(data, data + x * y * 4);
    }
    stbi_image_free(data);
    return (data != nullptr);
}