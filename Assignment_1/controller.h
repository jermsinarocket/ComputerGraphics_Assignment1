#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "shapes.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "background.h"
#include "soundcontroller.h"
#include "text.h"

using namespace std;
class Controller
{
public:
	/** Default constructor */
	Controller();
	void renderStart();
	void renderBg();
	void button();

	bool gameOver;
	bool gameRunning;

	Background bg;

	float currentScore;
protected:
private:
	SoundController soundcontroller;
	float wait = 0;

};

#endif // CONTROLLER_H