#pragma once
#include "Hittable.hpp"

class Sphere : public Hittable {
public:
    Vector3 center;
    float radius;

    Sphere(const Point& _center, float _radius);

    std::pair<bool, HitRecord> hit(const Ray& ray, float tMin, float tMax) const override;
};