#ifndef GAME_AUDIO_HEADER
#define GAME_AUDIO_HEADER

#include <vector>
#include <mutex>

#include <Wireframe.h>

#include "GameCode.h"
#include "Assets.h"

namespace GameAudio {
	inline std::mutex toPlayLock;
	inline std::vector<size_t> toPlay;
	inline std::vector<SoundSource*> speakers;

	void PlayAudio(size_t ID);
	void AudioCode(GameCode::GameData* gameData);
}

#endif