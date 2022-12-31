#include <iostream>
#include "RayTracer.hpp"

const double RayTracer::ASPECT_RATIO = 16.0 / 9;
const int RayTracer::IMG_WIDTH = 400;
const int RayTracer::IMG_HEIGHT = static_cast<int>(IMG_WIDTH / ASPECT_RATIO);

RayTracer::RayTracer() : camera(ASPECT_RATIO) {
    world.add(std::make_shared<Sphere>(Point(0, 0, -1), 0.5));
    world.add(std::make_shared<Sphere>(Point(0, -100.5, -1), 100));
}

void RayTracer::output_image() {
    std::cout << "P3\n" << IMG_WIDTH << " " << IMG_HEIGHT << "\n255\n";
    for (int row = IMG_HEIGHT - 1; row >= 0; row--)
    for (int col = 0; col < IMG_WIDTH; col++) {
        double horizFactor = static_cast<double>(col) / (IMG_WIDTH - 1);
        double vertFactor  = static_cast<double>(row) / (IMG_HEIGHT - 1);

        Vector3 direction = camera.LOWER_LEFT_CORNER + horizFactor * camera.HORIZONTAL + vertFactor * camera.VERTICAL;
        Ray ray = Ray(Camera::ORIGIN, direction);

        Color pixelColor = calculate_color(ray, world);
        output_color(std::cout, pixelColor);
    }
}

Color RayTracer::calculate_color(const Ray& ray, const HittableList& world) {
    double infinity = std::numeric_limits<double>::infinity();
    auto [worldIsHit, worldHitRecord] = world.hit(ray, 0, infinity);
    
    if (!worldIsHit) {
        Vector3 unitDirection = ila::unit_vector(ray.direction);
        double horizontalScaled = (unitDirection.y() + 1.0) / 2;
            
        Color backgroundColor = (1.0 - horizontalScaled) * Colors::WHITE + horizontalScaled * Colors::SKY_BLUE;
        return backgroundColor;     
    }

    Color objectColor = 0.5 * (worldHitRecord.normal + Color(1, 1, 1));
    return objectColor;
}