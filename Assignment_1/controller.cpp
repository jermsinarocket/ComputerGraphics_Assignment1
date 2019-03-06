#include "controller.h"
#include "net.h"
#include "player.h"

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
		Player player1;
		Player player2;
	}
	else {
		//Render the start screen
		renderBg();
		button();
	}
}
void Controller::renderBg() {
	Color color;
	color.setColor("d35400");

	glPushMatrix();
		glTranslatef(0, 0, 0);
		glColor3f(SETCOLOR(color));
		Shapes::rectangle(500.0,170.0,1000.0, 620.0);
	glPopMatrix();


	color.setColor("e67e22");
	glPushMatrix();
		glColor3f(SETCOLOR(color));
		Shapes::rectangle(520.0, 190.0, 980.0, 600.0);
	glPopMatrix();
	
	color.setColor("FFFFFF");
	Text logo;
	glPushMatrix();
		logo.text(color, (char*)"POKEMON BEACH VOLLEYBALL");
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(10, -30, 0);
		logo.text(color, (char*)"Click below to start!");
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(10, -150, 0);
		logo.text(color, (char*)"Player 1:");
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(10, -170, 0);
		logo.text(color, (char*) "Direction: A / D");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10, -210, 0);
		logo.text(color, (char*)"Player 2:");
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10, -230, 0);
	logo.text(color, (char*) "Direction: Arrow Keys (<- | ->)");
	glPopMatrix();

	/*
	glPushMatrix();
		glTranslatef(60, -340, 0);
		logo.text(color, (char*) "PRESS 'p' to pause the game");
	glPopMatrix();
	*/
	glPushMatrix();
		glTranslatef(60, -360, 0);
		logo.text(color, (char*) "PRESS 'esc' to exit the game");
	glPopMatrix();
	
}

void Controller::button() {
	Color btnColor;
	btnColor.setColor("8e44ad");

	glPushMatrix();
		glColor3f(SETCOLOR(btnColor));
		Shapes::rectangle(680.0, 450.0, 830.0, 500);
	glPopMatrix();

	btnColor.setColor("ffffff");
	Text logo;
	glPushMatrix();
		glTranslatef(80, -85, 0);
		logo.text(btnColor, (char*)"Start!");
	glPopMatrix();
}


void Controller::clicked(float x, float y) {

	if (!gameRunning) {

		if (x < -0.4 && x > -0.50 && y < -0.55 && y > -0.6) {

			gameRunning = true;
			gameOver = false;
			soundcontroller.clickStart();

		}
	}
}

