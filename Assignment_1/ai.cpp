#include "ai.h"

Ai::Ai() {

	aiX1 = AI_X1;
	aiY1 = AI_Y1;
	aiX2 = AI_X2;
	aiY2 = AI_Y2;
	speed = AI_SPEED;
	score = 0;
}

void Ai::render() {

	Color color;
	color.setColor("145214");

	//Create the Player
	Shapes::quad(aiX1, aiY1, aiX2, aiY2, color);


	//Render the score
	glPushMatrix();
		glTranslatef(450, 50, 0);
		aiScore.score(color, score);
	glPopMatrix();

	aiX1 += speed;
	aiX2 += speed;


	if (collision.rightWindowCollision(aiX2) || collision.rightNetCollision(aiX1)) {
		speed = -speed;
	}

}

void Ai::scoreAdd() {
	score++;
}

void Ai::resetScore() {
	score = 0;
}

int Ai::getScore() {
	return score;
}

Ai::~Ai() {

}