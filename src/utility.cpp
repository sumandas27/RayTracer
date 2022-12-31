#include "utility.hpp"

const Color Colors::RED      = Color(1.0, 0.0, 0.0);
const Color Colors::WHITE    = Color(1.0, 1.0, 1.0);
const Color Colors::SKY_BLUE = Color(0.5, 0.7, 1.0);

void output_color(std::ostream& os, const Color& color) {
    os << static_cast<int>(255.999 * color.r()) << " "
       << static_cast<int>(255.999 * color.g()) << " "
       << static_cast<int>(255.999 * color.b()) << "\n";
}

void debug_color(std::ostream& os, const Color& color) {
    os << static_cast<int>(255.999 * color.r()) << " - "
       << static_cast<int>(255.999 * color.g()) << " - "
       << static_cast<int>(255.999 * color.b()) << "\n"; 
}

constexpr float deg_to_rad(float degrees) {
    return degrees * M_PI / 180.0;
}

constexpr float rad_to_deg(float radians) {
    return radians * 180.0 / M_PI;
}

float random_float() {
    static std::uniform_real_distribution<float> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}