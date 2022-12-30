#include "Ray.hpp"

Ray::Ray(const Point& _origin, const Vector3& _direction) : 
    origin(_origin), 
    direction(_direction) { }

Point Ray::at(double t) const {
    return origin + t * direction;;
}