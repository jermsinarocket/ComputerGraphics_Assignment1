#include "background.h"
#include "shapes.h"
#include "colour.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
Background::Background() {
	cloudFarX = cloudNearX = 0.0;
	sunScale = 1;
}

void Background::render() {
	glPushMatrix();
		glTranslatef(-9, 4, 0);
		glScalef(sunScale, sunScale, 1);
		sun();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(cloudFarX, 4.5, 0);
		glScalef(.8, .8, 1);
		cloud();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(cloudFarX + 5, 5, 0);
		glScalef(.8, .8, 1);
		cloud();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(cloudNearX + 5, 2, 0);
		glScalef(1.2, 1.2, 1);
		cloud();
	glPopMatrix();

}

void Background::sun() {
	Color color;
	// color of background wrapper
	color.setColor("bbedf9");

	glPushMatrix();
	glScalef(10, 10, 1);
	glTranslatef(-.5, -.4, 0);
	Shapes::rect(color);
	glPopMatrix();
	// color of sun background wrapper
	color.setColor("fdf78c");

	glPushMatrix();
	glScalef(1.5, 1.5, 1);
	glTranslatef(-.155, -.155, 0);
	Shapes::rect(color);
	glPopMatrix();
	// color of sun
	color.setColor("fff200");

	glPushMatrix();
	Shapes::rect(color);
	glPopMatrix();

}
void Background::cloud() {
	Color color;
	color.setColor("ffffff");

	glPushMatrix();
	glTranslatef(.4, 0, 0);
	Shapes::rect(color);
	glPopMatrix();

	glPushMatrix();
	glScalef(.5, .5, 1);
	glTranslatef(0, 0, 0);
	Shapes::rect(color);

	glPopMatrix();

	glPushMatrix();
	glScalef(.5, .5, 1);
	glTranslatef(2.5, 0, 0);
	Shapes::rect(color);
	glPopMatrix();


}

Background::~Background()
{
	//dtor
}