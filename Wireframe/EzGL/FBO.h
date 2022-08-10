#ifndef FBO_HEADER
#define FBO_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

class FBO {
public:
	#ifdef GL_API_GLAD_OPENGL_3
	static const GLenum bufferType = GL_FRAMEBUFFER;
	GLuint ID;
	#endif
	
	FBO();
	~FBO();

	void Init();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Init(GLuint* ID);
	#endif
	void Bind();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Bind(GLuint ID);
	#endif
	static void Unbind();
	void BindRead();
	#ifdef GL_API_GLAD_OPENGL_3
	static void BindRead(GLuint ID);
	#endif
	static void UnbindRead();
	void BindDraw();
	#ifdef GL_API_GLAD_OPENGL_3
	static void BindDraw(GLuint ID);
	#endif
	static void UnbindDraw();
	#ifdef GL_API_GLAD_OPENGL_3
	static void LinkTexture2D(GLuint texture, GLenum texType, GLenum attachment);
	static void LinkRBO(GLuint RBO, GLenum attachment);
	static void Blit(GLint srcBottomLeftX,
		GLint srcBottomLeftY,
		GLint srcTopRightX,
		GLint srcTopRightY,
		GLint dstBottomLeftX,
		GLint dstBottomLeftY,
		GLint dstTopRightX,
		GLint dstTopRightY,
		GLbitfield mask,
		GLenum filter
	);
	#endif
	void Delete();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Delete(GLuint* ID);
	#endif
};

#endif