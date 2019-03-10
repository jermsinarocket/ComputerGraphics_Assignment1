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

	//Check Left Window Collision
	if (collision.leftWindowCollision(playerX1)) {
		moveRight();
	}
	
	//Check Left Net Collision
	if(collision.leftNetCollision(playerX2)) {
		moveLeft();
	}

	//Render the score
	glPushMatrix();
		glTranslatef(-0.55, 0, 0);
		playerScore.score(color, score);
	glPopMatrix();
}

//Move Player Right
void Player::moveRight() {
	playerX1 += speed;
	playerX2 += speed;
}

//Move Player Left
void Player::moveLeft(){
	playerX1 -= speed;
	playerX2 -= speed;
}

//Add Player's Score
void Player::scoreAdd() {
	score++;
}

//Reset Player's Score
void Player::resetScore() {
	score = 0;
}

//Get Player Score
int Player::getScore() {
	return score;
}


//Reset Player
void Player::resetAll() {
	playerX1 = PLAYER_X1;
	playerY1 = PLAYER_Y1;
	playerX2 = PLAYER_X2;
	playerY2 = PLAYER_Y2;
	speed = PLAYER_SPEED;
	resetScore();
}

Player::~Player() {

}