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

	//Create the AI
	Shapes::quad(aiX1, aiY1, aiX2, aiY2, color);


	//Render the score
	glPushMatrix();
		glTranslatef(450, 50, 0);
		aiScore.score(color, score);
	glPopMatrix();

	//Move AI constantly by x,y speed
	aiX1 += speed;
	aiX2 += speed;

	//Check AI - Window Collision
	if (collision.rightWindowCollision(aiX2) || collision.rightNetCollision(aiX1)) {
		speed = -speed;
	}

}

//Add AI score
void Ai::scoreAdd() {
	score++;
}

//Reset AI Score
void Ai::resetScore() {
	score = 0;
}

//Get AI Score
int Ai::getScore() {
	return score;
}

//Reset AI
void Ai::resetAll() {

	aiX1 = AI_X1;
	aiY1 = AI_Y1;
	aiX2 = AI_X2;
	aiY2 = AI_Y2;
	speed = AI_SPEED;
	resetScore();
}

Ai::~Ai() {

}