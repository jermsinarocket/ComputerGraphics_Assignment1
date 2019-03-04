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
	/** Default destructor */
	virtual ~Shapes();
protected:
private:
};

#endif // SHAPES_H