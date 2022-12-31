#pragma once
#include "../Ray.hpp"

struct HitRecord {
    Point contact;
    Vector3 normal;
    float t;

    HitRecord();

    void set_normal(const Ray& ray, const Vector3& outwardNormal);
};

class Hittable {
public:
    virtual std::pair<bool, HitRecord> hit(const Ray& ray, float tMin, float tMax) const = 0;  
};