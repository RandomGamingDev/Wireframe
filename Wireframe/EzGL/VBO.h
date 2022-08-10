#ifndef VBO_HEADER
#define VBO_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

template<class type>
class VBO {
public:
	#ifdef GL_API_GLAD_OPENGL_3
	static const GLenum bufferType = GL_ARRAY_BUFFER;
	GLuint ID;
	#endif
	
	#ifdef GL_API_GLAD_OPENGL_3
	VBO(type* vertices, GLsizeiptr size, GLenum howUse);
	#endif
	~VBO();

	#ifdef GL_API_GLAD_OPENGL_3
	void Init(type* vertices, GLsizeiptr size, GLenum howUse);
	static void Init(GLuint* ID, type* vertices, GLsizeiptr size, GLenum howUse);
	static void Data(type* vertices, GLsizeiptr size, GLenum howUse);
	static void SubData(type* vertices, GLintptr offset, GLsizeiptr size);
	static type* GetSubData(GLintptr offset, GLsizeiptr size);
	static type* Map(GLenum accessType);
	static type* MapRange(GLintptr offset, GLsizeiptr size, GLbitfield accessType);
	#endif
	static void Unmap();
	void Bind();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Bind(GLuint ID);
	#endif
	static void Unbind();
	void Delete();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Delete(GLuint* ID);
	#endif
};

#include "VBO.tpp"

#endif