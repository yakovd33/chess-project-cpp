#include "Point.h"

/*
constructor will construct point by a string of the place, f.e - a2
input:
	place- the string of the place of the point, f.e - a2
output:
	none
*/
Point::Point(string place)
{
	this->_x = place[X] - FIRST_X;
	this->_y = MAX_Y-(place[Y] - FIRST_Y);//the frontend board's y is upside down(starting from '8') so wer'e reversing it. 
}

/*
constructor will construct a point by another point
input:
	other- the other point
output:
	none
*/
Point::Point(const Point& other)
{
	this->_x = other._x;
	this->_y = other._y;
}

/*
constructor will construct a point by integer places f.e - (0,1)
input:
	x- the x place
	y- the y place
output:
	none
*/
Point::Point(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

/*
deconstructor will deconstruct the point
input:
	none
output:
	none
*/
Point::~Point() {
	//nothing to delete
}

/*
function will check if 2 points are equal
input:
	other- the other point
output:
	ans- false if not equal, true if equal.
*/
bool Point::operator==(Point other)
{
	bool ans = false;
	if (this->_x == other._x&&this->_y == other._y)
	{
		ans = true;
	}
	return ans;
}

/*
function will get the x of the point
input:
	none
output:
	the x of the point
*/
int Point::getX()
{
	return this->_x;
}

/*
function will get the y of the point
input:
	none
output:
	the y of the point
*/
int Point::getY()
{
	return this->_y;
}

/*
function will set the x of the point to a new x
input:
	x- the new x of the point
output:
	none
*/
void Point::setX(int x)
{
	this->_x = x;
}

/*
function will set the y of the point to a new y
input:
	y- the new y of the point
output:
	none
*/
void Point::setY(int y)
{
	this->_y = y;
}
