#include "RBO.h"

#ifdef GL_API_GLAD_OPENGL_3

RBO::RBO(GLenum type, GLsizei width, GLsizei height) {
	Init(type, width, height);
}

RBO::~RBO() {
	Delete();
}

void RBO::Init(GLenum type, GLsizei width, GLsizei height) {
	Init(&ID, type, width, height, &this->width, &this->height);
}

void RBO::Init(GLuint* ID, GLenum type, GLsizei width, GLsizei height, GLsizei* widthVar, GLsizei* heightVar) {
	glGenRenderbuffers(1, ID);
	Bind(*ID);
	Data(type, width, height, widthVar, heightVar);
}

void RBO::Data(GLenum type, GLsizei width, GLsizei height) {
	Data(type, width, height, &this->width, &this->height);
}

void RBO::Data(GLenum type, GLsizei width, GLsizei height, GLsizei* widthVar, GLsizei* heightVar) {
	*widthVar = width;
	*heightVar = height;
	glRenderbufferStorage(bufferType, type, width, height);
}

void RBO::Bind() {
	Bind(ID);
}

void RBO::Bind(GLuint ID) {
	glBindRenderbuffer(bufferType, ID);
}

void RBO::Unbind() {
	glBindRenderbuffer(bufferType, 0);
}

void RBO::Delete() {
	Delete(&ID);
}

void RBO::Delete(GLuint* ID) {
	glDeleteRenderbuffers(1, ID);
}

#endif
