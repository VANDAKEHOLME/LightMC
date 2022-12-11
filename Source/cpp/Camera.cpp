#include "Camera.h"
#include "DebugTools.h"
#include <glm/gtc/matrix_transform.hpp>
LightMC::Camera::Camera(vec3 _position, vec3 _front)
{
    position = _position;
    front = normalize(_front);
    right = normalize(cross(vec3(0.f, 1.f, 0.f), front));
    up = normalize(cross(front, right));
    yaw = -87;
    pitch = 0;
    cameraSpeed = 2.5f;
}
/// @brief To return a view matrix of the camera.
/// @return
glm::mat4 LightMC::Camera::GetViewMatrix() const
{
    return lookAt(position, position + front, up);
}
/// @brief To move the camera in its matrix.
/// @param _moveType
/// @param deltaTime
void LightMC::Camera::MoveCamera(MoveType _moveType, float deltaTime)
{
    float velocity = deltaTime * cameraSpeed;
    switch (_moveType)
    {
    case MoveType::FORWARD:
        this->position += velocity * front;
        break;
    case MoveType::BACK:
        this->position -= velocity * front;
        break;
    case MoveType::LEFT:
        this->position += velocity * right;
        break;
    case MoveType::RIGHT:
        this->position -= velocity * right;
        break;
    case MoveType::UP:
        position.y += velocity;
        break;
    case MoveType::DOWN:
        position.y -= velocity;
        break;
    default:
        break;
    }
}
/// @brief To rotate the camera.
/// @param _pitch
/// @param _yow
void LightMC::Camera::RotateCamera(float _xOffset, float _yOffset)
{
    pitch += _yOffset;
    yaw += _xOffset;
    // DebugTools::DebugOutput(std::to_string(pitch), DebugTools::Normal);
    if (pitch >= 89.f)
        pitch = 89;
    if (pitch <= -89.f)
        pitch = -89;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    this->front = normalize(front);
    right = normalize(cross(vec3(0.f, 1.f, 0.f), front));
    up = normalize(cross(front, right));
}
