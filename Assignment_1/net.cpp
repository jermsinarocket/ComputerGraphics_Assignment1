/**
 * @file net.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */



#include "net.h"


Net::Net() {
}


void Net::render() {

	//Create the Net
	Color color;
	color.setColor("000000");
	//Create the net
	glColor3f(SETCOLOR(color));
	glRectf(NET_X1, NET_Y1, NET_X2, NET_Y2);
	
	
}

Net::~Net(){

}