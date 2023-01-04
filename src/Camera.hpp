#pragma once
#include "utility.hpp"
#include "Ray.hpp"

class Camera {
public:
    Camera(float aspectRatio);

    Ray get_ray(float horizontalFactor, float verticalFactor);

private:
    static const Point ORIGIN;
    static const Point DESTINATION;
    static const float HORIZONTAL_OFFSET;
    static const float FIELD_OF_VIEW;
    static const float FOCUS_DISTANCE;
    static const float APERTURE;

    const float ASPECT_RATIO;

    Vector3 horizontal;
    Vector3 vertical;
    Point lowerLeftCorner;

    Vector3 orthonormalX;
    Vector3 orthonormalY;
    float lensRadius;
};