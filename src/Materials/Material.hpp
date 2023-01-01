#pragma once
#include "../utility.hpp"
#include "../Ray.hpp"

struct HitRecord;

class Material {
public:
    virtual std::pair<Ray, Color> scattered_ray(const Ray& inputRay, const HitRecord& hitRecord) const = 0;
};