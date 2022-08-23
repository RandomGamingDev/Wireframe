#ifndef PIXY_HEADER
#define PIXY_HEADER

#include <Wireframe.h>
#include <fmt/core.h>
#include <array>

template <typename type>
class Pixy {
public:
	static const std::array<float, 8> PixyVerts;
	static const std::array<unsigned int, 6> PixyIndices;
	Shader* shader;
	VAO* vao = new VAO();
	VBO<float>* vbo = new VBO(const_cast<float*>(PixyVerts.data()), sizeof(PixyVerts), GL_STATIC_DRAW);
	EBO<unsigned int>* ebo = new EBO(const_cast<unsigned int*>(PixyIndices.data()), sizeof(PixyIndices), GL_STATIC_DRAW);
	UBO* ubo;
	size_t tilemapSize;

	Pixy(
		type tilemap,
		size_t tilemapSize,
		unsigned int uboIndex,
		int screenWidth,
		int screenHeight,
		int tilemapWidth,
		int tilemapHeight
	) {
		this->tilemapSize = tilemapSize;

		vao->LinkAttrib<float>(vbo->ID, 0, 2, GL_FLOAT, 2, 0);

		std::string vertShader = { "\
			#version 330 core\n\
			\
			layout(location = 0) in vec2 aPos;\
			\
			void main() {\
				gl_Position = vec4(aPos, 0.0, 1.0);\
			}\
		" };
		std::string fragShader = { fmt::format(fmt::runtime("\
			#version 330 core\n\
			#extension ARB_arrays_of_arrays : require\n\
			\
			#define SCREEN_WIDTH {}\n\
			#define SCREEN_HEIGHT {}\n\
			#define TILEMAP_WIDTH {}\n\
			#define TILEMAP_HEIGHT {}\n\
			\
			out vec4 FragColor;\
			\
			layout(packed) uniform tiles {{\
				vec4 tileColors[TILEMAP_WIDTH][TILEMAP_HEIGHT];\
			}};\
			\
			void main() {{\
				FragColor = tileColors[int(gl_FragCoord.x) / (SCREEN_WIDTH / TILEMAP_WIDTH)][int(gl_FragCoord.y) / (SCREEN_HEIGHT / TILEMAP_HEIGHT)];\
			}}"),
			screenWidth, screenHeight, tilemapWidth, tilemapHeight) };
		ShaderData shaders[] = {
			ShaderData(vertShader.c_str(), GL_VERTEX_SHADER, "VERT"),
			ShaderData(fragShader.c_str(), GL_FRAGMENT_SHADER, "FRAG")
		};
		this->shader = new Shader(shaders, arrsize(shaders));

		this->ubo = new UBO(tilemap, tilemapSize, GL_STATIC_DRAW, "tiles", shader->ID, uboIndex);
		this->ubo->BindBase(uboIndex);
	}

	~Pixy() {
		delete shader;
		delete vao;
		delete vbo;
		delete ebo;
		delete ubo;
	}

	void Update(type tilemap) {
		ubo->SubData(tilemap, 0, tilemapSize);
	}

	void Draw() {
		shader->Activate();
		vao->Bind();
		vbo->Bind();
		ebo->Bind();
		ubo->Bind();
		Graphics::Draw(GL_TRIANGLES, arrsize(PixyIndices), GL_UNSIGNED_INT);
	}
};

template <typename type>
const std::array<float, 8> Pixy<type>::PixyVerts = {
		 1.0f,  1.0f,
		 1.0f, -1.0f,
		-1.0f,  1.0f,
		-1.0f, -1.0f
};

template <typename type>
const std::array<unsigned int, 6> Pixy<type>::PixyIndices = {
		2, 3, 1,
		2, 1, 0
};

#endif