#include "Sphere.hpp"

Sphere::Sphere(const Point& _center, double _radius) : center(_center), radius(_radius) { }

std::pair<bool, HitRecord> Sphere::hit(const Ray& ray, double tMin, double tMax) const {
    Vector3 originToCenter = ray.origin - center;
    double a = ila::dot(ray.direction, ray.direction);
    double halfB = ila::dot(originToCenter, ray.direction);
    double c = ila::dot(originToCenter, originToCenter) - radius * radius;
    double discriminant = halfB * halfB - a * c;
    
    if (discriminant < 0)
        return std::make_pair(false, HitRecord());

    double sqrtD = std::sqrt(discriminant);

    double root = (-halfB + sqrtD) / a; /* try + root */
    if (root < tMin || root > tMax) {
        root = (-halfB - sqrtD) / a;
        if (root < tMin || root > tMax) /* try - root */
            return std::make_pair(false, HitRecord());
    }

    HitRecord hitRecord = HitRecord();
    hitRecord.t = root;
    hitRecord.contact = ray.at(root);
    hitRecord.normal = ila::unit_vector(hitRecord.contact - center);

    return std::pair(true, hitRecord);
}