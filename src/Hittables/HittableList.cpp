#include "HittableList.hpp"

void HittableList::clear() {
    hittables.clear();
}

void HittableList::add(const std::shared_ptr<Hittable>& hittable) {
    hittables.emplace_back(hittable);
}

std::pair<bool, HitRecord> HittableList::hit(const Ray& ray, double tMin, double tMax) const {
    bool hitAnything = false;
    double closest = tMax;
    HitRecord hitRecord = HitRecord();

    for (const std::shared_ptr<Hittable>& hittable : hittables) {
        auto [hittableIsHit, hittableHitRecord] = hittable->hit(ray, tMin, tMax);
        if (!hittableIsHit)
            continue;

        hitAnything = true;
        closest = hittableHitRecord.t;
        hitRecord = hittableHitRecord;
    }
    
    return std::make_pair(hitAnything, hitRecord);
}