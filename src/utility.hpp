#pragma once
#include <random>
#include "dependencies/IntrLinAlgLibrary.hpp"

using Vector3 = ila::Vector<3>;
using Color = ila::Vector<3>;
using Point = ila::Vector<3>;

struct Colors {
    static const Color RED;
    static const Color WHITE;
    static const Color SKY_BLUE;
};

void output_color(std::ostream& os, const Color& color);
void debug_color (std::ostream& os, const Color& color);

constexpr float deg_to_rad(float degrees);
constexpr float rad_to_deg(float radians);

float random_float();