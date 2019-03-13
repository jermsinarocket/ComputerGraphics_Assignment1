/**
 * @file background.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#include "background.h"

Background::Background() {
}

void Background::render() {
	
	sun();
	
	glPushMatrix();
		glScalef(0.8f,0.8f,1.0f);
		cloud();
	glPopMatrix();

	glPushMatrix();
		glScalef(0.9f, 0.9f, 1.0f);
		glTranslatef(0.5, -0.2, 0.0f);
		cloud();
	glPopMatrix();

	glPushMatrix();
		glScalef(0.7f, 0.7f, 1.0f);
		glTranslatef(1.08f, 0.3f, 0.0f);
		cloud();
	glPopMatrix();

}

void Background::sun() {

	Color color;

	color.setColor("fdf78c");

	//colour of sun background
	glColor3f(SETCOLOR(color));
	glPushMatrix();
		Shapes::rectangle(-0.9f, 0.55f, -0.70f, 0.85f);	
	glPopMatrix();

	// color of sun

	color.setColor("fff200");
	glColor3f(SETCOLOR(color));
	glPushMatrix();
		Shapes::rectangle(-0.88, 0.58f, -0.72f, 0.83f);
	glPopMatrix();
}

void Background::cloud() {

	Color color;

	color.setColor("FFFFFF");

	glColor3f(SETCOLOR(color));

	glPushMatrix();
		Shapes::rectangle(-0.2f, 0.6, 0.05f, 0.73f);
	glPopMatrix();

	glPushMatrix();
		Shapes::rectangle(-0.15f, 0.6, 0.0f, 0.79f);
	glPopMatrix();

}

Background::~Background()
{
	//dtor
}