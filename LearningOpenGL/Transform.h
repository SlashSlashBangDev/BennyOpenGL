#pragma once

#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

class Transform
{
public:
	Transform(const glm::vec3& position = glm::vec3(), const glm::vec3& rotation = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0, 1.0, 1.0)):
		m_position(position),
 		m_rotation(rotation),
		m_scale(scale) {}
	
	inline glm::mat4 GetModel() const {
		glm::mat4 positionMatrix = glm::translate(m_position);

		glm::mat4 rotationMatrixX = glm::rotate(m_rotation.x, glm::vec3(1, 0, 0));
		glm::mat4 rotationMatrixY = glm::rotate(m_rotation.y, glm::vec3(0, 1, 0));
		glm::mat4 rotationMatrixZ = glm::rotate(m_rotation.z, glm::vec3(0, 0, 1));

		glm::mat4 rotationMatrixF = rotationMatrixZ * rotationMatrixY * rotationMatrixX;

		glm::mat4 scaleMatrix = glm::scale(m_scale);

		return positionMatrix * rotationMatrixF * scaleMatrix;
	}

	inline glm::vec3& GetPosition() { return m_position; }
	inline glm::vec3& GetRotation() { return m_rotation; }
	inline glm::vec3& GetScale() { return m_scale; }

	inline void SetPosition(const glm::vec3& position) { m_position = position; }
	inline void SetRotation(const glm::vec3& rotation) { m_rotation = rotation; }
	inline void SetScale( const glm::vec3& scale) { m_scale = scale; }



private:
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;
};

