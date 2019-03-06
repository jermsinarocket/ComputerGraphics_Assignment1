#ifndef COLLISION_H
#define COLLISION_H
#include "shapes.h"
#include "colour.h"
#include "text.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()


class Collision
{
public:
	/** Default constructor */
	Collision();
	bool leftNetCollision(double x2);
	bool leftWindowCollision(double x2);
	virtual ~Collision();

	double netLeftX;
	double netRightX;
	double windowLeftX;
	double windowRightX;


protected:
private:
	int score;
};

#endif // COLLISION_H