#include <iostream>
#include "RayTracer.hpp"

const double RayTracer::ASPECT_RATIO = 16.0 / 9;
const int RayTracer::IMG_WIDTH = 400;
const int RayTracer::IMG_HEIGHT = static_cast<int>(IMG_WIDTH / ASPECT_RATIO);

RayTracer::RayTracer() : camera(ASPECT_RATIO) {
    world.add(std::make_shared<Sphere>(Point(0, 0, -1), 0.5));
}

void RayTracer::output_image() {
    std::cout << "P3\n" << IMG_WIDTH << " " << IMG_HEIGHT << "\n255\n";
    for (int row = IMG_HEIGHT - 1; row >= 0; row--)
    for (int col = 0; col < IMG_WIDTH; col++) {
        double horizFactor = static_cast<double>(col) / (IMG_WIDTH - 1);
        double vertFactor  = static_cast<double>(row) / (IMG_HEIGHT - 1);

        Vector3 direction = camera.LOWER_LEFT_CORNER + horizFactor * camera.HORIZONTAL + vertFactor * camera.VERTICAL;
        Ray ray = Ray(Camera::ORIGIN, direction);

        Color color = calculate_color(ray, world);
        output_color(std::cout, color);
    }
}

Color RayTracer::calculate_color(const Ray& ray, const HittableList& world) {
    double infinity = std::numeric_limits<double>::infinity();
    auto [worldIsHit, worldHitRecord] = world.hit(ray, 0, infinity);
    
    if (!worldIsHit) {
        Vector3 unitDirection = ila::unit_vector(ray.direction);
        double horizontalScaled = (unitDirection.y + 1.0) / 2;
        
        Color rayColor = (1.0 - horizontalScaled) * Colors::WHITE + horizontalScaled * Colors::SKY_BLUE;
        return rayColor;
    }

    Color rayColor = 0.5 * (worldHitRecord.normal + Colors::WHITE);
    return rayColor;
}