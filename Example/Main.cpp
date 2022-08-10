#include <iostream>
#include <thread>
#include <stdio.h>
#include <ctime>

#include <Wireframe.h>

#include "GameCode.h"
#include "GameGraphics.h"
#include "GameAudio.h"

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	Graphics::WindowLibInit();
	Graphics::WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	Graphics::WindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	Graphics::WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GameCode::GameData gameData = GameCode::GameData();
	Graphics graphics;
	std::thread graphicsThread(&Graphics::Init, &graphics, "Pong", 800, 800, nullptr, GameGraphics::GraphicsCode, &gameData);
	std::thread audioThread(&GameAudio::AudioCode, &gameData);
	std::thread logicThread(&GameCode::GameLogic, &gameData, &graphics);
	graphicsThread.join();
	audioThread.join();
	logicThread.join();
	return 0;
}
