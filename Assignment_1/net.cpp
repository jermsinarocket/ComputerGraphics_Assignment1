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