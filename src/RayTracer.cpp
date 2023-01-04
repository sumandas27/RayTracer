#include <iostream>
#include "RayTracer.hpp"

const float RayTracer::ASPECT_RATIO = 16.0 / 9;
const int RayTracer::IMG_WIDTH = 400;
const int RayTracer::IMG_HEIGHT = static_cast<int>(IMG_WIDTH / ASPECT_RATIO);

const int RayTracer::SAMPLES_PER_PIXEL = 100;
const int RayTracer::MAX_BOUNCES = 50;

RayTracer::RayTracer() : world(), camera(ASPECT_RATIO) {
    std::shared_ptr<Material> materialGround = std::make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    std::shared_ptr<Material> materialCenter = std::make_shared<Lambertian>(Color(0.1, 0.2, 0.5));
    std::shared_ptr<Material> materialLeft   = std::make_shared<Dielectric>(1.5);
    std::shared_ptr<Material> materialRight  = std::make_shared<Metal>(Color(0.8, 0.6, 0.2), 0.0);

    world.add(std::make_shared<Sphere>(Point( 0.0, -100.5, -1.0), 100.0, materialGround));
    world.add(std::make_shared<Sphere>(Point( 0.0,    0.0, -1.0),   0.5, materialCenter));
    world.add(std::make_shared<Sphere>(Point(-1.0,    0.0, -1.0),   0.5, materialLeft));
    world.add(std::make_shared<Sphere>(Point(-1.0,    0.0, -1.0), -0.45, materialLeft));
    world.add(std::make_shared<Sphere>(Point( 1.0,    0.0, -1.0),   0.5, materialRight));
}

void RayTracer::output_image() {
    std::cout << "P3\n" << IMG_WIDTH << " " << IMG_HEIGHT << "\n255\n";
    for (int row = IMG_HEIGHT - 1; row >= 0; row--) {
        std::cerr << "\rSCANLINES REMAINING: " << row << " " << std::flush;
        for (int col = 0; col < IMG_WIDTH; col++) {
            Color pixelColor(0.0f, 0.0f, 0.0f);
            for (int sample = 0; sample < SAMPLES_PER_PIXEL; sample++) {
                float horizFactor = (col + random_float()) / (IMG_WIDTH - 1);
                float vertFactor  = (row + random_float()) / (IMG_HEIGHT - 1);

                Ray ray = camera.get_ray(horizFactor, vertFactor);
                pixelColor += calculate_color(ray, world, MAX_BOUNCES);
            }
            
            finalize_color(pixelColor);
            output_color(std::cout, pixelColor);
        }
    }
}

Color RayTracer::calculate_color(const Ray& ray, const HittableList& world, int bouncesLeft) {
    if (bouncesLeft <= 0)
        return Colors::BLACK;

    constexpr float CONTACT_START = 0.0001f;
    constexpr float INFTY = std::numeric_limits<float>::infinity();
    auto [worldIsHit, worldHitRecord] = world.hit(ray, CONTACT_START, INFTY);
    
    if (worldIsHit) {
        auto [isValidScatter, scatteredRay, albedo] = worldHitRecord.materialPtr->scatter(ray, worldHitRecord);
        if (isValidScatter) {
            Color scatteredColor = calculate_color(scatteredRay, world, bouncesLeft - 1);
            return multiply_components(scatteredColor, albedo);
        }
        return Colors::BLACK;
    }

    Vector3 unitDirection = ila::unit_vector(ray.direction);
    float horizontalScaled = (unitDirection.y() + 1.0f) / 2;
        
    Color skyColor = (1.0f - horizontalScaled) * Colors::WHITE + horizontalScaled * Colors::SKY_BLUE;
    return skyColor;   
}

void RayTracer::finalize_color(Color& accumulatedColor) {
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