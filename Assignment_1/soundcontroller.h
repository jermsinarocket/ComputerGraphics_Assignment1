#ifndef SOUNDCONTROLLER_H
#define SOUNDCONTROLLER_H
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include "colour.h"
#include <iostream>
#include <cmath>
#include <mmsystem.h>
#include "resource.h"

using namespace std;
class SoundController
{
public:
	/** Default constructor */
	SoundController();
	void startTheme();
	void background();
	void clickStart();
	bool mute;
protected:
private:
};

#endif // SOUNDCONTROLLER_H