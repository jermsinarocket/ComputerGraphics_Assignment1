#ifndef NET_H
#define NET_H
#include "colour.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()


class Net {

public:
	Net(double width, double height);
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