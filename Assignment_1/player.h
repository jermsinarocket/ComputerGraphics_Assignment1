#ifndef PLAYER_H
#define PLAYER_H
#include "shapes.h"
#include "colour.h"
#include "text.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>


class Player
{
public:
	/** Default constructor */
	Player();
	void render();
	virtual ~Player();
	
protected:
private:
	int score;
};

#endif // PLAYER_H