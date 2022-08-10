#ifndef EBO_TEMPLATE	
#define EBO_TEMPLATE

#ifdef GL_API_GLAD_OPENGL_3

template <typename type>
EBO<type>::EBO(type* indices, GLsizeiptr size, GLenum howUse) {
	Init(indices, size, howUse);
}

template <typename type>
EBO<type>::~EBO() {
	Delete();
}

template <typename type>
void EBO<type>::Init(type* indices, GLsizeiptr size, GLenum howUse) {
	Init(&ID, indices, size, howUse);
}

template <typename type>
void EBO<type>::Init(GLuint* ID, type* indices, GLsizeiptr size, GLenum howUse) {
	glGenBuffers(1, ID);
	Bind(*ID);
	Data(indices, size, howUse);
}

template <typename type>
void EBO<type>::Data(type* indices, GLsizeiptr size, GLenum howUse) {
	glBufferData(bufferType, size, indices, howUse);
}

template <typename type>
void EBO<type>::SubData(type* indices, GLintptr offset, GLsizeiptr size) {
	glBufferSubData(bufferType, offset, size, indices);
}

template <typename type>
type* EBO<type>::GetSubData(GLintptr offset, GLsizeiptr size) {
	void* indices = new char[size];
	glGetBufferSubData(GL_UNIFORM_BUFFER, offset, size, indices);
	return static_cast<type*>(indices);
}

template <typename type>
type* EBO<type>::Map(GLenum accessType) {
	return static_cast<type*>(glMapBuffer(bufferType, accessType));
}

template <typename type>
type* EBO<type>::MapRange(GLintptr offset, GLsizeiptr size, GLbitfield accessType) {
	return static_cast<type*>(glMapBufferRange(bufferType, offset, size, accessType));
}

template <typename type>
void EBO<type>::Unmap() {
	glUnmapBuffer(bufferType);
}

template <typename type>
void EBO<type>::Bind() {
	Bind(ID);
}

template <typename type>
void EBO<type>::Bind(GLuint ID) {
	glBindBuffer(bufferType, ID);
}

template <typename type>
void EBO<type>::Unbind() {
	glBindBuffer(bufferType, 0);
}

template <typename type>
void EBO<type>::Delete() {
	Delete(&ID);
}	

template <typename type>
void EBO<type>::Delete(GLuint* ID) {
	glDeleteBuffers(1, ID);
}

#endif

#endif
