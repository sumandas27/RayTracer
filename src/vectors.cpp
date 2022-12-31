#include "vectors.hpp"

const Color Colors::RED      = Color(1.0, 0.0, 0.0);
const Color Colors::WHITE    = Color(1.0, 1.0, 1.0);
const Color Colors::SKY_BLUE = Color(0.5, 0.7, 1.0);

void output_color(std::ostream& os, const Color& color) {
    os << static_cast<int>(255.999 * color.r) << " "
       << static_cast<int>(255.999 * color.g) << " "
       << static_cast<int>(255.999 * color.b) << "\n";
}