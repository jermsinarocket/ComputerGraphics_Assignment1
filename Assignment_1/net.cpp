#include "net.h"
#include "shapes.h"
#include "colour.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()

Net::Net(double width, double height) {
	netX1 = width/2 - 15;
	netY1 = 0.0;
	netX2 = width/2 + 15;
	netY2 = height * 0.5;
}


void Net::render() {

	Color color;
	color.setColor("000000");
	//Create the net
	glColor3f(SETCOLOR(color));
	glRectf(netX1, netY1, netX2, netY2);
	
	
}

Net::~Net(){

}