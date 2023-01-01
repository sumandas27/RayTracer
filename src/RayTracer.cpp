#include <iostream>
#include "RayTracer.hpp"

const float RayTracer::ASPECT_RATIO = 16.0 / 9;
const int RayTracer::IMG_WIDTH = 400;
const int RayTracer::IMG_HEIGHT = static_cast<int>(IMG_WIDTH / ASPECT_RATIO);
const int RayTracer::SAMPLES_PER_PIXEL = 100;
const int RayTracer::MAX_BOUNCES = 2;//50;

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
                pixelColor += calculate_color(ray, world, MAX_BOUNCES);
            }
            
            finalize_accumulated(pixelColor);
            output_color(std::cout, pixelColor);
        }
    }
}

Color RayTracer::calculate_color(const Ray& ray, const HittableList& world, int bouncesLeft) {
    if (bouncesLeft <= 0)
        return Colors::BLACK;

    float infinity = std::numeric_limits<float>::infinity();
    auto [worldIsHit, worldHitRecord] = world.hit(ray, 0, infinity);
    
    if (worldIsHit) {
        constexpr float LIGHT_ABSORPTION = 0.5;
        Vector3 reflectedDirection = worldHitRecord.normal + random_in_unit_sphere();
        Ray reflectedRay = Ray(worldHitRecord.contact, reflectedDirection);
        return LIGHT_ABSORPTION * calculate_color(reflectedRay, world, bouncesLeft - 1);
    }

    Vector3 unitDirection = ila::unit_vector(ray.direction);
    float horizontalScaled = (unitDirection.y() + 1.0) / 2;
        
    Color backgroundColor = (1.0 - horizontalScaled) * Colors::WHITE + horizontalScaled * Colors::SKY_BLUE;
    return backgroundColor;   
}

void RayTracer::finalize_accumulated(Color& accumulatedColor) {
    accumulatedColor /= SAMPLES_PER_PIXEL;

    gamma_correct(accumulatedColor);
    accumulatedColor.r() = std::min(accumulatedColor.r(), 0.999f);
    accumulatedColor.g() = std::min(accumulatedColor.g(), 0.999f);
    accumulatedColor.b() = std::min(accumulatedColor.b(), 0.999f);
}

void RayTracer::gamma_correct(Color& color) {
    color.r() = std::sqrt(color.r());
    color.g() = std::sqrt(color.g());
    color.b() = std::sqrt(color.b());
}