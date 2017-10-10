#pragma once


#include "glm/glm.hpp"
#include "GL/glew.h"
#include "obj_loader.h"


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
		NUM_BUFFERS
	};


	GLuint m_VertexArrayObject;
	GLuint m_VertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawcount;


};

