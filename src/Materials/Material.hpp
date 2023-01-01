#pragma once
#include "../utility.hpp"
#include "../Ray.hpp"

struct HitRecord;

class Material {
public:
    Material(Color _albedo);

    virtual std::tuple<bool, Ray, Color> scatter(const Ray& inputRay, const HitRecord& hitRecord) const = 0;

protected:
    const Color albedo;
};