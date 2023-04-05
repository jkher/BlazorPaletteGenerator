#ifndef RGBBUCKET_HPP
#define RGBBUCKET_HPP

#include <iostream>

using namespace std;

class RgbBucket
{
private:
    int total_r = 0;
    int total_g = 0;
    int total_b = 0;
    int total_a = 0;

public:
    int Count = 0;
    RgbBucket();
    RgbBucket(int& r, int& g, int& b, int& a);
    void add_pixel(int& r, int& g, int& b, int& a);
    int r_avg();
    int g_avg();
    int b_avg();
    int a_avg();
    string ToHex();
    ~RgbBucket();
};

#endif