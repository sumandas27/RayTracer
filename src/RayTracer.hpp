#pragma once
#include "utility.hpp"
#include "Camera.hpp"
#include "Ray.hpp"
#include "Hittables/Hittable.hpp"
#include "Hittables/HittableList.hpp"
#include "Hittables/Sphere.hpp"

//TODO after finish: tMax parameter for hit function?

class RayTracer {
public:
    RayTracer();

    void output_image();

private:
    Camera camera;
    HittableList world;

    static const float ASPECT_RATIO;
    static const int IMG_WIDTH;
    static const int IMG_HEIGHT;
    static const int SAMPLES_PER_PIXEL;

    Color calculate_color(const Ray& ray, const HittableList& world);
};