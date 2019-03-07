#include "collision.h"

Collision::Collision() {
	netLeftX = 705.0;
	netRightX = 745.0;
	netHeight = 400.0;
	windowLeftX = 0.;
	windowRightX = 1440.0;
	windowBottomX = 0;
	windowTopX = 800;

}

bool Collision::leftNetCollision(double x) {
	if (x >= netLeftX) {
		return true;
	}
	else {
	    return false;
	}
}

bool Collision::rightNetCollision(double x) {
	if (x <= netRightX) {
		return true;
	}
	else {
		return false;
	}
}


bool Collision::rightWindowCollision(double x) {
	if (x >= windowRightX) {
		return true;
	}
	else {
		return false;
	}
}

bool Collision::leftWindowCollision(double x) {
	if (x <= windowLeftX) {
		return true;
	}
	else {
		return false;
	}
}



bool Collision::ballLeftWindowCollision(double x,double radius) {
	if (x < windowLeftX+radius) {
		return true;
	}
	else {
		return false;
	}
}

bool Collision::ballRightWindowCollision(double x, double radius) {
	if (x > windowRightX-radius) {
		return true;
	}
	else {
		return false;
	}
}

bool Collision::ballTopWindowCollision(double y, double radius) {
	if (y > windowTopX - radius) {
		return true;
	}
	else {
		return false;
	}
}

bool Collision::ballBottomWindowCollision(double y, double radius) {
	if (y < windowBottomX + radius) {
		return true;
	}
	else {
		return false;
	}
}

bool Collision::ballRightNetCollision(double x, double y, double radius, double speed) {
	if (x >= netRightX + speed + radius  && x <= netRightX  + radius && y <= netHeight) {
		return true;
	}
	else {
		return false;
	}
}


bool Collision::ballLeftNetCollision(double x, double y, double radius, double speed) {
	if (x >= netLeftX- speed - radius && x <= netLeftX - radius && y <= netHeight) {
		return true;
	}
	else {
		return false;
	}
}



Collision::~Collision(){

}