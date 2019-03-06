#ifndef TEXT_H
#define TEXT_H
#include "shapes.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <string>
#include <cstring>
#include "colour.h"
#include <math.h>
#include <cstdlib>
using namespace std;

class Text
{
public:
	/** Default constructor */
	Text();
	void score(Color color, int score);
	void text(Color color, char st[]);
protected:
private:
};

#endif // TEXT_H