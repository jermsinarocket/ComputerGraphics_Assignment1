#include "soundcontroller.h"
#pragma comment( lib, "winmm" )


SoundController::SoundController()
{
}

void SoundController::startTheme() {

		PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC);
}


void SoundController::clickStart() {

		PlaySound(MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);

}

void SoundController::ballBounce() {

		PlaySound(MAKEINTRESOURCE(IDR_WAVE3), NULL, SND_RESOURCE | SND_ASYNC);

}

void SoundController::scoreSound() {

		PlaySound(MAKEINTRESOURCE(IDR_WAVE4), NULL, SND_RESOURCE | SND_ASYNC);

}

void SoundController::winSound() {

		PlaySound(MAKEINTRESOURCE(IDR_WAVE5), NULL, SND_RESOURCE | SND_ASYNC);

}

void SoundController::playerBallSound() {
	PlaySound(MAKEINTRESOURCE(IDR_WAVE6), NULL, SND_RESOURCE | SND_ASYNC);
}

SoundController::~SoundController() {

}