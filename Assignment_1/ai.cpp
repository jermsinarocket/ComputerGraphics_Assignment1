#include "ai.h"

Ai::Ai() {

	aiX1 = 1054.5;
	aiY1 = 0;
	aiX2 = 1154.5;
	aiY2 = 150;
	speed = 8.0;
	score = 0;
}

void Ai::render() {

	Color color;
	color.setColor("145214");

	//Create the Player
	Shapes::quad(aiX1, aiY1, aiX2, aiY2, color);

	if (collision.rightWindowCollision(aiX1)) {
		aiX1 -= speed;
		aiX2 -= speed;
	}

	if (collision.rightNetCollision(aiX2)) {
		aiX1 += speed;
		aiX2 += speed;
	}

	//Render the score
	glPushMatrix();
		glTranslatef(450, 50, 0);
		aiScore.score(color, score);
	glPopMatrix();
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