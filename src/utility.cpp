#include "utility.hpp"

const Color Colors::BLACK    = Color(0.0, 0.0, 0.0);
const Color Colors::RED      = Color(1.0, 0.0, 0.0);
const Color Colors::WHITE    = Color(1.0, 1.0, 1.0);
const Color Colors::SKY_BLUE = Color(0.5, 0.7, 1.0);

void output_color(std::ostream& os, const Color& color) {
    os << static_cast<int>(256 * color.r()) << " "
       << static_cast<int>(256 * color.g()) << " "
       << static_cast<int>(256 * color.b()) << "\n";
}

void debug_color(std::ostream& os, const Color& color) {
    os << static_cast<int>(256 * color.r()) << " - "
       << static_cast<int>(256 * color.g()) << " - "
       << static_cast<int>(256 * color.b()) << "\n"; 
}

Vector3 multiply_components(const Vector3& v1, const Vector3& v2) {
    Vector3 result = Vector3();
    result.components[0] = v1.components[0] * v2.components[0];
    result.components[1] = v1.components[1] * v2.components[1];
    result.components[2] = v1.components[2] * v2.components[2];
    return result;
}

float random_float() {
    static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    static std::mt19937 generator;
    return distribution(generator);
}

float random_float(float min, float max) {
    return min + (max - min) * random_float();
}

Vector3 random_in_unit_sphere() {
    float x = random_float(-1, 1);
    float y = random_float(-1, 1);
    float z = random_float(-1, 1);
    Vector3 random = Vector3(x, y, z);
    ila::normalize(random);

    float u = random_float();
    float scalar = std::cbrtf(u);
    random *= scalar;
    return random;
} 

Vector3 random_in_hemisphere(const Vector3& direction) {
    Vector3 random = random_in_unit_sphere();
    return (ila::dot(random, direction) >= 0) ? random : -1 * random;
}

float deg_to_rad(float degrees) {
    return degrees * M_PI / 180.0;
}

float rad_to_deg(float radians) {
    return radians * 180.0 / M_PI;
}