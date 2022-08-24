#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    struct Transform
    {
        glm::vec3 position {1.0f};
        glm::vec3 rotation {1.0f};
        glm::vec3 scale {1.0f};
        real currentAngle {0};

        glm::mat4 GetTransform(void);
    };
    typedef shared_ptr<Transform> p_Transform;
};