#ifndef TEXTURE1D_HEADER
#define TEXTURE1D_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

class Texture1D {
public:
#ifdef GL_API_GLAD_OPENGL_3
	static const GLenum bufferType = GL_TEXTURE_1D;
	GLuint ID;
	GLint width;
#endif

#ifdef GL_API_GLAD_OPENGL_3
	template <typename type>
	Texture1D(type* pixels, GLsizei width, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType);
#endif
	~Texture1D();

#ifdef GL_API_GLAD_OPENGL_3
	template <typename type>
	void Init(type* pixels, GLint width, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType);
	template <typename type>
	static void Init(GLuint* ID, type* pixels, GLsizei width, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType, GLsizei* widthVar);
	static void TexParameter(GLenum parameter, GLint value);
	void TexUnit(GLuint shader, const char* uniform, GLint unit);
	template <typename type>
	void Data(GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* pixels);
	template <typename type>
	static void Data(GLsizei width, GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* pixels);
	template <typename type>
	static void SubData(GLint xOffset, GLsizei width, GLint level, GLenum format, GLenum pixelType, type* pixels);
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

#include "Texture1D.tpp"

#endif