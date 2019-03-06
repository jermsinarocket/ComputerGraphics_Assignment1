#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "shapes.h"
#include "colour.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()


class Background
{
public:
	/** Default constructor */
	Background();
	void render();

	void sun();
	void cloud();

	/** Default destructor */
	virtual ~Background();
protected:
private:
};

#endif // BACKGROUND_H