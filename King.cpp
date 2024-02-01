
#include "King.h"


/*
constructor will construct the king
input:
	place- the place of the king
	color- the color of the king
output:
	none
*/
King::King(Point place, int color) : Piece(place, color)
{
}

/*
deconstructor will deconstruct the king
input:
	none
output:
	none
*/
King::~King()
{
	//nothing to delete- the deconstructor of Piece will delete his attributes already(place,color) 
}

/*
function will check if the move(src to dest) is legal(if the king move legally)
input:
gameBoard- the game board
dest- the dest of the move
output:
ans- false if illegal, true if legal
*/
bool King::checkMove(Piece* gameBoard[GAME_BORDERS][GAME_BORDERS], Point dest)
{
	bool ans = true;
	int xDifference = POSITIVE(this->getPlace().getX() - dest.getX());
	int yDifference = POSITIVE(this->getPlace().getY() - dest.getY());
	//difference=POSITIVE(src.(x or y)-dest.(x or y))

	if (!((xDifference == ONE && yDifference == ZERO) || (yDifference == ONE && xDifference == ZERO) || (yDifference == ONE && xDifference == ONE)))
		//if the king moved illegally - the difference in x axis or y axis is bigger than 1.
	{
		ans = false;
	}

	return ans;
}

