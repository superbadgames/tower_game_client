#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Entity.hpp"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace Tower
{
    class Camera
    {
    public:
        Camera(void);

        ~Camera(void);

        void InitProjection(F32 fov, F32 aspect, F32 nearDraw, F32 farDraw, const glm::vec3& targetOffset);

        void Update(const glm::vec3& targetPosition);

        const glm::mat4& GetMatrix(void) const
        {
            return _viewMatrix;
        }

    private:
        void _CalculateView(const glm::vec3& cameraPosition);

        glm::vec3 _targetOffset;
        glm::mat4 _viewMatrix;
        glm::mat4 _projectionMatrix;

    };
    typedef shared_ptr<Camera> p_Camera;
}