/**
 * @file shapes.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */

#include "shapes.h"


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

void Shapes::circle(double ballX,double ballY, double radius, Color color) {
	
	float angle;
	float x2, y2;
	glColor3f(SETCOLOR(color));
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(ballX, ballY);

	for (angle = 1.0f; angle < 3*PI; angle += 0.2)
	{
		x2 = ballX + sin(angle)*radius;
		y2 = ballY + cos(angle)*radius;
		glVertex2f(x2, y2);
	}

	glEnd();
	
}

Shapes::~Shapes()
{
	
}