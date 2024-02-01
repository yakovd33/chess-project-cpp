#include "Piece.h"

/*
constructor will construct a Piece
input:
	place- the place of the piece
	color- the color of the piece
output:
	none
*/
Piece::Piece(Point place, int color)
{
	this->_place = new Point(place);
	this->_color = color;
}


/*
deconstructor will deconstruct the piece
input:
	none
output:
	none
*/
Piece::~Piece()
{
	delete this->_place;
}

/*
function will get the color of the piece
input:
	none
output:
	the color of the piece
*/
int Piece::getColor()
{
	return this->_color;
}

/*
function will get the place of the piece
input:
	none
output:
	the place of the piece
*/
Point Piece::getPlace()
{
	return *(this->_place);
}

/*
function will set the place of the piece to a new point
input:
	x- the x of the new point
	y- the y of the new point
output:
	none
*/
void Piece::setPlace(int x, int y)
{
	this->_place->setX(x);
	this->_place->setY(y);
}