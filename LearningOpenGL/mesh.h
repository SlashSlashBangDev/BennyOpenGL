#pragma once


#include "glm/glm.hpp"
#include "GL/glew.h"
#include "obj_loader.h"


class Vertex {
public:
	Vertex(const glm::vec3& position,const glm::vec2& texCoord, const glm::vec3& normal = glm::vec3(0,0,0) ) {
		this->position = position;
		this->texCoord = texCoord;
		this->normal = normal;
	}

	inline glm::vec3 * getPosition() { return &position; }
	inline glm::vec2 * getTexCoord() { return &texCoord; }
	inline glm::vec3 * getNormal()   { return &normal;   }
private:
	glm::vec3 position;
	glm::vec2 texCoord;
	glm::vec3 normal;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indicies, unsigned int numIndices);
	Mesh(const std::string& fileName);

	void Draw();
	virtual ~Mesh();

private:

	void InitMesh(const IndexedModel& model);

		enum {
		POSITION_VB,
		TEXTCOORD_VB,
		INDEX_VB,
		NORMAL_VB,
		NUM_BUFFERS
	};


	GLuint m_VertexArrayObject;
	GLuint m_VertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawcount;


};

