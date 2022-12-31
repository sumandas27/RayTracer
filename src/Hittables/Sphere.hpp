#pragma once
#include "Hittable.hpp"

class Sphere : public Hittable {
public:
    Vector3 center;
    double radius;

    Sphere(const Point& _center, double _radius);

    std::pair<bool, HitRecord> hit(const Ray& ray, double tMin, double tMax) const override;
};