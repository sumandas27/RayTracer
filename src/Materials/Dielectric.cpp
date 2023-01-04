#include "Dielectric.hpp"
#include "../Hittables/Hittable.hpp"

Dielectric::Dielectric(float _indexOfRefraction) : Material(Color(1.0, 1.0, 1.0)), indexOfRefraction(_indexOfRefraction) { }

std::tuple<bool, Ray, Color> Dielectric::scatter(const Ray& inputRay, const HitRecord& hitRecord) const {
    float refractionRatio = hitRecord.facingOutside ? (1.0 / indexOfRefraction) : indexOfRefraction;
    Vector3 unitDirection = ila::unit_vector(inputRay.direction);

    float cosTheta = std::min(ila::dot(-1 * unitDirection, hitRecord.unitNormal), 1.0f);
    float sinTheta = std::sqrt(1.0 - cosTheta * cosTheta);

    bool shouldReflect = reflectance_schlick_approximation(cosTheta, refractionRatio) > random_float();
    bool cannotRefract = refractionRatio * sinTheta > 1.0;
    Vector3 scatteredDirection = (shouldReflect || cannotRefract) ?
        reflect(unitDirection, hitRecord.unitNormal) :
        refract(unitDirection, hitRecord.unitNormal, refractionRatio);
    
    Ray scatteredRay = Ray(hitRecord.contact, scatteredDirection);
    return std::make_tuple(true, scatteredRay, albedo);
}

float Dielectric::reflectance_schlick_approximation(float cosTheta, float refractionRatio) {
    float r0 = (1 - refractionRatio) / (1 + refractionRatio);
    r0 *= r0;
    return r0 + (1 - r0) * std::powf(1 - cosTheta, 5);
}