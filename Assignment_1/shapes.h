#ifndef SHAPES_H
#define SHAPES_H
#include "colour.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
#define PI 3.1415926535897932384626433832795

class Shapes
{
public:
	/** Default constructor */
	Shapes();
	static void circle(double ballX,double ballY,double radius, Color color);
	static void quad(double x1, double y1, double x2, double y2, Color color);
	static void rectangle(double x1, double y1, double x2, double y2);
	/** Default destructor */
	virtual ~Shapes();
protected:
private:
};

#endif // SHAPES_H