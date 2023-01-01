#pragma once
#include "Material.hpp"

class Metal : public Material {
public:
    Metal(const Color& _albedo, double _fuzz);

    std::tuple<bool, Ray, Color> scatter(const Ray& inputRay, const HitRecord& hitRecord) const override;

private:
    const double fuzz;

    Vector3 reflect(const Vector3& ray, const Vector3& normal) const;
};