#include "Ray.hpp"

Ray::Ray(const Point& _origin, const Vector3& _direction) : 
    origin(_origin), 
    direction(_direction) { }

Point Ray::at(float t) const {
    return origin + t * direction;;
}