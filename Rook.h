#pragma once
#include "Piece.h"
#define SKIP_SRC_ROOK 1
class Rook : public Piece
{
public:
	Rook(Point place, int color);
	~Rook();
	virtual bool checkMove(Piece* gameBoard[GAME_BORDERS][GAME_BORDERS], Point dest);
};