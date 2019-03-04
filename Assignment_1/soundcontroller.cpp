#include "soundcontroller.h"
#pragma comment( lib, "winmm" )


SoundController::SoundController()
{
}

void SoundController::startTheme() {

		PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
}


void SoundController::clickStart() {
		PlaySound(MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
}
