#pragma once


#include "glm/glm.hpp"
#include "GL/glew.h"


class Vertex {
public:
	Vertex(const glm::vec3& position) {
		this->position = position;
	}
private:
	glm::vec3 position;
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
		NUM_BUFFERS
	};


	GLuint m_VertexArrayObject;
	GLuint m_VertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawcount;


};

