#include "Camera.hpp"

const Point Camera::ORIGIN = Point(-2, 2, 1);
const Point Camera::DESTINATION = Point(0, 0, -1);
const float Camera::HORIZONTAL_OFFSET = 1.0f;
const float Camera::FIELD_OF_VIEW = 90.0f;
const float Camera::FOCUS_DISTANCE = 0.0f;
const float Camera::APERTURE = 0.0f;

Camera::Camera(float aspectRatio) : ASPECT_RATIO(aspectRatio) {
    float fovInRadians = deg_to_rad(FIELD_OF_VIEW);
    float heightScalar = std::tanf(fovInRadians / 2);
    float viewportHeight = 2.0 * heightScalar;
    float viewportWidth = viewportHeight * ASPECT_RATIO;

    Vector3 orthonormalZ = ila::unit_vector(ORIGIN - DESTINATION);
    Vector3 offsetVector = Vector3(0.0f, HORIZONTAL_OFFSET, 0.0f);
    orthonormalX = ila::unit_vector(ila::cross(offsetVector, orthonormalZ));
    orthonormalY = ila::cross(orthonormalZ, orthonormalX);

    horizontal = viewportWidth * orthonormalX;
    vertical = viewportHeight * orthonormalY;
    lowerLeftCorner = ORIGIN - horizontal / 2 - vertical / 2 - orthonormalZ;
}

Ray Camera::get_ray(float horizontalFactor, float verticalFactor) {
    Vector3 direction = lowerLeftCorner + horizontalFactor * horizontal + verticalFactor * vertical - ORIGIN/* - offset*/;
    return Ray(ORIGIN, direction);
}