#include "VAO.h"

#ifdef GL_API_GLAD_OPENGL_3

VAO::VAO() {
	Init();
}

VAO::~VAO() {
	Delete();
}

void VAO::Init() {
	Init(&ID);
}

void VAO::Init(GLuint* ID) {
	glGenVertexArrays(1, ID);
	Bind(*ID);
}

void VAO::Bind() {
	Bind(ID);
}

void VAO::Bind(GLuint ID) {
	glBindVertexArray(ID);
}

void VAO::Unbind() {
	glBindVertexArray(0);
}

void VAO::Delete() {
	Delete(&ID);
}

void VAO::Delete(GLuint* ID) {
	glDeleteVertexArrays(1, ID);
}

#endif
