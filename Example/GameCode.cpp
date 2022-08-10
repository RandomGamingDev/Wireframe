#include "GameCode.h"

#include "GameAudio.h"

// This sets a random y velocity based on a randomlyl generated integer, which we then do some calculations on to get 16 possible directions
void GameCode::RandomYVel(GameCode::Ball* ball) {
	const int numVel = 16;
	ball->vel[1] = (rand() % numVel - numVel / 2 + 1) * ballSpeed / numVel;
}

// This set's the position to 0, the x velocity of the ball to a negative or positive value based on the specified side and sets a random y velocity for the ball
void GameCode::ResetBall(GameCode::Ball* ball, bool toRight) {
	for (size_t i = 0; i < ball->pos.size(); i++)
		ball->pos[i] = 0;
	ball->vel[0] = toRight ? ballSpeed : -ballSpeed;
	RandomYVel(ball);
}

void GameCode::GameLogic(GameData* gameData, Graphics* graphics) {
	// Reset the ball and send it to a randomly decided side
	ResetBall(&gameData->ball, rand() % 2);
	float deltaTime = 0.0f;
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	// Clamps the deltaTime to maxDeltaTime
	if (deltaTime > maxDeltaTime)
		deltaTime = maxDeltaTime;

	while (!gameData->endGame) {
		for (size_t i = 0; i < gameData->paddles.size(); i++) {
			// On win/loss this resets the ball and counts the points
			if (i ? gameData->ball.pos[0] < -wallDistance : gameData->ball.pos[0] > wallDistance) {
				gameData->scores[i] += 1;
				ResetBall(&gameData->ball, i);
				GameAudio::PlayAudio(Assets::Sounds::WonRound);
			}

			// On hitting the top or bottom wall this bounces the ball
			if (i ? gameData->ball.pos[1] > wallDistance && !(gameData->ball.vel[1] < 0.0f) :
 				gameData->ball.pos[1] < -wallDistance && gameData->ball.vel[1] < 0.0f
			) {
				gameData->ball.vel[1] = -gameData->ball.vel[1];
				GameAudio::PlayAudio(Assets::Sounds::BallHit);
			}

			// Paddle collision
			if (
				(i ? gameData->ball.pos[0] > paddleDistance : gameData->ball.pos[0] < -paddleDistance) &&
				gameData->ball.pos[1] > gameData->paddles[i].y - paddleLength - ballLength &&
				gameData->ball.pos[1] < gameData->paddles[i].y + paddleLength + ballLength
			) {
				gameData->ball.vel[0] = i ? -ballSpeed : ballSpeed;
				gameData->ball.pos[0] = i ? paddleDistance : -paddleDistance;
				if (i ? (gameData->ball.vel[0] < 0.0f) : (gameData->ball.vel[0] < 0.0f));
					GameAudio::PlayAudio(Assets::Sounds::BallHit);
				RandomYVel(&gameData->ball);
			}

			// Clamping the paddles so that they can't go off the screen
			if (gameData->paddles[i].y > wallDistance)
				gameData->paddles[i].y = wallDistance;
			else if (gameData->paddles[i].y < -wallDistance)
				gameData->paddles[i].y = -wallDistance;
		}

		// This apply's the ball's velocity, multiplying it by deltaTime
		for (size_t i = 0; i < arrsize(gameData->ball.pos); i++)
			gameData->ball.pos[i] += gameData->ball.vel[i] * deltaTime;
		
		// deltaTime calculations
		std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		start = end;
	}
}

std::chrono::steady_clock::time_point inputStart = std::chrono::high_resolution_clock::now();
float inputDeltaTime = 0.0f;

#ifdef WINDOW_API_GLFW
void GameCode::Input(GLFWwindow* window, int key, int scancode, int action, int mods) {
	// Clamps the deltaTime to maxDeltaTime
	if (inputDeltaTime > maxDeltaTime)
		inputDeltaTime = maxDeltaTime;
	Graphics* graphics = Graphics::GetWindowPointer<Graphics>(window);
	GameData* gameData = graphics->GetData<GameData*>();
	const std::array<std::array<int, 2>, 2> paddleControls = {{
		{ GLFW_KEY_S, GLFW_KEY_W },
		{ GLFW_KEY_DOWN, GLFW_KEY_UP }
	}};
	// Gets paddle controls and checks for a press from the buttons listed by paddleControls
	for (size_t i = 0; i < paddleControls.size(); i++)
		for (size_t j = 0; j < paddleControls[0].size(); j++) {
			key = glfwGetKey(window, paddleControls[i][j]);
			if (key == GLFW_PRESS)
				gameData->paddles[i].y += (j ? paddleSpeed : -paddleSpeed) * inputDeltaTime;
		}

	// deltaTime calculations
	std::chrono::steady_clock::time_point inputEnd = std::chrono::high_resolution_clock::now();
	inputDeltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(inputEnd - inputStart).count();
	inputStart = inputEnd;
}
#endif
