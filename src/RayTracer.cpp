#include <iostream>
#include "RayTracer.hpp"

const int RayTracer::IMG_WIDTH = 256;
const int RayTracer::IMG_HEIGHT = 256;

void RayTracer::output_image() {
    std::cout << "P3\n" << IMG_WIDTH << " " << IMG_HEIGHT << "\n255\n";
    for (int row = IMG_HEIGHT - 1; row >= 0; row--)
    for (int col = 0; col < IMG_WIDTH; col++) {
        double r = static_cast<double>(row) / (IMG_WIDTH - 1);
        double g = static_cast<double>(col) / (IMG_HEIGHT - 1);
        double b = 0.25;

        Color color = Color(r, g, b);
        output_color(std::cout, color);
    }
}