#pragma once
#include "vectors.hpp"

class RayTracer {
public:
    void output_image();

private:
    static const int IMG_WIDTH;
    static const int IMG_HEIGHT;
};