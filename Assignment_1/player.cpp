#include "player.h"
Player::Player() {

	playerX1 = PLAYER_X1;
	playerY1 = PLAYER_Y1;
	playerX2 = PLAYER_X2;
	playerY2 = PLAYER_Y2;
	speed = PLAYER_SPEED;
	score = 0;
}

void Player::render() {

	Color color;
	color.setColor("c13450");

	//Create the Player
	Shapes::quad(playerX1, playerY1, playerX2, playerY2, color);

	if (collision.leftWindowCollision(playerX1)) {
		playerX1 += speed;
		playerX2 += speed;
	}

	if(collision.leftNetCollision(playerX2)) {
		playerX1 -= speed;
		playerX2 -= speed;
	}

	//Render the score
	glPushMatrix();
		glTranslatef(-300, 50, 0);
		playerScore.score(color, score);
	glPopMatrix();
}

void Player::moveRight() {
	playerX1 += speed;
	playerX2 += speed;
}

void Player::moveLeft(){
	playerX1 -= speed;
	playerX2 -= speed;
}

void Player::scoreAdd() {
	score++;
}

void Player::resetScore() {
	score = 0;
}

int Player::getScore() {
	return score;
}

void collisionDetection() {

}
Player::~Player() {

}