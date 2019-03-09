#ifndef NET_H
#define NET_H
#include "colour.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>

#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
#define SCREEN_WIDTH 1440
#define SCREEN_HEIGHT 800
#define NET_X1  SCREEN_WIDTH/2 - 15
#define NET_X2  SCREEN_WIDTH/2 + 15
#define NET_Y1  0
#define NET_Y2  SCREEN_HEIGHT * 0.7

class Net {

public:
	Net();
	void render();
	virtual ~Net();

private:
	double netX1;
	double netY1;
	double netX2;
	double netY2;
protected:
};

#endif // NET_H