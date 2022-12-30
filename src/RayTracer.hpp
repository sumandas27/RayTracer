#pragma once
#include "vectors.hpp"
#include "Camera.hpp"
#include "Ray.hpp"

class RayTracer {
public:
    RayTracer();

    void output_image();

private:
    Camera camera;

    static const double ASPECT_RATIO;
    static const int IMG_WIDTH;
    static const int IMG_HEIGHT;
};