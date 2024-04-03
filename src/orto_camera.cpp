/**
 * @file orto_camera.cpp
 * @author Christian Saloň
 */

#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "orto_camera.h"

OrtographicCamera::OrtographicCamera(
    glm::vec3 position,
    glm::vec3 rotation,
    float left,
    float right,
    float bottom,
    float top,
    float nearPlane,
    float farPlane
) : BaseCamera{ position, rotation } {
    this->setProjection(left, right, bottom, top, nearPlane, farPlane);
}

OrtographicCamera::OrtographicCamera(
    glm::vec3 position,
    float left,
    float right,
    float bottom,
    float top, 
    float nearPlane,
    float farPlane
) : BaseCamera{ position, glm::vec3(0.f, 0.f, 0.f) } {
    this->setProjection(left, right, bottom, top, nearPlane, farPlane);
}

OrtographicCamera::OrtographicCamera() : BaseCamera{ glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f) } {
    this->setProjection(-1.f, 1.f, -1.f, 1.f, 0.f, 1.f);
}

void OrtographicCamera::setProjection(
    float left,
    float right,
    float bottom,
    float top,
    float nearPlane,
    float farPlane
) {
    this->_left = left;
    this->_right = right;
    this->_bottom = bottom;
    this->_top = top;
    this->_nearPlane = nearPlane;
    this->_farPlane = farPlane;

    this->_projectionMatrix = glm::ortho(this->_left, this->_right, this->_bottom, this->_top, this->_nearPlane, this->_farPlane);
    this->_projectionMatrix[1][1] *= -1;
}
