#include "text.h"
#include <cstdio>
using namespace std;
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
Text::Text()
{
}

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

void Text::text(Color color, char st[]) {

	int l, i;
	l = strlen(st);

	glColor3f(SETCOLOR(color));
	glRasterPos2f(-0.15f, 0.40f);
	for (i = 0; i < l; i++) {

		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, st[i]);
	}


}


void Text::largeText(Color color, char st[]) {

	int l, i;
	l = strlen(st);

	glColor3f(SETCOLOR(color));
	glRasterPos2f(-0.15f, 0.40f);
	for (i = 0; i < l; i++) {

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
	}


}


