#include "rgbbucket.hpp"

RgbBucket::RgbBucket() { }

RgbBucket::RgbBucket(int& r, int& g, int& b, int& a)
{
    add_pixel(r, g, b, a);
}

void RgbBucket::add_pixel(int& r, int& g, int& b, int& a)
{
    Count += 1;
    total_r += r;
    total_g += g;
    total_b += b;
    total_a += a;
}

int RgbBucket::r_avg() { if (Count != 0) return total_r / Count; else return 0; }
int RgbBucket::g_avg() { if (Count != 0) return total_g / Count; else return 0; }
int RgbBucket::b_avg() { if (Count != 0) return total_b / Count; else return 0; }
int RgbBucket::a_avg() { if (Count != 0) return total_a / Count; else return 0; }

string RgbBucket::ToHex()
{
    char hexColor[8];
    std::snprintf(hexColor, sizeof hexColor, "#%02x%02x%02x", r_avg(), g_avg(), b_avg());
    return std::string(hexColor);
}

RgbBucket::~RgbBucket() { }