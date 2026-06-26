// filepath: c:\Users\robby\OneDrive\Desktop\Programming\FPS\src\Engine\Camera.cpp
#include "Engine/Camera.h"
#include <glm/gtc/constants.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
	: m_Position(position), m_Up(up), m_Yaw(yaw), m_Pitch(pitch)
{
	UpdateDirection();
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(m_Position, m_Position + m_Direction, m_Up);
}

glm::mat4 Camera::GetProjectionMatrix(float aspect, float fov, float nearPlane, float farPlane) const
{
	return glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
}

void Camera::SetPosition(const glm::vec3& position)
{
	m_Position = position;
}

void Camera::SetDirection(float yaw, float pitch)
{
	m_Yaw = yaw;
	m_Pitch = glm::clamp(pitch, -89.0f, 89.0f);
	UpdateDirection();
}

void Camera::SetUp(const glm::vec3& up)
{
	m_Up = glm::normalize(up);
}

glm::vec3 Camera::GetPosition() const
{
	return m_Position;
}

glm::vec3 Camera::GetDirection() const
{
	return m_Direction;
}

glm::vec3 Camera::GetUp() const
{
	return m_Up;
}

glm::vec3 Camera::GetRight() const
{
	return m_Right;
}

void Camera::UpdateDirection()
{
	glm::vec3 direction;
	direction.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	direction.y = sin(glm::radians(m_Pitch));
	direction.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Direction = glm::normalize(direction);

	m_Right = glm::normalize(glm::cross(m_Direction, glm::vec3(0.0f, 1.0f, 0.0f)));
	m_Up = glm::normalize(glm::cross(m_Right, m_Direction));
}