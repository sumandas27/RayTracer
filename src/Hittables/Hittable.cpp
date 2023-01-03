#include "Hittable.hpp"

HitRecord::HitRecord() : t(0) { }

void HitRecord::set_normal(const Ray& ray, const Vector3& outwardNormal) {
    facingOutside = ila::dot(ray.direction, outwardNormal) < 0;
    normal = facingOutside ? outwardNormal : -1 * outwardNormal;
}