#ifndef TEXTURE2DMULTISAMPLE_HEADER
#define TEXTURE2DMULTISAMPLE_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

class Texture2DMultisample {
public:
	#ifdef GL_API_GLAD_OPENGL_3
	static const GLenum bufferType = GL_TEXTURE_2D_MULTISAMPLE;
	GLuint ID;
	GLint width;
	GLint height;
	#endif

	#ifdef GL_API_GLAD_OPENGL_3
	Texture2DMultisample(GLsizei width, GLsizei height, GLenum slot, GLsizei samples, GLint internalFormat, GLboolean fixedSampleLocations);
	#endif
	~Texture2DMultisample();

	#ifdef GL_API_GLAD_OPENGL_3
	void Init(GLint width, GLsizei height, GLenum slot, GLsizei samples, GLint internalFormat, GLboolean fixedSampleLocations);
	static void Init(GLuint* ID, GLsizei width, GLsizei height, GLenum slot, GLsizei samples, GLint internalFormat, GLboolean fixedSampleLocations, GLsizei* widthVar, GLsizei* heightVar);
	static void TexParameter(GLenum parameter, GLint value);
	void TexUnit(GLuint shader, const char* uniform, GLint unit);
	void Data(GLsizei samples, GLint internalFormat, GLboolean fixedSampleLocations);
	static void Data(GLsizei width, GLsizei height, GLsizei samples, GLint internalFormat, GLboolean fixedSampleLocations);
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