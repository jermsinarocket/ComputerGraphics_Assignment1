#include <iostream> 
#include <GL/glew.h> 
#include <GL/glut.h> 
#include <windows.h>
#include "colour.h"
#include "shapes.h"
#include "background.h"
#include "controller.h"
#include "player.h"

using namespace std;

#define SCREEN_WIDTH 1440
#define SCREEN_HEIGHT 800
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()

float currentWidth = 1440;
float currentHeight = 800;
Controller control;
Net net(currentWidth,currentHeight);

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		//Start Rendering
		control.renderStart();
		//Update screen
		glutSwapBuffers();
	

}

//For Start Buttton
void processMouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			control.clicked((float)((x / currentWidth) - 1), (float)((y / currentHeight) - 1));
		}
	}
}

void processKeys(unsigned char key, int x, int y) {
	if (key == 27){
		exit(EXIT_SUCCESS);
	}

	

}

void specialKeyboard(int key, int x, int y) { 
	
	switch (key) { 

		case GLUT_KEY_RIGHT: 
			control.player1.moveRight();
			break; 
		case GLUT_KEY_LEFT: 
			control.player1.moveLeft();
			break; 
	} 
}



void changeSize(int w, int h) {

	//Prevents resize
	glutReshapeWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutPositionWindow(50, 50);

	//Protect against divide by zero
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluOrtho2D(0, w, 0,h );
	currentWidth = w;
	currentHeight = h;

	glDisable(GL_DEPTH_TEST);
	
	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
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
	glutKeyboardFunc(processKeys);
	glutMouseFunc(processMouse);
	glutSpecialFunc(specialKeyboard);

	glutMainLoop();



	return 1;
}
