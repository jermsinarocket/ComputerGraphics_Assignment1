#include "collision.h"

Collision::Collision() {

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
	if (x >= SCREEN_WIDTH) {
		return true;
	}
	else {
		return false;
	}
}

// Player/AI - Window (Left) Collision
bool Collision::leftWindowCollision(double x) {
	if (x <= WINDOW_LEFTX) {
		return true;
	}
	else {
		return false;
	}
}


// Ball - Window (Left) Collision
bool Collision::ballLeftWindowCollision(double x,double radius) {
	if (x < WINDOW_LEFTX +radius) {
		return true;
	}
	else {
		return false;
	}
}

// Ball - Window (Right) Collision
bool Collision::ballRightWindowCollision(double x, double radius) {
	if (x > SCREEN_WIDTH-radius) {
		return true;
	}
	else {
		return false;
	}
}

// Ball - Window (Top) Collision
bool Collision::ballTopWindowCollision(double y, double radius) {
	if (y > SCREEN_HEIGHT - radius) {
		return true;
	}
	else {
		return false;
	}
}

// Ball - Window (Bottom) Collision
bool Collision::ballBottomWindowCollision(double y, double radius) {
	if (y < WINDOW_BOTTOMX + radius) {
		return true;
	}
	else {
		return false;
	}
}

// Ball - Net (Right) Collision
bool Collision::ballRightNetCollision(double x, double y, double radius, double speed) {
	if (x >= NET_X2 + speed + radius  && x <= NET_X2  + radius && y <= NET_Y2) {
		return true;
	}
	else {
		return false;
	}
}


// Ball - Net (Tp[) Collision
bool Collision::ballLeftNetCollision(double x, double y, double radius, double speed) {
	if (x >= NET_X1- speed - radius && x <= NET_X1 - radius && y <= NET_Y2) {
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