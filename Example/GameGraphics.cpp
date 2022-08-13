#include "GameGraphics.h"

#include <glm/gtx/vector_angle.hpp>

#include "Assets.h"
#include "GameCode.h"

// Set the width and height to the correct value
void OnResize(Window* window, int width, int height) {
	if (width == 0 || height == 0) return;
	Graphics::Viewport(0, 0, width, height);
	Graphics* graphics = Graphics::GetWindowPointer<Graphics>(window);
	graphics->width = width;
	graphics->height = height;
}

bool firstClick = true;
float speed = 0.1f, sensitivity = 100.0f;

const char* paddleVertexShader = Shader::GetShaderData("paddle.vert");
const char* ballVertexShader = Shader::GetShaderData("ball.vert");
const char* noTexFragShader = Shader::GetShaderData("noTex.frag");

void GameGraphics::GraphicsCode(Graphics* graphics) {
	GameCode::GameData* gameData = graphics->GetData<GameCode::GameData*>();

	graphics->camera.Resize(graphics->width, graphics->height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Shaders, models, and uniform for the paddles

	ShaderData paddlesShaders[] = {
		ShaderData(paddleVertexShader, GL_VERTEX_SHADER, "VERT"),
		ShaderData(noTexFragShader, GL_FRAGMENT_SHADER, "FRAG")
	};
	Shader paddlesShader(paddlesShaders, arrsize(paddlesShaders));
	paddlesShader.Activate();
	graphics->camera.Matrix(45.0f, 0.1f, 100.0f, paddlesShader.ID, "camMatrix");

	VAO paddlesVAO;
	VBO<const float> paddlesVBO = VBO(Assets::paddleVerts, sizeof(Assets::paddleVerts), GL_STATIC_DRAW);
	EBO<const unsigned int> paddlesEBO = EBO(Assets::paddleIndices, sizeof(Assets::paddleIndices), GL_STATIC_DRAW);
	paddlesVAO.LinkAttrib<const float>(paddlesVBO.ID, 0, 3, GL_FLOAT, 7, 0);
	paddlesVAO.LinkAttrib<const float>(paddlesVBO.ID, 1, 4, GL_FLOAT, 7, 3);

	int paddlesUniformLocation = 0;
	UBO paddlesUniform = UBO(&gameData->paddles, sizeof(gameData->paddles), GL_DYNAMIC_DRAW, "paddles", paddlesShader.ID, paddlesUniformLocation);
	paddlesUniform.BindBase(paddlesUniformLocation);

	// Shaders, models, and uniform for the ball

	ShaderData ballShaders[] = {
		ShaderData(ballVertexShader, GL_VERTEX_SHADER, "VERT"),
		ShaderData(noTexFragShader, GL_FRAGMENT_SHADER, "FRAG")
	};
	Shader ballShader(ballShaders, arrsize(ballShaders));
	ballShader.Activate();
	graphics->camera.Matrix(45.0f, 0.1f, 100.0f, ballShader.ID, "camMatrix");

	VAO ballVAO = VAO();
	VBO<const float> ballVBO = VBO(Assets::ballVerts, sizeof(Assets::ballVerts), GL_STATIC_DRAW);
	EBO<const unsigned int> ballEBO = EBO(Assets::ballIndices, sizeof(Assets::ballIndices), GL_STATIC_DRAW);
	ballVAO.LinkAttrib<const float>(ballVBO.ID, 0, 3, GL_FLOAT, 7, 0);	
	ballVAO.LinkAttrib<const float>(ballVBO.ID, 1, 4, GL_FLOAT, 7, 3);

	int ballUniformLocation = 1;
	UBO ballUniform = UBO(&gameData->ball, sizeof(gameData->ball), GL_DYNAMIC_DRAW, "ball", ballShader.ID, ballUniformLocation);
	ballUniform.BindBase(ballUniformLocation);

	Graphics::Enable(GL_CULL_FACE);

	while (!graphics->WindowShouldClose()) {
		// Setting the title to Pong and the score
		graphics->SetTitle(
			(
				std::string("Pong ") +
				std::to_string(gameData->scores[0]) +
				std::string(" : ") + 
				std::to_string(gameData->scores[1])
			).c_str()
		);
		graphics->ClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		graphics->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		paddlesVAO.Bind();
		paddlesUniform.Bind();
		// Update the paddle uniform's data
		paddlesUniform.SubData(&gameData->paddles, 0, sizeof(gameData->paddles));
		paddlesShader.Activate();
		graphics->DrawInstanced(GL_TRIANGLES, arrsize(Assets::paddleIndices), GL_UNSIGNED_INT, 2);

		ballVAO.Bind();
		ballUniform.Bind();
		// Update the ball uniform's data
		ballUniform.SubData(&gameData->ball, 0, sizeof(gameData->ball));
		ballShader.Activate();
		graphics->Draw(GL_TRIANGLES, arrsize(Assets::ballIndices), GL_UNSIGNED_INT);

		graphics->PollEvents();
		graphics->OnResizeEvent(OnResize);
		graphics->SwapBuffers();
		// Inputs
		#ifdef WINDOW_API_GLFW
		glfwSetKeyCallback(graphics->window, GameCode::Input);
		#endif
	}
	gameData->endGame = true;
}