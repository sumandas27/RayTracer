#include "Camera.hpp"

const Point Camera::ORIGIN = Point(0, 0, 0);

Camera::Camera(float aspectRatio, float fieldOfView) {
    float fovInRadians = deg_to_rad(fieldOfView);
    float heightScalar = std::tanf(fovInRadians / 2);

    const float viewportHeight = 2.0 * heightScalar;
    const float viewportWidth = viewportHeight * aspectRatio;
    const float focalLength = 1.0;

    horizontal = Vector3(viewportWidth, 0, 0);
    vertical   = Vector3(0, viewportHeight, 0);
    depth      = Vector3(0, 0, focalLength);

    lowerLeftCorner = ORIGIN - horizontal / 2 - vertical / 2 - depth;
}

Ray Camera::get_ray(float horizontalFactor, float verticalFactor) {
    Vector3 direction = lowerLeftCorner + horizontalFactor * horizontal + verticalFactor * vertical;
    return Ray(ORIGIN, direction);
}