#pragma once
#include "vectors.hpp"

class Ray {
public:
    Point origin;
    Vector3 direction;

    Ray(const Point& _origin, const Vector3& _direction);

    Point at(double scalar) const;
};

Color calculate_color(const Ray& ray);