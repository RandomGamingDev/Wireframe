#ifndef ASSETS_HEADER
#define ASSETS_HEADER

#include <array>

#include <Wireframe.h>

namespace Assets {
	// Colors
	#define COLOR_WHITE 1.0f, 1.0f, 1.0f, 1.0f

	// Models
	const float paddleSize = 0.03f;
	const float paddleLength = 20.0f;

	const float paddleVerts[] = {
		//						COORDS										COLORS
		 1.0f * paddleSize,  1.0f * paddleLength / 2 * paddleSize, 0.0f,	COLOR_WHITE,
		 1.0f * paddleSize, -1.0f * paddleLength / 2 * paddleSize, 0.0f,	COLOR_WHITE,
		-1.0f * paddleSize,  1.0f * paddleLength / 2 * paddleSize, 0.0f,	COLOR_WHITE,
		-1.0f * paddleSize, -1.0f * paddleLength / 2 * paddleSize, 0.0f,	COLOR_WHITE,
	};

	const unsigned int paddleIndices[] = {
		2, 3, 1,
		2, 1, 0
	};

	const float ballSize = 0.03f;

	const float ballVerts[] = {
		//				COORDS						COLORS
		 1.0f * ballSize,  1.0f * ballSize, 0.0f,	COLOR_WHITE,
		 1.0f * ballSize, -1.0f * ballSize, 0.0f,	COLOR_WHITE,
		-1.0f * ballSize,  1.0f * ballSize, 0.0f,	COLOR_WHITE,
		-1.0f * ballSize, -1.0f * ballSize, 0.0f,	COLOR_WHITE,
	};

	const unsigned int ballIndices[] = {
		2, 3, 1,
		2, 1, 0
	};

	// Sounds

	enum Sounds {
		BallHit,
		WonRound
	};

	inline const std::array<SoundData, 2> sounds = {
		SoundBuffer::GetOggData("./ballHit.ogg"),
		SoundBuffer::GetOggData("./wonRound.ogg")
	};
}

#endif