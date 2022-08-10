#ifndef RBOMULTISAMPLE_HEADER
#define RBOMULTISAMPLE_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

class RBOMultisample {
public:
	#ifdef GL_API_GLAD_OPENGL_3
	static const GLenum bufferType = GL_RENDERBUFFER;
	GLuint ID;
	GLsizei width;
	GLsizei height;
	#endif

	#ifdef GL_API_GLAD_OPENGL_3
	RBOMultisample(GLenum type, GLsizei width, GLsizei height, GLsizei samples);
	#endif
	~RBOMultisample();

	#ifdef GL_API_GLAD_OPENGL_3
	void Init(GLenum type, GLsizei width, GLsizei height, GLsizei samples);
	static void Init(GLuint* ID, GLenum type, GLsizei width, GLsizei height, GLsizei samples, GLsizei* widthVar, GLsizei* heightVar);
	void Data(GLenum type, GLsizei width, GLsizei height, GLsizei samples);
	static void Data(GLenum type, GLsizei width, GLsizei height, GLsizei samples, GLsizei* widthVar, GLsizei* heightVar);
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