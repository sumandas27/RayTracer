#pragma once
#include "utility.hpp"
#include "Ray.hpp"

class Camera {
public:
    Camera(float aspectRatio);

    Ray get_ray(float horizontalFactor, float verticalFactor);

private:
    static const float ASPECT_RATIO;
    static const Point ORIGIN;

    Vector3 horizontal;
    Vector3 vertical;
    Vector3 depth;
    Vector3 lowerLeftCorner;
};