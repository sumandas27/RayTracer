#include <iostream>
#include "RayTracer.hpp"

const float RayTracer::ASPECT_RATIO = 16.0 / 9;
const int RayTracer::IMG_WIDTH = 400;
const int RayTracer::IMG_HEIGHT = static_cast<int>(IMG_WIDTH / ASPECT_RATIO);
const int RayTracer::SAMPLES_PER_PIXEL = 100;

RayTracer::RayTracer() : camera(ASPECT_RATIO) {
    world.add(std::make_shared<Sphere>(Point(0, 0, -1), 0.5));
    world.add(std::make_shared<Sphere>(Point(0, -100.5, -1), 100));
}

void RayTracer::output_image() {
    std::cout << "P3\n" << IMG_WIDTH << " " << IMG_HEIGHT << "\n255\n";
    for (int row = IMG_HEIGHT - 1; row >= 0; row--) {
        std::cerr << "\rSCANLINES REMAINING: " << row << " " << std::flush;
        for (int col = 0; col < IMG_WIDTH; col++) {
            Color pixelColor(0, 0, 0);
            for (int sample = 0; sample < SAMPLES_PER_PIXEL; sample++) {
                float horizFactor = static_cast<float>(col + random_float()) / (IMG_WIDTH - 1);
                float vertFactor  = static_cast<float>(row + random_float()) / (IMG_HEIGHT - 1);

                Ray ray = camera.get_ray(horizFactor, vertFactor);
                pixelColor += calculate_color(ray, world);
            }
            
            pixelColor /= SAMPLES_PER_PIXEL;
            pixelColor.r() = std::min(pixelColor.r(), 0.999f);
            pixelColor.g() = std::min(pixelColor.g(), 0.999f);
            pixelColor.b() = std::min(pixelColor.b(), 0.999f);
            output_color(std::cout, pixelColor);
        }
    }
}

Color RayTracer::calculate_color(const Ray& ray, const HittableList& world) {
    float infinity = std::numeric_limits<float>::infinity();
    auto [worldIsHit, worldHitRecord] = world.hit(ray, 0, infinity);
    
    if (!worldIsHit) {
        Vector3 unitDirection = ila::unit_vector(ray.direction);
        float horizontalScaled = (unitDirection.y() + 1.0) / 2;
            
        Color backgroundColor = (1.0 - horizontalScaled) * Colors::WHITE + horizontalScaled * Colors::SKY_BLUE;
        return backgroundColor;     
    }

    Color objectColor = 0.5 * (worldHitRecord.normal + Color(1, 1, 1));
    return objectColor;
}