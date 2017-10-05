#pragma once


#include "glm/glm.hpp"
#include "GL/glew.h"


class Vertex {
public:
	Vertex(const glm::vec3& position,const glm::vec2& texCoord) {
		this->position = position;
		this->texCoord = texCoord;
	}

	inline glm::vec3 * getPosition() { return &position; }
	inline glm::vec2 * getTexCoord() { return &texCoord; }
private:
	glm::vec3 position;
	glm::vec2 texCoord;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);

	void Draw();
	virtual ~Mesh();

private:

	enum {
		POSITION_VB,
		TEXTCOORD_VB,
		NUM_BUFFERS
	};


	GLuint m_VertexArrayObject;
	GLuint m_VertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawcount;


};

