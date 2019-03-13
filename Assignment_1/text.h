/**
 * @file text.h
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#ifndef TEXT_H
#define TEXT_H

#include "shapes.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <string>
#include <cstring>
#include <cstdlib>

#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()


using namespace std;

class Text
{
public:
	/** Default constructor */
	Text();
	void score(Color color, int score);
	void text(Color color, char st[]);
	void largeText(Color color, char st[]);
protected:
private:
};

#endif // TEXT_H