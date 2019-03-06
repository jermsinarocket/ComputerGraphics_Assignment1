#include "colour.h"


using namespace std;
Color::Color()
{
	//ctor
}

Color::~Color()
{
	//dtor
}

void Color::setColor(string colorCode)
{
	string colors = colorCode;
	string color;

	color = colors.substr(0, 2);


	stringstream sr;
	unsigned int r;
	sr << hex << color;
	sr >> r;

	color = colors.substr(2, 2);

	stringstream sg;
	unsigned int g;
	sg << hex << color;
	sg >> g;

	color = colors.substr(4, 2);

	stringstream sb(color);
	unsigned int b;
	sb << hex << color;
	sb >> b;


	red = (float)r / 255;
	green = (float)g / 255;
	blue = (float)b / 255;

}