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
	bool leftNetCollision(double x);
	bool leftWindowCollision(double x);
	bool rightNetCollision(double x);
	bool rightWindowCollision(double x);
	bool ballRightWindowCollision(double x, double radius);
	bool ballLeftWindowCollision(double x,double radius);
	bool ballTopWindowCollision(double y, double radius);
	bool ballBottomWindowCollision(double y, double radius);
	bool ballRightNetCollision(double x,double y, double radius,double speed);
	bool ballLeftNetCollision(double x,double y, double radius,double speed);
	virtual ~Collision();

	double netLeftX;
	double netRightX;
	double netHeight;
	double windowLeftX;
	double windowRightX;
	double windowTopX;
	double windowBottomX;


protected:
private:
	int score;
};

#endif // COLLISION_H