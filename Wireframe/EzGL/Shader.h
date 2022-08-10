#ifndef SHADER_HEADER
#define SHADER_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include<glad/glad.h>
#endif

#include<fstream>
#include<iostream>

struct ShaderData {
	#ifdef GL_API_GLAD_OPENGL_3
	const GLchar* shader;
	GLuint type;
	#endif
	const char* name;
	#ifdef GL_API_GLAD_OPENGL_3	
	ShaderData(const GLchar* shader, GLuint type, const char* name) {
		this->shader = shader;
		this->type = type;
		this->name = name;
	}
	#endif
};

class Shader {
public:
	static const unsigned int logSize = 1024;
	#ifdef GL_API_GLAD_OPENGL_3
	GLuint ID;
	#endif

	Shader(ShaderData shaders[], unsigned int numberOfShaders);
	~Shader();

	void Activate();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Activate(GLuint ID);
	#endif
	void Delete();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Delete(GLuint ID);
	#endif
	static const char* GetShaderData(const char* filename);
	static void CompileErrors(unsigned int shader, const char* type);
	void LinkErrors();
	#ifdef GL_API_GLAD_OPENGL_3
	static void LinkErrors(GLuint ID);
	#endif
};

#endif