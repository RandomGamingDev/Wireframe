#ifndef PIXY_HEADER
#define PIXY_HEADER

#include <Wireframe.h>
#include <fmt/core.h>
#include <array>

template <typename type>
type Flag(std::string flag, type toReturn) {
	std::cout << flag;
	return toReturn;
}

template <typename type>
class Pixy {
public:
	static const std::array<float, 8> verts;
	static const std::array<unsigned int, 6> indices;
	const std::string vertShader;
	const std::string fragShader;
	std::array<ShaderData, 2> shaders;
	Shader shader;
	VAO vao = VAO();
	VBO<float> vbo = VBO(const_cast<float*>(this->verts.data()), sizeof(this->verts), GL_STATIC_DRAW);
	EBO<unsigned int> ebo = EBO(const_cast<unsigned int*>(this->indices.data()), sizeof(this->indices), GL_STATIC_DRAW);
	UBO ubo;
	size_t tilemapSize;

	Pixy(
		type tilemap,
		unsigned int tilemapSize,
		unsigned int uboIndex,
		int screenWidth,
		int screenHeight,
		int tilemapWidth,
		int tilemapHeight
	) :
		vertShader("\
			#version 330 core\n\
			\
			layout(location = 0) in vec2 aPos;\
			\
			void main() {\
				gl_Position = vec4(aPos, 0.0, 1.0);\
			}\
		"),
		fragShader(fmt::format("\
			#version 330 core\n\
			\
			#define SCREEN_WIDTH {}\n\
			#define SCREEN_HEIGHT {}\n\
			#define TILEMAP_WIDTH {}\n\
			#define TILEMAP_HEIGHT {}\n\
			\
			out vec4 FragColor;\
			\
			layout(packed) uniform tiles {{\
				vec4 tileColors[TILEMAP_WIDTH * TILEMAP_HEIGHT];\
			}};\
			\
			void main() {{\
				FragColor = tileColors[(int(gl_FragCoord.x) / (SCREEN_WIDTH / TILEMAP_WIDTH)) * TILEMAP_WIDTH + int(gl_FragCoord.y) / (SCREEN_HEIGHT / TILEMAP_HEIGHT)];\
			}}"
		, screenWidth, screenHeight, tilemapWidth, tilemapHeight)),
		shaders({
			ShaderData(this->vertShader.c_str(), GL_VERTEX_SHADER, "VERT"),
			ShaderData(this->fragShader.c_str(), GL_FRAGMENT_SHADER, "FRAG")
			}),
		shader(Shader(this->shaders.data(), shaders.size())),
		ubo(UBO(tilemap, tilemapSize, GL_STATIC_DRAW, "tiles", shader.ID, uboIndex))
	{
		this->tilemapSize = tilemapSize;
		this->vao.LinkAttrib<float>(vbo.ID, 0, 2, GL_FLOAT, 2, 0);
		this->ubo.BindBase(uboIndex);
	}

	void Update(type tilemap) {
		this->ubo.SubData(tilemap, 0, tilemapSize);
	}

	void Bind() {
		this->shader.Activate();
		this->vao.Bind();
		this->vbo.Bind();
		this->ebo.Bind();
		this->ubo.Bind();
	}

	void Unbind() {
		this->vao.Unbind();
		this->vbo.Unbind();
		this->ebo.Unbind();
		this->ubo.Unbind();
	}

	void Draw() {
		Graphics::Draw(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT);
	}
};

template <typename type>
const std::array<float, 8> Pixy<type>::verts = {
		 1.0f,  1.0f,
		 1.0f, -1.0f,
		-1.0f,  1.0f,
		-1.0f, -1.0f
};

template <typename type>
const std::array<unsigned int, 6> Pixy<type>::indices = {
		2, 3, 1,
		2, 1, 0
};

#endif
