//
// Created by 54367 on 2019/3/1.
//
#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
        : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
        : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

void Camera::invertPitch() {
    Pitch = -Pitch;
    updateCameraVectors();
}




glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(Position, Position + Front, Up);
}

glm::vec3 &Camera::getPosition() {
    return Position;
}

void Camera::setPosition(const glm::vec3 &Position) {
    Camera::Position = Position;
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime) {
    //练习：如果只在平面上移动，则在移动摄像机时取消y轴分量
    glm::vec3 front = glm::normalize(glm::vec3(Front.x, 0, Front.z));
    glm::vec3 right = Right;
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
        Position += front * velocity;
    if (direction == BACKWARD)
        Position -= front * velocity;
    if (direction == LEFT)
        Position -= right * velocity;
    if (direction == RIGHT)
        Position += right * velocity;
    if (direction == UP)
        Position.y += 1.0f * velocity;
    if (direction == DOWN)
        Position.y -= 1.0f * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch) {
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    if (constrainPitch) {
        if (Pitch > 89.0f)
            Pitch = 89.90f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }
    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset) {
    if (Zoom >= 1.0f && Zoom <= 45.0f)
        Zoom -= yoffset;
    if (Zoom <= 1.0f)
        Zoom = 1.0f;
    if (Zoom >= 45.0f)
        Zoom = 45.0f;
}

void Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = static_cast<float>(cos(glm::radians(Yaw)) * cos(glm::radians(Pitch)));
    front.y = static_cast<float>(sin(glm::radians(Pitch)));
    front.z = static_cast<float>(sin(glm::radians(Yaw)) * cos(glm::radians(Pitch)));
    Front = glm::normalize(front);
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}
