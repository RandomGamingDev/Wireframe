#include "RBOMultisample.h"

#ifdef GL_API_GLAD_OPENGL_3

RBOMultisample::RBOMultisample(GLenum type, GLsizei width, GLsizei height, GLsizei samples) {
	Init(type, width, height, samples);
}

RBOMultisample::~RBOMultisample() {
	Delete();
}

void RBOMultisample::Init(GLenum type, GLsizei width, GLsizei height, GLsizei samples) {
	Init(&ID, type, width, height, samples, &this->width, &this->height);
}

void RBOMultisample::Init(GLuint* ID, GLenum type, GLsizei width, GLsizei height, GLsizei samples, GLsizei* widthVar, GLsizei* heightVar) {
	glGenRenderbuffers(1, ID);
	Bind(*ID);
	Data(type, width, height, samples, widthVar, heightVar);
}

void RBOMultisample::Data(GLenum type, GLsizei width, GLsizei height, GLsizei samples) {
	Data(type, width, height, samples, &this->width, &this->height);
}

void RBOMultisample::Data(GLenum type, GLsizei width, GLsizei height, GLsizei samples, GLsizei* widthVar, GLsizei* heightVar) {
	*widthVar = width;
	*heightVar = height;
	glRenderbufferStorageMultisample(bufferType, samples, type, width, height);
}

void RBOMultisample::Bind() {
	Bind(ID);
}

void RBOMultisample::Bind(GLuint ID) {
	glBindRenderbuffer(bufferType, ID);
}

void RBOMultisample::Unbind() {
	glBindRenderbuffer(bufferType, 0);
}

void RBOMultisample::Delete() {
	Delete(&ID);
}

void RBOMultisample::Delete(GLuint* ID) {
	glDeleteRenderbuffers(1, ID);
}

#endif
