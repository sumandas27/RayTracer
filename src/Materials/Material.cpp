#include "Material.hpp"

Material::Material() : albedo() { }

Material::Material(Color _albedo) : albedo(_albedo) { }

Vector3 Material::reflect(const Vector3& ray, const Vector3& normal) const {
    Vector3 parallelProjection = ila::dot(ray, normal) * normal;
    return ray - 2 * parallelProjection;
}

Vector3 Material::refract(const Vector3& inputUnitDirection, const Vector3& normal, float refractionRatio) const {
    float cosTheta = std::min(ila::dot(-1 * inputUnitDirection, normal), 1.0f);

    Vector3 refractedPerpendicular = refractionRatio * (inputUnitDirection + cosTheta * normal);
    double parallelScalar = -std::sqrtf(std::abs(1.0 - ila::dot(refractedPerpendicular, refractedPerpendicular)));
    Vector3 refractedParallel = parallelScalar * normal;
    Vector3 refractedDirection = refractedPerpendicular + refractedParallel;
    return refractedDirection;
}