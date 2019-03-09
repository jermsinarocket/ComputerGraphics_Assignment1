#include "controller.h"


Controller::Controller()
{
	soundcontroller.startTheme();
}

void Controller::renderStart() {
	//Render the background
	bg.render();
	
	if (gameRunning) {


		Net net;
		net.render();

		//Render the Player
		player1.render();
		//Render the Ai
		ai.render();

		int scores = ball.render();

		//AI follow ball movement
		if (ballCollision.ballRightWindowCollision(ball.ballX, ball.ballRadius)){
			ai.speed = -(abs(ai.speed));
		}

		if (ballCollision.ballLeftNetCollision(ball.ballX, ball.ballY, ball.ballRadius, ball.xSpeed)) {
			ai.speed = abs(ai.speed);
		}

		//collision with player/AI
		if (ballCollision.playBallCollision(player1.playerX1, player1.playerX2, player1.playerY2, ball.ballX, ball.ballY,ball.ballRadius) || 
			ballCollision.playBallCollision(ai.aiX1, ai.aiX2, ai.aiY2, ball.ballX, ball.ballY,ball.ballRadius)) {
			ball.ySpeed = -ball.ySpeed;
			ball.xSpeed = -ball.xSpeed;
			soundcontroller.ballBounce();
		}
		



		//AI Scores

		if (scores == 1) {
			//Add AI Score
			ai.scoreAdd();
			//Reset Ball Position
			ball.ballX = BALL_X;
			ball.ballY = BALL_Y;
			ball.ySpeed = -ball.ySpeed;

		//Player Scores
		}else if(scores == 2){

			//Add Player Score
			player1.scoreAdd();
			//Reset Ball Position
			ball.ballX = BALL_X;
			ball.ballY = BALL_Y;
			ball.ySpeed = -ball.ySpeed;
		}

		//End if score reached
		if (player1.getScore() == WINNING_POINTS || ai.getScore() == WINNING_POINTS) {

			gameRunning = false;

			if (player1.getScore() == WINNING_POINTS) {
				// Do something
			}

			if (ai.getScore() == WINNING_POINTS) {
				//Do something
			}

		}
	}
	else {
		//Render the start screen
		renderBg();
		button();
	}
}
void Controller::renderBg() {
	Color color;
	color.setColor("d35400");

	glPushMatrix();
		glTranslatef(0, 0, 0);
		glColor3f(SETCOLOR(color));
		Shapes::rectangle(500.0,170.0,1000.0, 620.0);
	glPopMatrix();


	color.setColor("e67e22");
	glPushMatrix();
		glColor3f(SETCOLOR(color));
		Shapes::rectangle(520.0, 190.0, 980.0, 600.0);
	glPopMatrix();
	
	color.setColor("FFFFFF");
	Text logo;
	glPushMatrix();
		logo.text(color, (char*)"POKEMON BEACH VOLLEYBALL");
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(10, -30, 0);
		logo.text(color, (char*)"Click below to start!");
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(10, -150, 0);
		logo.text(color, (char*)"Player 1:");
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(10, -170, 0);
		logo.text(color, (char*) "Directions: A / D");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10, -210, 0);
		logo.text(color, (char*)"Game Rules: ");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10, -230, 0);
	logo.text(color, (char*) "It's just like Volleyball!");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10, -250, 0);
	logo.text(color, (char*) "First to 3 Points wins!");
	glPopMatrix();

	/*
	glPushMatrix();
		glTranslatef(60, -340, 0);
		logo.text(color, (char*) "PRESS 'p' to pause the game");
	glPopMatrix();
	*/
	glPushMatrix();
		glTranslatef(60, -360, 0);
		logo.text(color, (char*) "PRESS 'esc' to exit the game");
	glPopMatrix();
	
}

void Controller::button() {
	Color btnColor;
	btnColor.setColor("8e44ad");

	glPushMatrix();
		glColor3f(SETCOLOR(btnColor));
		Shapes::rectangle(680.0, 450.0, 830.0, 500);
	glPopMatrix();

	btnColor.setColor("ffffff");
	Text logo;
	glPushMatrix();
		glTranslatef(80, -85, 0);
		logo.text(btnColor, (char*)"Start!");
	glPopMatrix();
}


void Controller::clicked(float x, float y) {

	if (!gameRunning) {

		if (x < -0.4 && x > -0.50 && y < -0.55 && y > -0.6) {

			gameRunning = true;
			gameOver = false;
			soundcontroller.clickStart();

		}
	}
}

