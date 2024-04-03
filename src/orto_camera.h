/**
 * @file orto_camera.h
 * @author Christian Saloň
 */

#pragma once

#include <glm/vec3.hpp>

#include "base_camera.h"

class OrtographicCamera : public BaseCamera {

private:

    // In pixels
    float _left;
    float _right;
    float _bottom;
    float _top;
    float _nearPlane;
    float _farPlane;

public:

    OrtographicCamera(
        glm::vec3 position,
        glm::vec3 rotation,
        float left,
        float right,
        float bottom,
        float top,
        float nearPlane,
        float farPlane
    );
    OrtographicCamera(
        glm::vec3 position,
        float left,
        float right,
        float bottom,
        float top,
        float nearPlane,
        float farPlane
    );
    OrtographicCamera();

    void setProjection(
        float left,
        float right,
        float bottom,
        float top,
        float nearPlane,
        float farPlane
    );

};
