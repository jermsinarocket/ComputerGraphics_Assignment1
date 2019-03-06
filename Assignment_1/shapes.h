#ifndef SHAPES_H
#define SHAPES_H
#include "colour.h"
class Shapes
{
public:
	/** Default constructor */
	Shapes();
	static void rect(Color);
	static void circle(Color);
	static void triangle(Color);
	static void octagon(Color);
	static void rectangle(double x1, double y1, double x2, double y2);
	/** Default destructor */
	virtual ~Shapes();
protected:
private:
};

#endif // SHAPES_H