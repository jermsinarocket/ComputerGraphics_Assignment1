#ifndef COLOUR_H
#define COLOUR_H
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>

class Color
{
public:
	/** Default constructor */
	Color();
	/** Default destructor */
	virtual ~Color();

	/** Make Hex code to glut colorcode */
	void setColor(std::string colorCode);
	/** Access red
	 * \return The current value of red
	 */

	float Getred() { return red; }
	/** Access green
	 * \return The current value of green
	 */
	float Getgreen() { return green; }
	/** Access blue
	 * \return The current value of blue
	 */
	float Getblue() { return blue; }
protected:
private:
	float red; //!< Member variable "red"
	float green; //!< Member variable "green"
	float blue; //!< Member variable "blue"
};

#endif // COLOR_H