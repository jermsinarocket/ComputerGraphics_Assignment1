/**
 * @file colliision.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#include "collision.h"

Collision::Collision() {

}

void Collision::render() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(255, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(WINDOW_LEFT, WINDOW_BOTTOM);
		glVertex2f(WINDOW_LEFT, WINDOW_TOP);
		glVertex2f(WINDOW_RIGHT, WINDOW_TOP);
		glVertex2f(WINDOW_RIGHT, WINDOW_BOTTOM);
	glEnd();
}

// Player/AI - Net (Left) Collision
bool Collision::leftNetCollision(double x) {
	if (x >= NET_X1) {
		return true;
	}
	else {
	    return false;
	}
}

// Player/AI - Net (Right) Collision
bool Collision::rightNetCollision(double x) {
	if (x <= NET_X2) {
		return true;
	}
	else {
		return false;
	}
}


// Player/AI - Window (Right) Collision
bool Collision::rightWindowCollision(double x) {
	if (x >= WINDOW_RIGHT) {
		return true;
	}
	else {
		return false;
	}
}

// Player/AI - Window (Left) Collision
bool Collision::leftWindowCollision(double x) {
	if (x <= WINDOW_LEFT) {
		return true;
	}
	else {
		return false;
	}
}


// Ball - Window (Left) Collision
bool Collision::ballLeftWindowCollision(double x,double radius) {
	if (x < WINDOW_LEFT +radius) {
		return true;
	}
	else {
		return false;
	}
}

// Ball - Window (Right) Collision
bool Collision::ballRightWindowCollision(double x, double radius) {
	if (x > WINDOW_RIGHT-radius) {
		return true;
	}
	else {
		return false;
	}
}

// Ball - Window (Top) Collision
bool Collision::ballTopWindowCollision(double y, double radius) {
	if (y > WINDOW_TOP - radius) {
		return true;
	}
	else {
		return false;
	}
}

// Ball - Window (Bottom) Collision
bool Collision::ballBottomWindowCollision(double y, double radius) {
	if (y < WINDOW_BOTTOM + radius) {
		return true;
	}
	else {
		return false;
	}
}

// Ball - Net (Right) Collision
bool Collision::ballRightNetCollision(double x, double y, double radius) {
	if (x >= NET_X2 + radius  && x <= NET_X2  + radius && y <= NET_Y2) {
		return true;
	}
	else {
		return false;
	}
}


// Ball - Net (Tp[) Collision
bool Collision::ballLeftNetCollision(double x, double y, double radius) {
	if (x >= NET_X1 - radius && x <= NET_X1 - radius && y <= NET_Y2) {
		return true;
	}
	else {
		return false;
	}
}

// Player/AI - Ball Collision
bool Collision::playBallCollision(double x1, double x2, double y1, double ballX, double ballY, double ballRadius) {
	if ((x1 <= ballX && ballX <= x2) && ballY-ballRadius <= y1) {
		return true;
	}
	else {
		return false;
	}

}


Collision::~Collision(){

}