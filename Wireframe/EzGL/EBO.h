#ifndef EBO_HEADER
#define EBO_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

template <class type>
class EBO {
public:
	#ifdef GL_API_GLAD_OPENGL_3
	static const GLenum bufferType = GL_ELEMENT_ARRAY_BUFFER;
	GLuint ID;
	#endif

	#ifdef GL_API_GLAD_OPENGL_3
	EBO(type* indices, GLsizeiptr size, GLenum howUse);
	#endif
	~EBO();

	#ifdef GL_API_GLAD_OPENGL_3
	void Init(type* indices, GLsizeiptr size, GLenum howUse);
	static void Init(GLuint* ID, type* indices, GLsizeiptr size, GLenum howUse);
	static void Data(type* indices, GLsizeiptr size, GLenum howUse);
	static void SubData(type* indices, GLintptr offset, GLsizeiptr size);
	static type* GetSubData(GLintptr offset, GLsizeiptr size);
	static type* Map(GLenum accessType);
	static type* MapRange(GLintptr offset, GLsizeiptr size, GLbitfield accessType);
	static void Unmap();
	void Bind();
	static void Bind(GLuint ID);
	static void Unbind();
	void Delete();
	static void Delete(GLuint* ID);
	#endif
};

#include "EBO.tpp"

#endif