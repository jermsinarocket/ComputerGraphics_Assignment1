/**
 * @file ball.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#include "ball.h"

Ball::Ball() {
	ballRadius = BALL_RADIUS;
	ballX = BALL_X;
	ballY = BALL_Y;
	xSpeed = BALL_xSpeed;
	ySpeed = BALL_ySpeed;
	count = 0;
	zoom = false;
	translateX = 0.0f;
	translateY = 0.0f;
}

int Ball::render() {

	Color ballColor;
	ballColor.setColor("398ec6");
	Shapes::circle(ballX, ballY, ballRadius, ballColor); 
	ballColor.setColor("ffffff");

	/*
	glColor3f(SETCOLOR(ballColor));
		glBegin(GL_LINE_LOOP);
		glVertex2f(ballX - 0.2, ballY - 0.2);
		glVertex2f(ballX + 0.2, ballY - 0.2);
		glVertex2f(ballX + 0.2, ballY + 0.2);
		glVertex2f(ballX - 0.2, ballY + 0.2);
	glEnd();*/

	//Ball moves constantly at x,y speed
	ballX += xSpeed;
	ballY += ySpeed;
	
	if(zoom) {

		glTranslatef(-xSpeed, -ySpeed, 0.0f);

		translateX += -xSpeed;
		translateY += -ySpeed;

	}
	else {

		glTranslatef(-translateX, -translateY, 0.0f);

		translateX = 0.0f;
		translateY = 0.0f;


	}



	//Check if Ball collides with left window
	if (ballCollision.ballLeftWindowCollision(ballX,ballRadius)
		|| ballCollision.ballRightWindowCollision(ballX, ballRadius)) {
		reverseBallX();
		count = 1;
		soundcontroller.ballBounce();
	}

	//Check if Ball collides with top window
	if (ballCollision.ballTopWindowCollision(ballY, ballRadius)) {
		reverseBallY();
		count = 1;
		soundcontroller.ballBounce();
	}

	//Check if Ball collides with bottom window
	if (ballCollision.ballBottomWindowCollision(ballY, ballRadius)) {

		if (zoom) {

			glTranslatef(-translateX, -translateY, 0.0f);

			translateX = 0.0f;
			translateY = 0.0f;
			zoom = false;
			zoom = true;
		}

		reverseBallY();
		count = 1;

		//Check who scores
		//AI scores
		if (ballX <= NET_X1 - ballRadius) {
			return 1;

		//Player Scores
		} else if (ballX >= NET_X2 + ballRadius){
			return 2;
		}


	
		
	}

	//Check if ball collides with net
	if (count != 0) {
		if (ballCollision.ballRightNetCollision(ballX,ballY, ballRadius)
			|| ballCollision.ballLeftNetCollision(ballX, ballY, ballRadius)){
			reverseBallX();
			soundcontroller.ballBounce();
		}

	}

	return 0;

}

//Reverse Ball's X Speed
void Ball::reverseBallX(){
	xSpeed = -xSpeed;
}

//Reverse Ball's Y Speed
void  Ball::reverseBallY() {
	ySpeed = -ySpeed;
}


//Reset Balls
void Ball:: resetAll() {
	ballX = BALL_X;
	ballY = BALL_Y;
}

Ball::~Ball() {

}