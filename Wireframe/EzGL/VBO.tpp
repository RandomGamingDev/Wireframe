#ifndef VBO_TEMPLATE
#define VBO_TEMPLATE

#ifdef GL_API_GLAD_OPENGL_3

template <typename type>
VBO<type>::VBO(type* vertices, GLsizeiptr size, GLenum howUse) {
	Init(vertices, size, howUse);
}

template <typename type>
VBO<type>::~VBO() {
	Delete();
}

template <typename type>
void VBO<type>::Init(type* vertices, GLsizeiptr size, GLenum howUse) {
	Init(&ID, vertices, size, howUse);
}

template <typename type>
void VBO<type>::Init(GLuint* ID, type* vertices, GLsizeiptr size, GLenum howUse) {
	glGenBuffers(1, ID);
	Bind(*ID);
	Data(vertices, size, howUse);
}

template <typename type>
void VBO<type>::Data(type* vertices, GLsizeiptr size, GLenum howUse) {
	glBufferData(bufferType, size, vertices, howUse);
}

template <typename type>
void VBO<type>::SubData(type* vertices, GLintptr offset, GLsizeiptr size) {
	glBufferSubData(bufferType, offset, size, vertices);
}

template <typename type>
type* VBO<type>::GetSubData(GLintptr offset, GLsizeiptr size) {
	void* vertices = new char[size];
	glGetBufferSubData(GL_UNIFORM_BUFFER, offset, size, vertices);
	return static_cast<type*>(vertices);
}

template <typename type>
type* VBO<type>::Map(GLenum accessType) {
	return static_cast<type*>(glMapBuffer(bufferType, accessType));
}

template <typename type>
type* VBO<type>::MapRange(GLintptr offset, GLsizeiptr size, GLbitfield accessType) {
	return static_cast<type*>(glMapBufferRange(bufferType, offset, size, accessType));
}

template <typename type>
void VBO<type>::Unmap() {
	glUnmapBuffer(bufferType);
}

template <typename type>
void VBO<type>::Bind() {
	Bind(ID);
}

template <typename type>
void VBO<type>::Bind(GLuint ID) {
	glBindBuffer(bufferType, ID);
}

template <typename type>
void VBO<type>::Unbind() {
	glBindBuffer(bufferType, 0);
}

template <typename type>
void VBO<type>::Delete() {
	Delete(&ID);
}

template <typename type>
void VBO<type>::Delete(GLuint* ID) {
	glDeleteBuffers(1, ID);
}

#endif

#endif