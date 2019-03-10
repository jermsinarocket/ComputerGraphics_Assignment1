#include "background.h"

Background::Background() {
}

void Background::render() {
	
	sun();
	
	glPushMatrix();
		glTranslatef(0, 4.5, 0);
		cloud();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(250, 100, 0);
		cloud();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(500, 70, 0);
		cloud();
	glPopMatrix();

}

void Background::sun() {

	Color color;

	color.setColor("fdf78c");

	//colour of sun background
	glColor3f(SETCOLOR(color));
	glPushMatrix();
		Shapes::rectangle(125.0, 600.0, 275.0, 750.0);
	glPopMatrix();

	// color of sun

	color.setColor("fff200");
	glColor3f(SETCOLOR(color));
	glPushMatrix();
		Shapes::rectangle(135.0, 620.0, 245.0, 740.0);
	glPopMatrix();
}

void Background::cloud() {

	Color color;

	color.setColor("FFFFFF");

	glColor3f(SETCOLOR(color));

	glPushMatrix();
		Shapes::rectangle(550.0, 500.0, 675.0, 550.0);
	glPopMatrix();

	glPushMatrix();
		Shapes::rectangle(575.0, 500.0,650.0,600.0);
	glPopMatrix();

}

Background::~Background()
{
	//dtor
}