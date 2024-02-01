#pragma once
#include "Point.h"

#define GAME_BORDERS 8


class Piece
{
public:
	Piece(Point place, int color);
	~Piece();
	virtual bool checkMove(Piece* gameBoard[GAME_BORDERS][GAME_BORDERS], Point dst) = 0;
	int getColor();
	Point getPlace();
	void setPlace(int x, int y);
protected:
	Point* _place;
	int _color;
};