/**
 * @file main.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#include <iostream> 
#include <GL/glew.h> 
#include <GL/glut.h> 
#include <GL/glu.h>
#include <windows.h>
#include "controller.h"


using namespace std;

#define SCREEN_WIDTH 1440
#define SCREEN_HEIGHT 800
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
#define ZOOM_FACTOR 0.30

float currentWidth = 1440;
float currentHeight = 800;
Controller control;


void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Start Rendering
	control.renderStart();
	//Update screen
	glutSwapBuffers();

}




//For Mouse Click
void processMouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			control.clicked((float)((x / currentWidth) - 1), (float)((y / currentHeight) - 1));
		}
	}
}

//For Keyboard Inputs (Keys)
void processKeys(unsigned char key, int x, int y) {
	if (key == 27){
		exit(EXIT_SUCCESS);
	}

	if (key == 'r') {
		control.resetGame();
	}

	if (key == 'z') {

		if (control.ball.zoom) {
			control.ball.zoom = false;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			//Reset Clipping to fixed screen
			gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

			glMatrixMode(GL_MODELVIEW);
		}
		else {
			control.ball.zoom = true;

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			//Clips screen to ball
			gluOrtho2D(control.ball.ballX - ZOOM_FACTOR, control.ball.ballX + ZOOM_FACTOR, control.ball.ballY - ZOOM_FACTOR, control.ball.ballY + ZOOM_FACTOR);

			glMatrixMode(GL_MODELVIEW);

		}
	}

}


//For directional keyboard keys
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


/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void changeSize(GLsizei w, GLsizei h) {

	//Prevents resize
	//glutReshapeWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
	//glutPositionWindow(50, 50);

	//Protect against divide by zero
	if (h == 0)
		h = 1;

	float aspect = w  / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (control.ball.zoom) {

		gluOrtho2D(control.ball.ballX - ZOOM_FACTOR, control.ball.ballX + ZOOM_FACTOR, control.ball.ballY - ZOOM_FACTOR, control.ball.ballY + ZOOM_FACTOR);

	}
	else {

		gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

	}



	currentWidth =  w;
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

	//Fullscreen mode
	glutFullScreen();

	glutMainLoop();



	return 1;
}
