#include "Metal.hpp"
#include "../Hittables/Hittable.hpp"

Metal::Metal(const Color& _albedo, float _fuzz) : Material(_albedo), fuzz(_fuzz < 1 ? _fuzz : 1) { }

std::tuple<bool, Ray, Color> Metal::scatter(const Ray& inputRay, const HitRecord& hitRecord) const {
    Vector3 reflectedDirection = reflect(inputRay.direction, hitRecord.normal);
    Vector3 fuzzedDirection = reflectedDirection + fuzz * random_in_unit_sphere();

    Ray reflectionRay = Ray(hitRecord.contact, fuzzedDirection);
    if (ila::dot(reflectionRay.direction, hitRecord.normal) < 0)
        return std::make_tuple(false, Ray(), Color());

    return std::make_tuple(true, reflectionRay, albedo);
}