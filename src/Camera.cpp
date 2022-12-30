#include "Camera.hpp"

const Point Camera::ORIGIN = Point(0, 0, 0);

Camera::Camera(double aspectRatio) : 
    VIEWPORT_HEIGHT(2.0), 
    VIEWPORT_WIDTH (2.0 * aspectRatio), 
    FOCAL_LENGTH   (1.0),
    HORIZONTAL(Vector3(VIEWPORT_WIDTH, 0, 0)),
    VERTICAL  (Vector3(0, VIEWPORT_HEIGHT, 0)),
    DEPTH     (Vector3(0, 0, FOCAL_LENGTH)),
    LOWER_LEFT_CORNER(ORIGIN - HORIZONTAL / 2 - VERTICAL / 2 - DEPTH) { }