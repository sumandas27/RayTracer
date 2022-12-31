#pragma once
#include "utility.hpp"

class Ray {
public:
    Point origin;
    Vector3 direction;

    Ray(const Point& _origin, const Vector3& _direction);

    Point at(double t) const;
};