#include "Sphere.hpp"

Sphere::Sphere(const Point& _center, float _radius) : center(_center), radius(_radius) { }

std::pair<bool, HitRecord> Sphere::hit(const Ray& ray, float tMin, float tMax) const {
    Vector3 originToCenter = ray.origin - center;
    float a = ila::dot(ray.direction, ray.direction);
    float halfB = ila::dot(originToCenter, ray.direction);
    float c = ila::dot(originToCenter, originToCenter) - radius * radius;
    float discriminant = halfB * halfB - a * c;

    if (discriminant < 0)
        return std::make_pair(false, HitRecord());

    float sqrtD = std::sqrt(discriminant);

    float root = (-halfB - sqrtD) / a; /* try '-' root */
    if (root <= tMin || root >= tMax) {
        root = (-halfB + sqrtD) / a;
        if (root <= tMin || root >= tMax) /* try '+' root */
            return std::make_pair(false, HitRecord());
    }

    HitRecord hitRecord = HitRecord();
    hitRecord.t = root;
    hitRecord.contact = ray.at(root);
    Vector3 outwardNormal = ila::unit_vector(hitRecord.contact - center);
    hitRecord.set_normal(ray, outwardNormal);

    return std::pair(true, hitRecord);
}