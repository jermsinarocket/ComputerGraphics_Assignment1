/**
 * @file colour.h
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */



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