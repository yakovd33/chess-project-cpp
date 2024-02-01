#pragma once
#include <iostream>
#include "Rook.h"
#include "King.h"

#define WHITE_KING 'K'
#define BLACK_KING 'k'
#define WHITE_ROOK 'R'
#define BLACK_ROOK 'r'
#define WHITE_QUEEN 'Q'
#define BLACK_QUEEN 'q'
#define WHITE_BISHOP 'B'
#define BLACK_BISHOP 'b'
#define WHITE_PAWN 'P'
#define BLACK_PAWN 'p'
#define WHITE_KNIGHT 'N'
#define BLACK_KNIGHT 'n'
#define EMPTY '#'

#define BLACK 1
#define WHITE 0

#define MAX_BORDER 7
#define MIN_BORDER 0

#define LEGAL_MOVE 0
#define LEGAL_CHESS 1
#define ILLEGAL_SRC 2
#define ILLEGAL_DEST 3
#define ILLEGAL_CHESS 4
#define ILLEGAL_INDEX 5
#define ILLEGAL_MOVE 6
#define ILLEGAL_SRC_DEST_EQUAL 7



class Board {
public:
	Board(string startTemplate);
	~Board();
	bool checkCheck(int turn);
	bool checkBounds(Point src, Point dest);
	int move(Point src, Point dest, int turn);
private:
	Piece* _whiteKing;
	Piece* _blackKing;
protected:
	Piece* _gameBoard[GAME_BORDERS][GAME_BORDERS];
};