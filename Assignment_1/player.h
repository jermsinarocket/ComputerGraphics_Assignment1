#ifndef PLAYER_H
#define PLAYER_H
#include "shapes.h"
#include "colour.h"
#include "text.h"
#include "collision.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()


class Player
{
public:
	/** Default constructor */
	Player();

	void render();
	void moveRight();
	void moveLeft();
	void scoreAdd();
	void resetScore();
	int getScore();
	virtual ~Player();

	double playerX1;
	double playerY1;
	double playerX2;
	double playerY2;
	double speed;

	Text playerScore;
	Collision collision;
	
protected:
private:
	int score;
};

#endif // PLAYER_H