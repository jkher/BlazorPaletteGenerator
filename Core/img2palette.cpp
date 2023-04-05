#ifdef _WIN32
#  define E __declspec( dllexport )
#else
#  define E
#endif

#include "palette.hpp"


extern "C" {
    E Palette* generate_palette(unsigned char* bytes, unsigned int length, unsigned int* totalBuckets)
    {
        return get_colors_from_image(bytes, length, totalBuckets);
    }
}

