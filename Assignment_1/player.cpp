#include "player.h"
Player::Player() {

	playerX1 = 325.5;
	playerY1 = 0;
	playerX2 = 425.5;
	playerY2 = 150;
	speed = 8.0;
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