#include "GameAudio.h"

void GameAudio::PlayAudio(size_t ID) {
	toPlayLock.lock();
	toPlay.push_back(ID);
	toPlayLock.unlock();
}

void GameAudio::AudioCode(GameCode::GameData* gameData) {
	while (!gameData->endGame) {
		// This gets the default audio device and generates a context, and then generates the sound buffers
		SoundDevice soundDevice(nullptr);
		std::array<SoundBuffer, Assets::sounds.size()> sounds = {
			SoundBuffer(Assets::sounds[0]),
			SoundBuffer(Assets::sounds[1])
		};

		// This waits for there to be something to play before doing audio calculations
		while (toPlay.size() == 0);

		while (toPlay.size() != 0 || speakers.size() != 0) {
			// This stores the source and then plays one of the buffers based on what's int he array
			for (size_t i = 0; i < toPlay.size(); i++) {
				speakers.push_back(new SoundSource());
				unsigned int buffers[] = { sounds[toPlay[toPlay.size() - 1]].ID };
				speakers[i]->buffersSize = 1;
				speakers[i]->buffers = buffers;
				speakers[i]->QueueBuffers();
				speakers[i]->Play();
				toPlayLock.lock();
				toPlay.erase(toPlay.begin() + toPlay.size() - 1);
				toPlayLock.unlock();
			}

			// This clears up the sources that aren't playing
			for (size_t i = 0; i < speakers.size(); i++) {
				if (speakers[i]->GetState(AL_SOURCE_STATE) != AL_PLAYING) {
					delete speakers[i];
					speakers.erase(speakers.begin() + i);
				}
			}
		}
	}
}