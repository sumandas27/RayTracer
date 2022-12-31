#pragma once
#include "../Ray.hpp"

struct HitRecord {
    Point contact;
    Vector3 normal;
    double t;

    HitRecord();

    void set_normal(const Ray& ray, const Vector3& outwardNormal);
};

class Hittable {
public:
    virtual std::pair<bool, HitRecord> hit(const Ray& ray, double tMin, double tMax) const = 0;  
};