#pragma once
#include "vectors.hpp"
#include "Camera.hpp"
#include "Ray.hpp"
#include "Hittables/Hittable.hpp"
#include "Hittables/HittableList.hpp"
#include "Hittables/Sphere.hpp"

class RayTracer {
public:
    RayTracer();

    void output_image();

private:
    Camera camera;
    HittableList world;

    static const double ASPECT_RATIO;
    static const int IMG_WIDTH;
    static const int IMG_HEIGHT;

    Color calculate_color(const Ray& ray, const HittableList& world);
};