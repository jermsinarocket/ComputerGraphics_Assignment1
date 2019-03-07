
#include "shapes.h"
#include "colour.h"
#include "text.h"
#include "collision.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()


class Ai
{
public:
	/** Default constructor */
	Ai();

	void render();
	void scoreAdd();
	void resetScore();
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
