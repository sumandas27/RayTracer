#include "Ray.hpp"

Ray::Ray(const Point& _origin, const Vector3& _direction) : 
    origin(_origin), 
    direction(_direction) { }

Point Ray::at(double scalar) const {
    return origin + scalar * direction;;
}

Color calculate_color(const Ray& ray) {
    Vector3 unitDirection = ila::unit_vector(ray.direction);
    double horizontalScaled = (unitDirection.y + 1.0) / 2;

    const Color WHITE = Color(1.0, 1.0, 1.0);
    const Color SKY_BLUE = Color(0.5, 0.7, 1.0);

    Color rayColor = (1.0 - horizontalScaled) * WHITE + horizontalScaled * SKY_BLUE;
    return rayColor;
}