#pragma once
#include "dependencies/IntrLinAlgLibrary.hpp"

using Vector3 = ila::Vector<3>;
using Color = ila::Vector<3>;
using Point = ila::Vector<3>;

void output_color(std::ostream& os, const Color& color);