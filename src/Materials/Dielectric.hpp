#pragma once
#include "Material.hpp"

class Dielectric : public Material {
public:
    Dielectric(float _indexOfRefraction);

    std::tuple<bool, Ray, Color> scatter(const Ray& inputRay, const HitRecord& hitRecord) const override;

private:
    float indexOfRefraction;

    static float reflectance_schlick_approximation(float cosTheta, float refractionRatio);
};