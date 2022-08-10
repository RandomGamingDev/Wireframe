#ifndef UBO_HEADER
#define UBO_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

class UBO {
public:
	#ifdef GL_API_GLAD_OPENGL_3
	static const GLenum bufferType = GL_UNIFORM_BUFFER;
	GLuint ID;
	#endif

	#ifdef GL_API_GLAD_OPENGL_3
	template <typename type>
	UBO(type* data, GLsizeiptr size, GLenum howUse, const GLchar* name, GLuint shader, GLuint index);
	#endif
	~UBO();

	#ifdef GL_API_GLAD_OPENGL_3	
	template <typename type>
	void Init(type* data, GLsizeiptr size, GLenum howUse, const GLchar* name, GLuint shader, GLuint index);
	template <typename type>
	static void Init(GLuint* ID, type* data, GLsizeiptr size, GLenum howUse, const GLchar* name, GLuint shader, GLuint index);
	template <typename type>
	static void Data(type* data, GLsizeiptr size, GLenum howUse);
	template <typename type>
	static void SubData(type* data, GLintptr offset, GLsizeiptr size);
	template <typename type>
	static type* GetSubData(GLintptr offset, GLsizeiptr size);
	template <typename type>
	static type* Map(GLenum accessType);
	template <typename type>
	static type* MapRange(GLintptr offset, GLsizeiptr size, GLbitfield accessType);
	#endif
	static void Unmap();
	void Bind();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Bind(GLuint ID);
	#endif
	static void Unbind();
	#ifdef GL_API_GLAD_OPENGL_3
	void BindBase(GLuint index);
	static void BindBase(GLuint ID, GLuint index);
	static void UnbindBase(GLuint index);
	void BindRange(GLuint index, GLuint offset, GLsizeiptr size);
	static void BindRange(GLuint ID, GLuint index, GLuint offset, GLsizeiptr size);
	static void UnbindRange(GLuint index, GLuint offset, GLsizeiptr size);
	static GLint GetUniformLocation(GLuint shader, const GLchar * uniform); 
	#endif
	void Delete();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Delete(GLuint* ID);
	#endif
};

#include "UBO.tpp"

#endif