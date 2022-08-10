#ifndef VAO_HEADER
#define VAO_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

class VAO {
public:
	#ifdef GL_API_GLAD_OPENGL_3
	GLuint ID;
	#endif

	VAO();
	~VAO();

	void Init();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Init(GLuint* ID);
	#endif
	void Bind();
	#ifdef GL_API_GLAD_OPENGL_3	
	static void Bind(GLuint ID);
	#endif
	static void Unbind();
	void Delete();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Delete(GLuint* ID);
	template <typename type>
	static void LinkAttrib(GLuint VBO, GLuint layout, GLuint numComponents, GLenum varType, GLsizeiptr stride, GLsizeiptr offset);
	#endif
};

#include "VAO.tpp"

#endif