#include "Metal.hpp"
#include "../Hittables/Hittable.hpp"

Metal::Metal(const Color& _albedo, double _fuzz) : Material(_albedo), fuzz(_fuzz < 1 ? _fuzz : 1) { }

std::tuple<bool, Ray, Color> Metal::scatter(const Ray& inputRay, const HitRecord& hitRecord) const {
    Vector3 scatteredDirection = reflect(inputRay.direction, hitRecord.normal);
    Vector3 fuzzedDirection = scatteredDirection + fuzz * random_in_unit_sphere();

    Ray scatteredRay = Ray(hitRecord.contact, fuzzedDirection);
    if (ila::dot(scatteredRay.direction, hitRecord.normal) < 0)
        return std::make_tuple(false, Ray(), Color());

    return std::make_tuple(true, scatteredRay, albedo);
}

Vector3 Metal::reflect(const Vector3& ray, const Vector3& normal) const {
    Vector3 parallelProjection = ila::dot(ray, normal) * normal;
    return ray - 2 * parallelProjection;
}