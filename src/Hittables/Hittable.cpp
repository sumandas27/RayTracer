#include "Hittable.hpp"

HitRecord::HitRecord() : t(0) { }

inline void HitRecord::set_normal(const Ray& ray, const Vector3& outwardNormal) {
    bool frontFace = ila::dot(ray.direction, outwardNormal) < 0;
    normal = frontFace ? outwardNormal : -1 * outwardNormal;
}