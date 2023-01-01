#pragma once
#include "Material.hpp"

class Lambertian : public Material {
public:
    Lambertian(const Color& _albedo);

    std::tuple<bool, Ray, Color> scatter(const Ray& inputRay, const HitRecord& hitRecord) const override;
};