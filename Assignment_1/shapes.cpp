#include "shapes.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
#define PI 3.1415926535897932384626433832795


Shapes::Shapes() {
}

void Shapes::rectangle(double x1, double y1, double x2, double y2) {
	glRectf(x1, y1, x2, y2);
}

void Shapes::quad(double x1, double y1, double x2, double y2,Color color) {
	glColor3f(SETCOLOR(color));
	glBegin(GL_QUADS);
		glVertex2f(x1, y1);
		glVertex2f(x1, y2);
		glVertex2f(x2, y2);
		glVertex2f(x2, y1);
	glEnd();

}
/*

void Shapes::circle(Color color) {
	glPushMatrix();
	glColor3f(SETCOLOR(color));
	glBegin(GL_POLYGON);
	for (double i = 0; i < 2 * PI; i += PI / 24)
		glVertex3f(cos(i) * 1, sin(i) * 1, -5.0);
	glEnd();
	glPopMatrix();


}

*/
Shapes::~Shapes()
{
	
}