/**
 * @file controller.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#include "controller.h"


Controller::Controller()
{
	soundcontroller.startTheme();
}

void Controller::renderStart() {
	//Render the background

	bg.render();
	
	if (gameRunning && !gameOver) {

		//Boundary Box
		ballCollision.render();

		bg.render();

		//Render the Net
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

		if (ballCollision.ballRightNetCollision(ball.ballX, ball.ballY, ball.ballRadius)) {
			ai.speed = abs(ai.speed);
		}

		//Check Collision with player/AI
		if (ballCollision.playBallCollision(player1.playerX1-player1.speed, player1.playerX2+player1.speed, player1.playerY2, ball.ballX, ball.ballY,ball.ballRadius) ||
			ballCollision.playBallCollision(ai.aiX1-ai.speed, ai.aiX2+ai.speed, ai.aiY2, ball.ballX, ball.ballY,ball.ballRadius)) {
				ball.reverseBallY();
				ball.reverseBallX();
				soundcontroller.playerBallSound();
		}
		

		//testing
		//ai.scoreAdd();

		//AI Scores

		if (scores == 1) {
			//Add AI Score
			ai.scoreAdd();

			if (ai.getScore() != WINNING_POINTS) {
				soundcontroller.scoreSound();
			}
			else {

				soundcontroller.winSound();
			}
			
			//Reset Ball Position
			ball.ballX = BALL_X;
			ball.ballY = BALL_Y;
			ball.reverseBallY();

		//Player Scores
		}else if(scores == 2){

			//Add Player Score
	
			player1.scoreAdd();

			if (player1.getScore() != WINNING_POINTS) {
				soundcontroller.scoreSound();
			}
			else {

				soundcontroller.winSound();
			}

			//Reset Ball Position
			ball.ballX = BALL_X;
			ball.ballY = BALL_Y;
			ball.reverseBallY();
		}

		//End if winning score reached
		if (player1.getScore() == WINNING_POINTS || ai.getScore() == WINNING_POINTS) {
			gameRunning = false;
			gameOver = true;

		}
		

	}
	else if (!gameOver) {
		//Render the start screen
		renderBg();
		button();
	}

	//Runs if winning score reached
	if (gameOver) {

		renderWinScreen();

		if (player1.getScore() == WINNING_POINTS) {
			//Render Player 1 Win
			Color color;
			color.setColor("FFFFFF");
			Text logo;
			glPushMatrix();
				glTranslatef(0.05f,-0.1f,0);
				logo.largeText(color, (char*)"Player 1 Wins!");
			glPopMatrix();
		}

		if (ai.getScore() == WINNING_POINTS) {
			//Render AI Wins
			Color color;
			color.setColor("FFFFFF");
			Text logo;
			glPushMatrix();
				glTranslatef(0.1f, -0.1f, 0);
				logo.largeText(color, (char*)"AI Wins!");
			glPopMatrix();
		}
	}

}

void Controller::renderBg() {
	Color color;
	color.setColor("d35400");

	glPushMatrix();
		glTranslatef(0, 0, 0);
		glColor3f(SETCOLOR(color));
		Shapes::rectangle(-0.3f,-0.5f,0.3f, 0.5f);
	glPopMatrix();


	color.setColor("e67e22");
	glPushMatrix();
		glColor3f(SETCOLOR(color));
		Shapes::rectangle(-0.28f, -0.48f, 0.28f, 0.48f);
	glPopMatrix();
	
	color.setColor("FFFFFF");
	Text logo;
	glPushMatrix();
		logo.text(color, (char*)"POKEMON BEACH VOLLEYBALL");
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(0.01f, -0.1f, 0.0f);
		logo.text(color, (char*)"Click below to start!");
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(0.08f, -0.33f, 0.0f);
		logo.text(color, (char*)"Player 1:");
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(0.04f, -0.39f, 0.0f);
		logo.text(color, (char*) "Directions: <- / ->");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.07f, -0.49f, 0.0f);
		logo.text(color, (char*)"Game Rules: ");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, -0.54f, 0.0f);
		logo.text(color, (char*) "It's just like Volleyball!");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.02f, -0.59f, 0.0f);
		logo.text(color, (char*) "First to 3 Points wins!");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.06f, -0.71f, 0.0f);
		logo.text(color, (char*) "PRESS 'z' to follow the ball");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.06f, -0.78f, 0.0f);
		logo.text(color, (char*) "PRESS 'r' to restart the game");
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.06f, -0.85f, 0.0f);
		logo.text(color, (char*) "PRESS 'esc' to exit the game");
	glPopMatrix();
	
}

void Controller::button() {
	Color btnColor;
	btnColor.setColor("8e44ad");

	glPushMatrix();
		glColor3f(SETCOLOR(btnColor));
		Shapes::rectangle(-0.08f, 0.15f, 0.08f, 0.25f);
	glPopMatrix();

	btnColor.setColor("ffffff");
	Text logo;
	glPushMatrix();
		glTranslatef(0.11f, -0.21f, 0.0f);
		logo.text(btnColor, (char*)"Start!");
	glPopMatrix();
}


void Controller::clicked(float x, float y) {

	if (!gameRunning) {

		if (x < -0.35 && x > -0.55 && y < -0.56 && y > -0.6) {

			gameRunning = true;
			soundcontroller.clickStart();

		}
	}
}


void Controller::renderWinScreen() {

	Color color;
	color.setColor("d35400");

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glColor3f(SETCOLOR(color));
		Shapes::rectangle(-0.3f, 0.1f, 0.3f, 0.4f);
	glPopMatrix();


	color.setColor("FFFFFF");
	Text logo;
	glPushMatrix();
		glTranslatef(0.0f, -0.2f, 0);
		logo.text(color, (char*)"Press 'r' to restart the game");
	glPopMatrix();


	glPushMatrix();
		glTranslatef(0.0f, -0.25f, 0);
		logo.text(color, (char*)"Press 'esc' to exit the game");
	glPopMatrix();

}

//Reset the game
void Controller::resetGame() {

	//Reset Scores
	player1.resetAll();
	ai.resetAll();
	ball.resetAll();

	gameOver = false;
	gameRunning = false;
	soundcontroller.startTheme();

}
