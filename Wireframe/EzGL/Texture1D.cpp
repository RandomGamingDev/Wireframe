#include "Texture1D.h"

#ifdef GL_API_GLAD_OPENGL_3

Texture1D::~Texture1D() {
	Delete();
}

void Texture1D::TexParameter(GLenum parameter, GLint value) {
	glTexParameteri(bufferType, parameter, value);
}

void Texture1D::TexUnit(GLuint shader, const char* uniform, GLint unit) {
	glUniform1i(glGetUniformLocation(shader, uniform), unit);
}

void Texture1D::Bind() {
	Bind(ID);
}

void Texture1D::Bind(GLuint ID) {
	glBindTexture(bufferType, ID);
}

void Texture1D::Unbind() {
	glBindTexture(bufferType, 0);
}

void Texture1D::Delete() {
	Delete(&ID);
}

void Texture1D::Delete(GLuint* ID) {
	glDeleteTextures(1, ID);
}

#endif
