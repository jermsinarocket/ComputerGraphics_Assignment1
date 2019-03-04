#include "shapes.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "colour.h"
#include <math.h>
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
#define PI 3.1415926535897932384626433832795


Shapes::Shapes() {
}

void Shapes::rect(Color color) {

	glPushMatrix();
	glColor3f(SETCOLOR(color));
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, -5.0);
	glVertex3f(1, 0.0, -5.0);
	glVertex3f(1, 1, -5.0);
	glVertex3f(0, 1, -5.0);
	glEnd();
	glPopMatrix();
}



void Shapes::circle(Color color) {
	glPushMatrix();
	glColor3f(SETCOLOR(color));
	glBegin(GL_POLYGON);
	for (double i = 0; i < 2 * PI; i += PI / 24)
		glVertex3f(cos(i) * 1, sin(i) * 1, -5.0);
	glEnd();
	glPopMatrix();


}
void Shapes::triangle(Color color) {
	glPushMatrix();
	glColor3f(SETCOLOR(color));
	glBegin(GL_POLYGON);
	glVertex3f(-1, 0, -5.0);
	glVertex3f(1, 0, -5.0);
	glVertex3f(.02, 1, -5.0);
	glVertex3f(0, 1, -5.0);

	glEnd();
	glPopMatrix();
}

void Shapes::octagon(Color color) {
	float angle = 0.0;
	float dAngle = PI / 4.0;
	float x, y;
	glPushMatrix();
	glColor3f(SETCOLOR(color));
	glBegin(GL_POLYGON);
	for (int i = 0; i < 8; i++) {
		double theta = i * 2.*PI / 8.;
		x = 1 * cos(theta);
		y = 1 * sin(theta);
		glVertex3f(x, y, -5.0);
	}
	glEnd();
	glPopMatrix();
}
Shapes::~Shapes()
{
	//dtor
}