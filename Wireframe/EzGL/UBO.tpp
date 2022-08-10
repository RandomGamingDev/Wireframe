#ifndef UBO_TEMPLATE
#define UBO_TEMPLATE

#ifdef GL_API_GLAD_OPENGL_3

template <typename type>
UBO::UBO(type* data, GLsizeiptr size, GLenum howUse, const GLchar* name, GLuint shader, GLuint index) {
	Init<type>(data, size, howUse, name, shader, index);
}

template <typename type>
void UBO::Init(type* data, GLsizeiptr size, GLenum howUse, const GLchar* name, GLuint shader, GLuint index) {
	Init<type>(&ID, data, size, howUse, name, shader, index);
}

template <typename type>
void UBO::Init(GLuint* ID, type* data, GLsizeiptr size, GLenum howUse, const GLchar* name, GLuint shader, GLuint index) {
	GLuint uniform = glGetUniformBlockIndex(shader, name);
	glUniformBlockBinding(shader, uniform, index);
	glGenBuffers(1, ID);
	Bind(*ID);
	Data<type>(data, size, howUse);
}

template <typename type>
void UBO::Data(type* data, GLsizeiptr size, GLenum howUse) {
	glBufferData(bufferType, size, data, howUse);
}

template <typename type>
void UBO::SubData(type* data, GLintptr offset, GLsizeiptr size) {
	glBufferSubData(bufferType, offset, size, data);
}

template <typename type>
type* UBO::GetSubData(GLintptr offset, GLsizeiptr size) {
	void* data = new char[size];
	glGetBufferSubData(bufferType, offset, size, data);
	return static_cast<type*>(data);
}

template <typename type>
type* UBO::Map(GLenum accessType) {
	return static_cast<type*>(glMapBuffer(bufferType, accessType));
}

template <typename type>
type* UBO::MapRange(GLintptr offset, GLsizeiptr size, GLbitfield accessType) {
	return static_cast<type*>(glMapBufferRange(bufferType, offset, size, accessType));
}

#endif

#endif
