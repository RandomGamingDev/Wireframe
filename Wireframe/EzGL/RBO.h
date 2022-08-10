#ifndef RBO_HEADER
#define RBO_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

class RBO {
public:
	#ifdef GL_API_GLAD_OPENGL_3
	static const GLenum bufferType = GL_RENDERBUFFER;
	GLuint ID;
	GLsizei width;
	GLsizei height;
	#endif

	#ifdef GL_API_GLAD_OPENGL_3
	RBO(GLenum type, GLsizei width, GLsizei height);
	#endif
	~RBO();

	#ifdef GL_API_GLAD_OPENGL_3
	void Init(GLenum type, GLsizei width, GLsizei height);
	static void Init(GLuint* ID, GLenum type, GLsizei width, GLsizei height, GLsizei* widthVar, GLsizei* heightVar);
	void Data(GLenum type, GLsizei width, GLsizei height);
	static void Data(GLenum type, GLsizei width, GLsizei height, GLsizei* widthVar, GLsizei* heightVar);
	#endif
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

#endif