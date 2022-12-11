#ifndef CAMERA_H_
#define CAMERA_H_
#include "glm/glm.hpp"
#include "Camera.h"

namespace LightMC
{
    using namespace glm;
    class Camera
    {
    private:
        vec3 position;
        vec3 target;
        vec3 front;
        vec3 right;
        vec3 up;
        float cameraSpeed;
        float yaw, pitch;
    public:
        enum MoveType
        {
            FORWARD,
            BACK,
            LEFT,
            RIGHT,
            UP,
            DOWN
        };
        Camera(vec3 _position, vec3 _front = vec3(.0f, .0f, -1.f));
        mat4 GetViewMatrix() const;
        void MoveCamera(MoveType,float);
        void RotateCamera(float, float);
        void VerticalMove(MoveType);
    };
} // namespace LightMC
#endif