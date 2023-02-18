#ifndef PIXELATOR_HEADER
#define PIXELATOR_HEADER

// The goal for this library is to pixelate stuff

#include <iostream>

#include <Wireframe.h>
#include <fmt/core.h>
#include <array>

class Pixelator {
public:
	inline static const std::array<float, 16> verts = {
		 1.0f, -1.0f, 1.0f, 0.0f,
		 1.0f,  1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 0.0f, 0.0f,
		-1.0f,  1.0f, 0.0f, 1.0f 
	};
	inline static const std::array<unsigned int, 6> indices = {
		1, 3, 2,
		0, 1, 2
	};
	const std::string vertShader;
	const std::string fragShader;
	std::array<ShaderData, 2> shaders;
	Shader shader;
	VAO vao = VAO();
	VBO<float> vbo = VBO(const_cast<float*>(this->verts.data()), sizeof(this->verts), GL_STATIC_DRAW);
	EBO<unsigned int> ebo = EBO(const_cast<unsigned int*>(this->indices.data()), sizeof(this->indices), GL_STATIC_DRAW);
	FBO fbo = FBO();
	Texture2D texture;
	RBO rbo;
	unsigned int xRes;
	unsigned int yRes;

	Pixelator(unsigned int xRes, unsigned int yRes, GLenum texUnit) :
		vertShader("\
			#version 330 core\n\
			\n\
			layout(location = 0) in vec2 pos;\n\
			layout(location = 1) in vec2 tex;\n\
			\n\
			out vec2 texCoord;\n\
			\n\
			void main() {\n\
				gl_Position = vec4(pos, 0.0, 1.0);\n\
				texCoord = tex;\n\
			}\n\
		"),
		fragShader("\
			#version 330 core\n\
			\n\
			out vec4 FragColor;\n\
			\n\
			in vec2 texCoord;\n\
			\n\
			uniform sampler2D screenTexture;\n\
			\n\
			void main() {\n\
				FragColor = texture(screenTexture, texCoord);\n\
			}\n\
		"),
		shaders({
			ShaderData(this->vertShader.c_str(), GL_VERTEX_SHADER, "VERT"),
			ShaderData(this->fragShader.c_str(), GL_FRAGMENT_SHADER, "FRAG")
		}),
		shader(Shader(this->shaders.data(), this->shaders.size())),
		texture(Texture2D(static_cast<char*>(nullptr), xRes, yRes, texUnit, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE)),
		rbo(RBO(GL_DEPTH24_STENCIL8, xRes, yRes))
	{
		this->vao.LinkAttrib<float>(this->vbo.ID, 0, 2, GL_FLOAT, 4, 0);
		this->vao.LinkAttrib<float>(this->vbo.ID, 1, 2, GL_FLOAT, 4, 2);
        Graphics::Viewport(0, 0, xRes, yRes);
		this->texture.Bind();
		this->texture.TexParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		this->texture.TexParameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		this->texture.TexParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		this->texture.TexParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		this->texture.TexUnit(this->shader.ID, "screenTexture", 0);
		this->fbo.LinkTexture2D(this->texture.ID, GL_TEXTURE_2D, GL_COLOR_ATTACHMENT0);
		this->fbo.LinkRBO(this->rbo.ID, GL_DEPTH_STENCIL_ATTACHMENT);

		this->xRes = xRes;
		this->yRes = yRes;
	}

	void SetViewport() {
		Graphics::Viewport(0, 0, this->xRes, this->yRes);
	}

	void Bind() {
		this->shader.Activate();
		this->vao.Bind();
		this->vbo.Bind();
		this->ebo.Bind();
		this->fbo.Bind();
		this->SetViewport();
		this->texture.Bind();
		this->texture.TexUnit(shader.ID, "tex0", 0);
		this->rbo.Bind();
	}

	void Unbind(unsigned int xRes, unsigned int yRes) {
		this->vao.Unbind();
		this->vbo.Unbind();
		this->ebo.Unbind();
		this->fbo.Unbind();
        Graphics::Viewport(0, 0, xRes, yRes);
		this->texture.Unbind();
		this->rbo.Unbind();
	}

	void Draw() {
		Graphics::Draw(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT);
	}
};

#endif