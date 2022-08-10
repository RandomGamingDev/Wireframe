#include "Texture2DMultisample.h"

#ifdef GL_API_GLAD_OPENGL_3

Texture2DMultisample::Texture2DMultisample(GLsizei width, GLsizei height, GLenum slot, GLsizei samples, GLint internalFormat, GLboolean fixedSampleLocations) {
	Init(width, height, slot, samples, internalFormat, fixedSampleLocations);
}

Texture2DMultisample::~Texture2DMultisample() {
	Delete();
}

void Texture2DMultisample::Init(GLint width, GLsizei height, GLenum slot, GLsizei samples, GLint internalFormat, GLboolean fixedSampleLocations) {
	Init(&ID, width, height, slot, samples, internalFormat, fixedSampleLocations, &this->width, &this->height);
}

void Texture2DMultisample::Init(GLuint* ID, GLsizei width, GLsizei height, GLenum slot, GLsizei samples, GLint internalFormat, GLboolean fixedSampleLocations, GLsizei* widthVar, GLsizei* heightVar) {
	*widthVar = width;
	*heightVar = height;

	glGenTextures(1, ID);
	glActiveTexture(slot);
	Bind(*ID);
	Data(width, height, samples, internalFormat, fixedSampleLocations);
}

void Texture2DMultisample::Data(GLsizei samples, GLint internalFormat, GLboolean fixedSampleLocations) {
	Data(samples, width, height, internalFormat, fixedSampleLocations);
}

void Texture2DMultisample::Data(GLsizei width, GLsizei height, GLsizei samples, GLint internalFormat, GLboolean fixedSampleLocations) {
	glTexImage2DMultisample(bufferType, samples, internalFormat, width, height, fixedSampleLocations);
}

void Texture2DMultisample::TexParameter(GLenum parameter, GLint value) {
	glTexParameteri(bufferType, parameter, value);
}

void Texture2DMultisample::TexUnit(GLuint shader, const char* uniform, GLint unit) {
	glUniform1i(glGetUniformLocation(shader, uniform), unit);
}

void Texture2DMultisample::Bind() {
	Bind(ID);
}

void Texture2DMultisample::Bind(GLuint ID) {
	glBindTexture(bufferType, ID);
}

void Texture2DMultisample::Unbind() {
	glBindTexture(bufferType, 0);
}

void Texture2DMultisample::Delete() {
	Delete(&ID);
}

void Texture2DMultisample::Delete(GLuint* ID) {
	glDeleteTextures(1, ID);
}

#endif
