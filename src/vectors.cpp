#include "vectors.hpp"

void output_color(std::ostream& os, const Color& color) {
    os << static_cast<int>(255.999 * color.r) << " "
       << static_cast<int>(255.999 * color.g) << " "
       << static_cast<int>(255.999 * color.b) << "\n";
}