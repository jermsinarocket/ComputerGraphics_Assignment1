#include "controller.h"

Controller::Controller()
{
	soundcontroller.startTheme();
}

void Controller::renderStart() {

	bg.render();
	renderBg();
	button();

	if (gameRunning) {
	}
	else {
		glPushMatrix();
		glPushMatrix();
		glTranslatef(2.6, -3.6, 0);
		glPopMatrix();
	}
}

void Controller::renderBg() {
	Color color;
	color.setColor("d35400");
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
