#include "soundcontroller.h"


SoundController::SoundController()
{
	mute = false;
}

void SoundController::startTheme() {
	if (!mute)
		PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
}


void SoundController::clickStart() {
	if (!mute)
		PlaySound("clicStart.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void SoundController::background() {

}