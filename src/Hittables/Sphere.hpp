#pragma once
#include "Hittable.hpp"

class Sphere : public Hittable {
public:
    Vector3 center;
    float radius;
    std::shared_ptr<Material> materialPtr;

    Sphere(const Point& _center, float _radius, std::shared_ptr<Material> _materialPtr);

    std::pair<bool, HitRecord> hit(const Ray& ray, float tMin, float tMax) const override;
};