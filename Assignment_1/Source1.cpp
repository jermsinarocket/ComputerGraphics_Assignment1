
#include <iostream> 
#include <GL/glew.h> 
#include <GL/freeglut.h> 
#include <windows.h>
#include "colour.h"
#include "shapes.h"
#include "background.h"
#include "controller.h"

using namespace std;

#define SCREEN_WIDTH 1440
#define SCREEN_HEIGHT 800
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()

float currentWidth = 1440;
float currentHeight = 800;
Controller control;

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	control.renderStart();

	//Update screen
	glutSwapBuffers();
}


void changeSize(int w, int h) {
	glutReshapeWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutPositionWindow(50, 50);

	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);

	currentWidth = w;
	currentHeight = h;
	gluPerspective(100, ratio, 1, 100);
	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1440,800);
	glutCreateWindow("Pokemon Beach Volleyball");

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	Color bgcolor;
	bgcolor.setColor("a7edfe");
	glClearColor(SETCOLOR(bgcolor), 1);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutMainLoop();



	return 1;
}
