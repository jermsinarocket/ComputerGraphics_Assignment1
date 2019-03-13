/**
 * @file net.h
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#ifndef NET_H
#define NET_H

#include "colour.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>

#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
#define NET_X1  -0.05
#define NET_X2  0.05
#define NET_Y1  -1
#define NET_Y2  0.4

class Net {

public:
	Net();
	void render();
	virtual ~Net();

private:
	double netX1;
	double netY1;
	double netX2;
	double netY2;
protected:
};

#endif // NET_H