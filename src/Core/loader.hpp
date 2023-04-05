#ifndef LOADER_HPP
#define LOADER_HPP

#include <vector>

bool load_image(std::vector<unsigned char>& image, unsigned char* bytes, unsigned int length, int& x, int& y);

#endif