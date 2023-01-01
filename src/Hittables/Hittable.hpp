#pragma once
#include "../Ray.hpp"

class Material;

struct HitRecord {
    Point contact;
    Vector3 normal;
    float t;
    std::shared_ptr<Material> materialPtr;

    HitRecord();

    void set_normal(const Ray& ray, const Vector3& outwardNormal);
};

class Hittable {
public:
    virtual std::pair<bool, HitRecord> hit(const Ray& ray, float tMin, float tMax) const = 0;  
};