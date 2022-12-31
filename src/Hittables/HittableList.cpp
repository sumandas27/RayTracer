#include "HittableList.hpp"

void HittableList::clear() {
    hittables.clear();
}

void HittableList::add(const std::shared_ptr<Hittable>& hittable) {
    hittables.emplace_back(hittable);
}

std::pair<bool, HitRecord> HittableList::hit(const Ray& ray, float tMin, float tMax) const {
    bool hitAnything = false;
    float closest = tMax;
    HitRecord hitRecord = HitRecord();

    for (const std::shared_ptr<Hittable>& hittable : hittables) {
        auto [hittableIsHit, hittableHitRecord] = hittable->hit(ray, tMin, tMax);
        if (!hittableIsHit)
            continue;

        hitAnything = true;
        if (closest <= hittableHitRecord.t)
            continue;

        closest = hittableHitRecord.t;
        hitRecord = hittableHitRecord;
    }
    
    return std::make_pair(hitAnything, hitRecord);
}