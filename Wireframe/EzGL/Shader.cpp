#include "Shader.h"

#ifdef GL_API_GLAD_OPENGL_3

Shader::Shader(ShaderData shaders[], unsigned int numberOfShaders) {
	ID = glCreateProgram();
	for (unsigned int i = 0; i < numberOfShaders; i++) {
		GLuint shader = glCreateShader(shaders[i].type);
		glShaderSource(shader, 1, &shaders[i].shader, NULL);
		glCompileShader(shader);
		CompileErrors(shader, shaders[i].name);
		glAttachShader(ID, shader);
		glDeleteShader(shader);
	}
	glLinkProgram(ID);
	LinkErrors();
	Activate();
}

Shader::~Shader() {
	Delete();
}

void Shader::Activate() {
	Activate(ID);
}

void Shader::Activate(GLuint ID) {
	glUseProgram(ID);
}

void Shader::Delete() {
	Delete(ID);
}

void Shader::Delete(GLuint ID) {
	glDeleteProgram(ID);
}

const char* Shader::GetShaderData(const char* filename) {
	std::ifstream in(filename, std::ios::binary);
	if (!in)
		std::cout << "ERROR: There was an error getting the files contents of " << filename;
	std::string contents;
	in.seekg(0, std::ios::end);
	contents.resize(in.tellg());
	in.seekg(0, std::ios::beg);
	in.read(&contents[0], contents.size());
	const GLchar* buffer = new char[contents.length() + 1];
	memcpy((void*)buffer, contents.c_str(), contents.length() + 1);
	return buffer;
}

void Shader::CompileErrors(unsigned int shader, const char* type) {
	GLint hasCompiled;
	GLchar infoLog[logSize];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
	if (hasCompiled == GL_TRUE) return;
	glGetShaderInfoLog(shader, logSize, NULL, infoLog);
	std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << '\n';
}

void Shader::LinkErrors() {
	LinkErrors(ID);
}

void Shader::LinkErrors(GLuint ID) {
	GLint hasCompiled;
	GLchar infoLog[logSize];

	glGetProgramiv(ID, GL_LINK_STATUS, &hasCompiled);
	if (hasCompiled == GL_TRUE) return;
	glGetProgramInfoLog(ID, logSize, NULL, infoLog);
	std::cout << "SHADER_LINKING_ERROR for: PROGRAM" << "\n" << infoLog << '\n';
}

#endif