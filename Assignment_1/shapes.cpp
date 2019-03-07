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