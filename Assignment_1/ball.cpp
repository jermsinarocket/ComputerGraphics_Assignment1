#include "ball.h"

Ball::Ball() {
	ballRadius = BALL_RADIUS;
	ballX = BALL_X;
	ballY = BALL_Y;
	xSpeed = BALL_xSpeed;
	ySpeed = BALL_ySpeed;
	count = 0;
}

int Ball::render() {

	Color ballColor;
	ballColor.setColor("398ec6");
	Shapes::circle(ballX, ballY, ballRadius, ballColor); 

	//Ball constantly at x,y speed
	ballX += xSpeed;
	ballY += ySpeed;

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
		if (ballCollision.ballRightNetCollision(ballX,ballY, ballRadius,xSpeed)
			|| ballCollision.ballLeftNetCollision(ballX, ballY, ballRadius,xSpeed)){
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