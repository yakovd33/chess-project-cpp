#pragma once

#include "Piece.h"
#define POSITIVE(n) ((n) < 0 ? 0 - (n) : (n))
#define ONE 1
#define ZERO 0
class King : public Piece
{
public:
	King(Point place, int color);
	~King();
	virtual bool checkMove(Piece* gameBoard[GAME_BORDERS][GAME_BORDERS], Point dest);
};
