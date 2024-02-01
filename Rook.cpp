#include "Rook.h"

/*
constructor will construct the rook
input:
	place- the place of the rook
	color- the color of the rook
output:
	none
*/
Rook::Rook(Point place, int color) : Piece(place, color)
{
}

/*
deconstructor will deconstruct the rook
input:
	none
output:
	none
*/
Rook::~Rook()
{
	//nothing to delete- the deconstructor of Piece will delete his attributes already(place,color) 
}

/*
function will check if the move(src to dest) is legal(if the rook move legally and if there is a piece in his way)
input:
	gameBoard- the game board
	dest- the dest of the move
output:
	ans- false if illegal, true if legal
*/
bool Rook::checkMove(Piece* gameBoard[GAME_BORDERS][GAME_BORDERS], Point dest)
{
	int i = 0;
	bool ans = true;

	if (this->_place->getX() == dest.getX() || this->_place->getY() == dest.getY()) {//if the rook moved only in one axis(checking if src==dest outside this function so cant be both)
		//if it moved on the x axis
		if (this->_place->getX() < dest.getX())//if(src.x<dest.x)
		{
			for (i = this->_place->getX()+SKIP_SRC_ROOK; i < dest.getX() && ans == true; i++)//skipping one to skip the src piece(the rook)
			{//going through the rook path till the dest piece
				if (gameBoard[dest.getY()][i])//if there is a piece in the path of the rook till the dest piece(blocking the path)
				{
					ans = false;
				}
			}
		}
		else if(this->_place->getX() > dest.getX())//if(src.x>dest.x)
		{
			for (i = this->_place->getX()-SKIP_SRC_ROOK; i > dest.getX() && ans == true; i--)
			{
				if (gameBoard[dest.getY()][i])
				{
					ans = false;
				}
			}
		}
		//if it moved on the y axis
		if (this->_place->getY() < dest.getY())//if(src.y<dest.y)
		{
			for (i = this->_place->getY()+SKIP_SRC_ROOK; i < dest.getY() && ans == true; i++)
			{
				if (gameBoard[i][dest.getX()])
				{
					ans = false;
				}
			}
		}
		else if(this->_place->getY() > dest.getY())//if(src.y>dest.y)
		{
			for (i = this->_place->getY()-SKIP_SRC_ROOK; i > dest.getY() && ans == true; i--)
			{
				if (gameBoard[i][dest.getX()])
				{
					ans = false;
				}
			}
		}
	}
	else
	{
		ans = false;
	}
	return ans;
}
