#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "shapes.h"
#include "ball.h"
#include "ai.h"
#include "collision.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "background.h"
#include "net.h"
#include "soundcontroller.h"
#include "text.h"
#include "player.h"

#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
//Points to win
#define WINNING_POINTS 3


using namespace std;
class Controller
{
public:
	/** Default constructor */
	Controller();
	void renderStart();
	void renderBg();
	void button();
	void clicked(float x, float y);
	bool gameOver;
	bool gameRunning;

	Background bg;

	Player player1;
	Ai ai;
	Ball ball;
	float currentScore;
	bool paused;
	Collision ballCollision;
protected:
private:
	SoundController soundcontroller;

};

#endif // CONTROLLER_H