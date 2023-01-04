#include "Hittable.hpp"

HitRecord::HitRecord() : t(0) { }

void HitRecord::set_normal(const Ray& ray, const Vector3& outwardUnitNormal) {
    facingOutside = ila::dot(ray.direction, outwardUnitNormal) < 0;
    unitNormal = facingOutside ? outwardUnitNormal : -1 * outwardUnitNormal;
}