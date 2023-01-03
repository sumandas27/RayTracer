#pragma once
#include "../utility.hpp"
#include "../Ray.hpp"

struct HitRecord;

class Material {
public:
    Material();
    Material(Color _albedo);

    virtual std::tuple<bool, Ray, Color> scatter(const Ray& inputRay, const HitRecord& hitRecord) const = 0;

protected:
    const Color albedo;

    Vector3 reflect(const Vector3& ray, const Vector3& normal) const;
    Vector3 refract(const Vector3& inputUnitDirection, const Vector3& normal, float refractionRatio) const;
};