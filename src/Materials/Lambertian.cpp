#include "Lambertian.hpp"
#include "../Hittables/Hittable.hpp"

Lambertian::Lambertian(const Color& _albedo) : albedo(_albedo) { }

std::pair<Ray, Color> Lambertian::scattered_ray(const Ray& ray, const HitRecord& hitRecord) const {
    Vector3 reflectedDirection = random_in_hemisphere(hitRecord.normal);
    Ray reflectedRay = Ray(hitRecord.contact, reflectedDirection);
    return std::make_pair(reflectedRay, albedo);
}