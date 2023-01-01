#pragma once
#include "Material.hpp"

class Lambertian : public Material {
public:
    Lambertian(const Color& _albedo);

    std::pair<Ray, Color> scattered_ray(const Ray& inputRay, const HitRecord& hitRecord) const override;

private:
    const Color albedo;
};