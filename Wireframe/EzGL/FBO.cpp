#include "FBO.h"

#ifdef GL_API_GLAD_OPENGL_3

FBO::FBO() {
	Init();
}

FBO::~FBO() {
	Delete();
}

void FBO::Init() {
	Init(&ID);
}

#ifdef GL_API_GLAD_OPENGL_3

void FBO::Init(GLuint* ID) {
	glGenFramebuffers(1, ID);
	Bind(*ID);
}

#endif

void FBO::Bind() {
	Bind(ID);
} 

void FBO::Bind(GLuint ID) {
	glBindFramebuffer(bufferType, ID);
}

void FBO::Unbind() {
	glBindFramebuffer(bufferType, 0);
}

void FBO::BindRead() {
	BindRead(ID);
}

void FBO::BindRead(GLuint ID) {
	glBindFramebuffer(GL_READ_FRAMEBUFFER, ID);
}

void FBO::UnbindRead() {
	glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
}

void FBO::BindDraw() {
	BindDraw(ID);
}

void FBO::BindDraw(GLuint ID) {
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, ID); 
}

void FBO::UnbindDraw() {
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
}

void FBO::LinkTexture2D(GLuint texture, GLenum texType, GLenum attachment) {
	glFramebufferTexture2D(bufferType, attachment, texType, texture, 0);
}

void FBO::LinkRBO(GLuint RBO, GLenum attachment) {
	glFramebufferRenderbuffer(bufferType, attachment, GL_RENDERBUFFER, RBO);
}

void FBO::Blit(GLint srcBottomLeftX,
	GLint srcBottomLeftY,
	GLint srcTopRightX,
	GLint srcTopRightY,
	GLint dstBottomLeftX,
	GLint dstBottomLeftY,
	GLint dstTopRightX,
	GLint dstTopRightY,
	GLbitfield mask,
	GLenum filter
) {
	glBlitFramebuffer(srcBottomLeftX, srcBottomLeftY, srcTopRightX, srcTopRightY, dstBottomLeftX, dstBottomLeftY, dstTopRightX, dstTopRightY, mask, filter);
}

void FBO::Delete() {
	Delete(&ID);
}

void FBO::Delete(GLuint* ID) {
	glDeleteFramebuffers(1, ID);
}

#endif
