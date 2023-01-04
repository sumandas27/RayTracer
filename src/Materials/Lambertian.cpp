#include "Lambertian.hpp"
#include "../Hittables/Hittable.hpp"

Lambertian::Lambertian(const Color& _albedo) : Material(_albedo) { }

std::tuple<bool, Ray, Color> Lambertian::scatter(const Ray& ray, const HitRecord& hitRecord) const {
    Vector3 scatteredDirection = random_in_hemisphere(hitRecord.unitNormal);
    Ray scatteredRay = Ray(hitRecord.contact, scatteredDirection);
    return std::make_tuple(true, scatteredRay, albedo);
}