#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
		   glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
		   float yaw = -90.0f,
		   float pitch = 0.0f);

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix(float aspect, float fov = 45.0f, float nearPlane = 0.1f, float farPlane = 100.0f) const;

	void SetPosition(const glm::vec3& position);
	void SetDirection(float yaw, float pitch);
	void SetUp(const glm::vec3& up);

	glm::vec3 GetPosition() const;
	glm::vec3 GetDirection() const;
	glm::vec3 GetUp() const;
	glm::vec3 GetRight() const;

private:
	void UpdateDirection();

	glm::vec3 m_Position;
	glm::vec3 m_Up;
	glm::vec3 m_Direction;
	glm::vec3 m_Right;
	
	float m_Yaw;
	float m_Pitch;
};

#endif