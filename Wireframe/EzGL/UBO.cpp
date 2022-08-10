#include "UBO.h"

#ifdef GL_API_GLAD_OPENGL_3

UBO::~UBO() {
	Delete();
}

void UBO::Unmap() {
	glUnmapBuffer(bufferType);
}

void UBO::Bind() {
	Bind(ID);
}

void UBO::Bind(GLuint ID) {
	glBindBuffer(bufferType, ID);
}

void UBO::Unbind() {
	glBindBuffer(bufferType, 0);
}

void UBO::BindBase(GLuint index) {
	BindBase(ID, index);
}

void UBO::BindBase(GLuint ID, GLuint index) {
	glBindBufferBase(bufferType, index, ID);
}

void UBO::UnbindBase(GLuint index) {
	glBindBufferBase(bufferType, index, 0);
}


void UBO::BindRange(GLuint index, GLuint offset, GLsizeiptr size) {
	BindRange(ID, index, offset, size);
}

void UBO::BindRange(GLuint ID, GLuint index, GLuint offset, GLsizeiptr size) {
	glBindBufferRange(bufferType, index, ID, offset, size);
}

void UBO::UnbindRange(GLuint index, GLuint offset, GLsizeiptr size) {
	glBindBufferRange(bufferType, index, 0, offset, size);
}

GLint UBO::GetUniformLocation(GLuint shader, const GLchar* uniform) {
	return glGetUniformBlockIndex(shader, uniform);
}

void UBO::Delete() {
	Delete(&ID);
}

void UBO::Delete(GLuint* ID) {
	glDeleteBuffers(1, ID);
}

#endif
