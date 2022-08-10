#include "Texture3D.h"

#ifdef GL_API_GLAD_OPENGL_3

Texture3D::~Texture3D() {
	Delete();
}

void Texture3D::TexParameter(GLenum parameter, GLint value) {
	glTexParameteri(bufferType, parameter, value);
}

void Texture3D::TexUnit(GLuint shader, const char* uniform, GLint unit) {
	glUniform1i(glGetUniformLocation(shader, uniform), unit);
}

void Texture3D::Bind() {
	Bind(ID);
}

void Texture3D::Bind(GLuint ID) {
	glBindTexture(bufferType, ID);
}

void Texture3D::Unbind() {
	glBindTexture(bufferType, 0);
}

void Texture3D::Delete() {
	Delete(&ID);
}

void Texture3D::Delete(GLuint* ID) {
	glDeleteTextures(1, ID);
}

#endif
