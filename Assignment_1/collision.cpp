#include "collision.h"

Collision::Collision() {
	netLeftX = 705.0;
	netRightX = 745.0;
	windowLeftX = 0.;
	windowRightX = 1440.0;

}

bool Collision::leftNetCollision(double x) {
	if (x >= netLeftX) {
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
Collision::~Collision(){

}