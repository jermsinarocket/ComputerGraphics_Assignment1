#include "controller.h"
#include "net.h"
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
Controller::Controller()
{
	soundcontroller.startTheme();
}

void Controller::renderStart() {
	//Render the background
	bg.render();
	
	if (gameRunning) {
		Net net(1440, 800);
		net.render();
	}
	else {
		//Render the start screen
		renderBg();
		//button();
		/*glPushMatrix();
			glTranslatef(2.6, -3.6, 0);
		glPopMatrix();*/
	}
}
void Controller::renderBg() {
	Color color;
	color.setColor("d35400");

	glPushMatrix();
		glColor3f(SETCOLOR(color));
		Shapes::rectangle(500.0,200.0,1000.0, 700.0);
	glPopMatrix();

	/*
	glPushMatrix();
		glTranslatef(-4.5, -4.5, 0);
		glScalef(9, 9, 1);
		Shapes::rect(color);
	glPopMatrix();

	color.setColor("e67e22");
	glPushMatrix();
		glTranslatef(-4, -4, 0);
		glScalef(8, 8, 1);
		Shapes::rect(color);
	glPopMatrix();

	color.setColor("FFFFFF");
	Text logo;
	glPushMatrix();
		glTranslatef(-1.5, 2.5, 0);
		logo.text(color, (char*)"POKEMON BEACH VOLLEYBALL");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.3, 1.5, 0);
	logo.text(color, (char*)"Click below to start!");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.6, -1.6, 0);
		logo.text(color, (char*)"Player 1:");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.1, -2.0, 0);
		logo.text(color, (char*) "Direction: A / D");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6, -2.5, 0);
	logo.text(color, (char*)"Player 2:");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.1, -2.9, 0);
	logo.text(color, (char*) "Direction: Arrow Keys (<- | ->)");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.35, -3.5, 0);
		logo.text(color, (char*) "PRESS 'p' to pause the game");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.22, -3.9, 0);
		logo.text(color, (char*) "PRESS 'esc' to exit the game");
	glPopMatrix();
	*/
}

void Controller::button() {
	Color btnColor;
	btnColor.setColor("8e44ad");

	glPushMatrix();
		glTranslatef(0.1, -0.1, 0);
		Shapes::octagon(btnColor);
	glPopMatrix();

	btnColor.setColor("ffffff");
	Text logo;
	glPushMatrix();
		glTranslatef(-.25, -.1, 0);
		logo.text(btnColor, (char*)"Start!");
	glPopMatrix();
}


void Controller::clicked(float x, float y) {

	if (!gameRunning) {

		if (x < -0.4 && x > -0.56 && y < -0.4 && y > -0.6) {

			gameRunning = true;
			gameOver = false;
			soundcontroller.clickStart();

		}
	}
}

