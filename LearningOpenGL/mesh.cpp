#include "Mesh.h"
#include <vector>



Mesh::Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indicies, unsigned int numIndices)
{


	IndexedModel model;

	for (unsigned int i = 0; i < numVertices; i++) {
		model.positions.push_back(*vertices[i].getPosition());
		model.texCoords.push_back(*vertices[i].getTexCoord());
	}

	for (unsigned int i = 0; i < numIndices; i++)
	{
		model.indices.push_back( indicies[i]);	 
	}

	InitMesh(model);
	
}

Mesh::Mesh(const std::string & fileName)
{
	IndexedModel model = OBJModel(fileName).ToIndexedModel();
	InitMesh(model);
}


void Mesh::Draw()
{
	glBindVertexArray(m_VertexArrayObject);
	glDrawElements(GL_TRIANGLES, m_drawcount, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_VertexArrayObject);
}

void Mesh::InitMesh(const IndexedModel & model)
{
	m_drawcount = model.indices.size();
	glGenVertexArrays(1, &m_VertexArrayObject);
	glBindVertexArray(m_VertexArrayObject);


	glGenBuffers(NUM_BUFFERS, m_VertexArrayBuffers);

	glBindBuffer(GL_ARRAY_BUFFER, m_VertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size()  * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);


	glBindBuffer(GL_ARRAY_BUFFER, m_VertexArrayBuffers[TEXTCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.texCoords.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_VertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW);


	glBindVertexArray(0);


}
