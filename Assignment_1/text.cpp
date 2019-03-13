/**
* @file text.cpp
*
* @brief CSED541 Computer Graphics Assignment 1
*
* @author Tan Wei Xuan(49003140), Ong Wei Hua(49003139)
* Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
*
*/

#include "text.h"

Text::Text()
{
}

//To Display Scores
void Text::score(Color color, int score) {
	int l, i;
	char st[50];
	snprintf(st, sizeof(st), "Score: %d", score);
	l = strlen(st);
	glPushMatrix();
		glColor3f(SETCOLOR(color));
		glRasterPos2f(0.00f, 0.45f);
		for (i = 0; i < l; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
		}
	glPopMatrix();
}

//To Display General Text
void Text::text(Color color, char st[]) {

	int l, i;
	l = strlen(st);

	glColor3f(SETCOLOR(color));
	glRasterPos2f(-0.15f, 0.40f);
	for (i = 0; i < l; i++) {

		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, st[i]);
	}


}

//To Display larger text
void Text::largeText(Color color, char st[]) {

	int l, i;
	l = strlen(st);

	glColor3f(SETCOLOR(color));
	glRasterPos2f(-0.15f, 0.40f);
	for (i = 0; i < l; i++) {

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
	}


}


