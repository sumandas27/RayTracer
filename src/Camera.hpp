#pragma once
#include "vectors.hpp"

class Camera {
public:
    Camera(double aspectRatio);

    static const Point ORIGIN;

private:
    const double VIEWPORT_WIDTH;
    const double VIEWPORT_HEIGHT;
    const double FOCAL_LENGTH;

public:
    const Vector3 HORIZONTAL;
    const Vector3 VERTICAL;
    const Vector3 DEPTH;
    
    const Vector3 LOWER_LEFT_CORNER;
};