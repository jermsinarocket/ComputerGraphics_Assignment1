/**
 * @file controller.h
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "shapes.h"
#include "ball.h"
#include "ai.h"
#include "collision.h"
#include "background.h"
#include "net.h"
#include "soundcontroller.h"
#include "text.h"
#include "player.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>


#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
//Points to win
#define WINNING_POINTS 3


using namespace std;

class Controller
{
public:
	
	Controller();
	void renderStart();
	void renderBg();
	void renderWinScreen();
	void resetGame();
	void button();
	void clicked(float x, float y);

	bool gameRunning;
	bool gameOver;

	Background bg;
	Player player1;
	Ai ai;
	Ball ball;
	Collision ballCollision;

protected:
private:
	SoundController soundcontroller;


};

#endif // CONTROLLER_H