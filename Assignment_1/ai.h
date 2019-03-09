
#include "shapes.h"
#include "colour.h"
#include "text.h"
#include "collision.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>

#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()

#define AI_X1 1054.5
#define AI_X2 1154.5
#define AI_Y1 0
#define AI_Y2 150
#define AI_SPEED -3.0

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
