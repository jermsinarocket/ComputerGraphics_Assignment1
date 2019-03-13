/**
 * @file soundcontroller.h
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#ifndef SOUNDCONTROLLER_H
#define SOUNDCONTROLLER_H
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <iostream>
#include <mmsystem.h>
#include "resource.h"

using namespace std;
class SoundController
{
public:
	/** Default constructor */
	SoundController();
	void startTheme();
	void clickStart();
	void ballBounce();
	void scoreSound();
	void winSound();
	void playerBallSound();
	~SoundController();
protected:
private:
};

#endif // SOUNDCONTROLLER_H