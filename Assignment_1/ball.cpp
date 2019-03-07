#include "ball.h"

Ball::Ball() {
	ballRadius = 60;
	ballX = 720.0;
	ballY = 600.0;
	xSpeed = -3.5;
	ySpeed = -1.0;
	count = 0;
}

int Ball::render() {
	Color ballColor;
	ballColor.setColor("398ec6");
	Shapes::circle(ballX, ballY, ballRadius, ballColor); 

	ballX += xSpeed;
	ballY += ySpeed;

	if (ballCollision.ballLeftWindowCollision(ballX,ballRadius)
		|| ballCollision.ballRightWindowCollision(ballX, ballRadius)) {
		xSpeed = -xSpeed;	
		count = 1;
		soundcontroller.ballBounce();
	}

	if (ballCollision.ballTopWindowCollision(ballY, ballRadius)) {
		ySpeed = -ySpeed;
		count = 1;
		soundcontroller.ballBounce();
	}


	if (ballCollision.ballBottomWindowCollision(ballY, ballRadius)) {
		ySpeed = -ySpeed;
		count = 1;
		
		soundcontroller.scoreSound();

		//Check who scores

		//AI scores
		if (ballX <= 705 - ballRadius) {
			return 1;

		//Player Scores
		} else if (ballX >= 745 + ballRadius){
			return 2;
		}
		
	}

	if (count != 0) {
		if (ballCollision.ballRightNetCollision(ballX,ballY, ballRadius,xSpeed)
			|| ballCollision.ballLeftNetCollision(ballX, ballY, ballRadius,xSpeed)){
			xSpeed = -xSpeed;
			soundcontroller.ballBounce();
		}

	}

	return 0;

}

Ball::~Ball() {

}