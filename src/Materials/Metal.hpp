#pragma once
#include "Material.hpp"

class Metal : public Material {
public:
    Metal(const Color& _albedo, float _fuzz);

    std::tuple<bool, Ray, Color> scatter(const Ray& inputRay, const HitRecord& hitRecord) const override;

private:
    const float fuzz;
};