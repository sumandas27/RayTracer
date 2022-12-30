#pragma once
#include "Hittable.hpp"
#include "../Ray.hpp"

class HittableList : public Hittable {
public:
    std::vector<std::shared_ptr<Hittable>> hittables;

    void clear();
    void add(const std::shared_ptr<Hittable>& hittable);

    std::pair<bool, HitRecord> hit(const Ray& ray, double tMin, double tMax) const override;
};