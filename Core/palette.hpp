#ifndef PALETTE_HPP
#define PALETTE_HPP

struct Palette
{
    int R;
    int G;
    int B;
    double Coverage;
};

Palette* get_colors_from_image(unsigned char* bytes, unsigned int length, unsigned int* totalBuckets);

#endif