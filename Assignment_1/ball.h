/**
 * @file ball.h
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#ifndef BALL_H
#define BALL_H

#include "shapes.h"
#include "colour.h"
#include "collision.h"
#include "net.h"
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
 //Can be changed to increase/decrease speed
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