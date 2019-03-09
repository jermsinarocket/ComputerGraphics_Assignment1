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

#define BALL_RADIUS 60
#define BALL_X 720
#define BALL_Y 650
#define BALL_xSpeed -3.5
#define BALL_ySpeed -1


class Ball
{
public:
	/** Default constructor */
	Ball();

	int render();

	virtual ~Ball();

	double ballRadius;
	double ballX;
	double ballY;
	double xSpeed;
	double ySpeed;
	int count;
	Collision ballCollision;


protected:
private:
	SoundController soundcontroller;

};

#endif // Ball_H