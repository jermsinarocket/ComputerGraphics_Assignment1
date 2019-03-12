#ifndef BALL_H
#define BALL_H
#include "shapes.h"
#include "colour.h"
#include "text.h"
#include "collision.h"
#include "net.h"
#include "player.h"
#include  "soundcontroller.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

#define PI 3.14159265f
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()

#define BALL_RADIUS 0.10
#define BALL_X 0.0
#define BALL_Y 0.55
#define BALL_xSpeed -0.006
#define BALL_ySpeed -0.005


class Ball
{
public:
	/** Default constructor */
	Ball();

	int render();
	void reverseBallX();
	void reverseBallY();
	void resetAll();

	virtual ~Ball();

	double ballRadius;
	double ballX;
	double ballY;
	double xSpeed;
	double ySpeed;
	int count;

	bool zoom;
	float translateX;
	float translateY;

	Collision ballCollision;


protected:
private:
	SoundController soundcontroller;

};

#endif // Ball_H