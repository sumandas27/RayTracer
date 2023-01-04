#pragma once
#include <random>
#include "dependencies/IntrLinAlgLibrary.hpp"

using Vector3 = ila::Vector<3>;
using Color = ila::Vector<3>;
using Point = ila::Vector<3>;

struct Colors {
    static const Color BLACK;
    static const Color RED;
    static const Color WHITE;
    static const Color SKY_BLUE;
};

void output_color(std::ostream& os, const Color& color);
void debug_color (std::ostream& os, const Color& color);

Vector3 multiply_components(const Vector3& v1, const Vector3& v2);

float random_float();
float random_float(float min, float max);

Vector3 random_in_unit_sphere();
Vector3 random_in_hemisphere(const Vector3& direction);

float deg_to_rad(float degrees);
float rad_to_deg(float radians);