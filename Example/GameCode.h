#ifndef GAME_CODE_HEADER
#define GAME_CODE_HEADER

#include <Wireframe.h>

#include <array>
#include <chrono>

#include "Assets.h"

namespace GameCode {
	struct Paddle {
		float y;
		Paddle(float y = 0.0f) {
			this->y = y;
		}
	};

	struct Ball {
		std::array<float, 2> pos;
		std::array<float, 2> vel;
		Ball(std::array<float, 2> pos = std::array<float, 2>(), std::array<float, 2> vel = std::array<float, 2>()) {
			this->pos = pos;
			this->vel = vel;
		}
	};

	struct GameData {
		std::array<Paddle, 2> paddles;
		Ball ball;
		std::array<size_t, 2> scores;
		bool endGame;
		GameData(std::array<Paddle, 2> paddles = std::array<Paddle, 2>(), Ball ball = Ball(), std::array<size_t, 2> scores = std::array<size_t, 2>(), bool endGame = false) {
			this->paddles = paddles;
			this->ball = ball;
			this->endGame = endGame;
			this->scores = scores;
		}
	};

	const float ballSpeed = 0.0000000005f;
	const float ballLength = Assets::ballSize / 2;
	const float paddleSpeed = 0.0000000005f;
	const float paddleLength = Assets::paddleLength / 2 * Assets::paddleSize;
	const float paddleDistance = 0.67f;
	const float wallDistance = 0.8f;
	const float maxDeltaTime = 100000000.0f;

	void GameLogic(GameData* gameData, Graphics* graphics);
	void Input(GLFWwindow* window, int key, int scancode, int action, int mods);
	void RandomYVel(GameCode::Ball* ball);
	void ResetBall(GameCode::Ball* ball, bool toRight);
}

#endif