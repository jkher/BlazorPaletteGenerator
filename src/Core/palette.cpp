#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>

#include "palette.hpp"
#include "rgbbucket.hpp"
#include "loader.hpp"

using namespace std;

static const int DIMENTION_MAX = 256;
static const int BUCKETS_PER_DIMENTION = 3;
static const size_t RGBA = 4;

string get_pixel_key(int& r, int& g, int& b)
{
    double bucketSize = DIMENTION_MAX / BUCKETS_PER_DIMENTION;
    double redBucket = floor(r / bucketSize);
    double greenBucket = floor(g / bucketSize);
    double blueBucket = floor(b / bucketSize);
    char key[10];
    snprintf(key, sizeof key, "%d:%d:%d", (int)redBucket, (int)greenBucket, (int)blueBucket);
    return string(key);
}

map<string, RgbBucket> get_buckets(unsigned char* bytes, unsigned int length, unsigned int& total_pixels)
{
    map<string, RgbBucket> buckets;
    int width, height;
    std::vector<unsigned char> image;
    bool success = load_image(image, bytes, length, width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            size_t index = RGBA * (y * width + x);
            int r = static_cast<int>(image[index + 0]);
            int g = static_cast<int>(image[index + 1]);
            int b = static_cast<int>(image[index + 2]);
            int a = static_cast<int>(image[index + 3]);

            std::string pixelKey = get_pixel_key(r, g, b);
            map<string, RgbBucket>::iterator it = buckets.find(pixelKey);

            if (it != buckets.end())
                it->second.add_pixel(r, g, b, a);
            else
            {
                RgbBucket bucket = RgbBucket(r, g, b, a);
                buckets.insert(map<string, RgbBucket>::value_type(pixelKey, bucket));
            }

            total_pixels++;
        }
    }

    return buckets;
}

Palette* get_colors_from_image(unsigned char* bytes, unsigned int length, unsigned int* totalBuckets) {
            unsigned int total_pixels = 0;
        auto buckets = get_buckets(bytes, length, total_pixels);

        if (buckets.size() >= 30) *totalBuckets = 30; else *totalBuckets = buckets.size();

        vector<pair<string, RgbBucket>> topBuckets(*totalBuckets);
        partial_sort_copy(
            buckets.begin(),
            buckets.end(),
            topBuckets.begin(),
            topBuckets.end(),
            [](pair<const string, RgbBucket> const& l,
               pair<const string, RgbBucket> const& r)
            {
                return l.second.Count > r.second.Count;
            });

        Palette temp;
        Palette *palette = new Palette[*totalBuckets];
        for (int i = 0; i < topBuckets.size(); i++)
        {
            temp.R = topBuckets[i].second.r_avg();
            temp.G = topBuckets[i].second.g_avg();
            temp.B = topBuckets[i].second.b_avg();
            temp.Coverage = (double)topBuckets[i].second.Count/(double)total_pixels;
            palette[i] = temp;
        }

        buckets.clear();

        return palette;
}
