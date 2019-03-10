#ifndef COLLISION_H
#define COLLISION_H
#include "shapes.h"
#include "colour.h"
#include "text.h"
#include "net.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>

#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
#define WINDOW_RIGHT 1.0
#define WINDOW_TOP 1.0
#define WINDOW_LEFT -1.0
#define WINDOW_BOTTOM -1.0


class Collision
{
public:
	/** Default constructor */
	Collision();

	//Player/AI - Net Collision
	bool leftNetCollision(double x);
	bool rightNetCollision(double x);

	//Player/AI - Net Collision
	bool leftWindowCollision(double x);
	bool rightWindowCollision(double x);

	//Ball - Window Collision
	bool ballRightWindowCollision(double x, double radius);
	bool ballLeftWindowCollision(double x,double radius);
	bool ballTopWindowCollision(double y, double radius);
	bool ballBottomWindowCollision(double y, double radius);

	//Ball -Net Collision
	bool ballRightNetCollision(double x,double y, double radius,double speed);
	bool ballLeftNetCollision(double x,double y, double radius,double speed);

	//Player/AI - Ball Collision
	bool playBallCollision(double x1, double x2, double y1, double ballX, double ballY, double ballRadius);

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