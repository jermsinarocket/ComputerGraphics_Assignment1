/**
 * @file ai.h
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */

#include "shapes.h"
#include "colour.h"
#include "text.h"
#include "collision.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>

#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()

#define AI_X1 0.43
#define AI_X2 0.57
#define AI_Y1 -1.0
#define AI_Y2 -0.60
//Can be changed to increase/decrease speed
#define AI_SPEED -0.004

class Ai
{
public:
	/** Default constructor */
	Ai();

	void render();
	void scoreAdd();
	void resetScore();
	void resetAll();
	int getScore();
	virtual ~Ai();

	double aiX1;
	double aiY1;
	double aiX2;
	double aiY2;
	double speed;

	Text aiScore;
	Collision collision;

protected:
private:
	int score;
};
