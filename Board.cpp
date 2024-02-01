#include "Board.h"
/*
constructor will construct a board
input:
	startTemplate- the starting template, f.w("rqQpPbn##N...)
output:
	none
*/
Board::Board(string startTemplate)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <GAME_BORDERS; i++)
	{
		for (j = 0; j < GAME_BORDERS; j++)
		{
			switch (startTemplate[(i*GAME_BORDERS) + j])//for every y in the board the start template go up by 8(skipping all the x that were in the y before)
			{
			/*case BLACK_PAWN:
				this->_gameBoard[i][j] = new Pawn(Point(j, i), 1);
				break;
			case WHITE_PAWN:
				this->_gameBoard[i][j] = new Pawn(Point(j, i), 0);
				break;
			case BLACK_BISHOP:
				this->_gameBoard[i][j] = new Bishop(Point(j, i), 1);
				break;
			case WHITE_BISHOP:
				this->_gameBoard[i][j] = new Bishop(Point(j, i), 0);
				break;*/
			case BLACK_ROOK:
				this->_gameBoard[i][j] = new Rook(Point(j, i), BLACK);
				break;
			case WHITE_ROOK:
				this->_gameBoard[i][j] = new Rook(Point(j, i), WHITE);
				break;
			/*case BLACK_KNIGHT:
				this->_gameBoard[i][j] = new Knight(Point(j, i), 1);
				break;
			case WHITE_KNIGHT:
				this->_gameBoard[i][j] = new Knight(Point(j, i), 0);
				break;
			case BLACK_QUEEN:
				this->_gameBoard[i][j] = new Queen(Point(j, i), 1);
				break;
			case WHITE_QUEEN:
				this->_gameBoard[i][j] = new Queen(Point(j, i), 0);
				break;*/
			case BLACK_KING:
				this->_gameBoard[i][j] = new King(Point(j, i), BLACK);
				this->_blackKing = this->_gameBoard[i][j];
				break;
			case WHITE_KING:
				this->_gameBoard[i][j] = new King(Point(j, i), WHITE);
				this->_whiteKing = this->_gameBoard[i][j];
				break;
			case EMPTY:
				this->_gameBoard[i][j] = 0;
			default:
				break;
			}
		}
	}
}

/*
deconstructor will deconstruct the board
input:
	none
output:
	none
*/
Board::~Board()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < GAME_BORDERS; i++)
	{
		for (j = 0; j < GAME_BORDERS; j++)
		{
			delete this->_gameBoard[i][j];
		}
	}
}

/*
function will check if the source and the dest points are in the board indexes
input:
	src- the src point
	dest- the dest point
output:
	ans- true if legal, false if illegal
*/
bool Board::checkBounds(Point src, Point dest)
{
	bool ans = true;
	if (src.getX() > MAX_BORDER || src.getX() < MIN_BORDER || src.getY() > MAX_BORDER || src.getY() < MIN_BORDER || dest.getX()>MAX_BORDER || dest.getX() < MIN_BORDER || dest.getY() > MAX_BORDER || dest.getY() < MIN_BORDER)
	{
		ans = false;
	}
	return ans;
}


/*
function will check if its legal to move src to dest
input:
	src- the src of the move
	dest- the dest of the move
	turn- who's turn it is
output:
	the code response to the move
*/
int Board::move(Point src, Point dest, int turn)
{
	Piece* temp = 0;
	int ans = LEGAL_MOVE;
	if (checkBounds(src, dest))//if indexes are inside the borders
	{
		if (this->_gameBoard[src.getY()][src.getX()] && (this->_gameBoard[src.getY()][src.getX()])->getColor() == turn)//if the player that its his turn own the piece that in the src 
		{
			if (this->_gameBoard[dest.getY()][dest.getX()] && this->_gameBoard[dest.getY()][dest.getX()]->getColor() == turn)//if the piece that in the dest has the same color as the turn - (illegal)
			{
				ans = ILLEGAL_DEST;
			}
			else
			{
				if (src == dest)
				{
					ans = ILLEGAL_SRC_DEST_EQUAL;
				}
				else
				{
					if (this->_gameBoard[src.getY()][src.getX()]->checkMove(this->_gameBoard, dest))//if the move is legal by the piece type's movement
					{
						temp = this->_gameBoard[dest.getY()][dest.getX()];//saving what that in the dest so if there will be check on the player we can bring that piece back as it was
						this->_gameBoard[dest.getY()][dest.getX()] = this->_gameBoard[src.getY()][src.getX()];//board[dest]=board[src]
						this->_gameBoard[dest.getY()][dest.getX()]->setPlace(dest.getX(), dest.getY());//changing the piece place to the new place
						this->_gameBoard[src.getY()][src.getX()] = 0;
						if (checkCheck(turn==WHITE?BLACK:WHITE))//if the player has check on himself after the move
						{
							ans = ILLEGAL_CHESS;
							this->_gameBoard[src.getY()][src.getX()] = this->_gameBoard[dest.getY()][dest.getX()];//bringing src back to his place
							this->_gameBoard[src.getY()][src.getX()]->setPlace(src.getX(), src.getY());//changing source's place back 
							this->_gameBoard[dest.getY()][dest.getX()] = temp;//bringing dest back to his place
						}
						else
						{
							if (temp)
							{
								if (turn == WHITE)
								{
									if (this->_blackKing&&this->_blackKing->getPlace()==temp->getPlace())//if the piece that getting deleted is the black king
									{
										this->_blackKing = 0;//set it to 0 so when its being used in checkCheck the game wont crash.
									}
								}
								else
								{
									if (this->_whiteKing&&this->_whiteKing->getPlace() == temp->getPlace())//if the piece that getting deleted is the white king
									{
										this->_whiteKing = 0;//set it to 0 so when its being used in checkCheck the game wont crash.
									}
								}
							}
							delete temp;//delete what was in dest(got eaten or just empty)
							if (checkCheck(turn))//if the player made check on the opponent
							{
								ans = LEGAL_CHESS;
							}
						}
					}
					else
					{
						ans = ILLEGAL_MOVE;
					}
				}
			}
		}
		else
		{
			ans = ILLEGAL_SRC;
		}
	}
	else
	{
		ans = ILLEGAL_INDEX;
	}
	return ans;
}



/*
function will check if there is a check
input:
	turn- the player's turn(white/black)
output:
	ans- false if there is no check, true if there is
*/
bool Board::checkCheck(int turn)
{
	bool ans = false;
	Piece* temp = turn == WHITE ? this->_blackKing : this->_whiteKing;//setting the targeted king
	int i = 0;
	int j = 0;
	if (temp)//if the king is still alive
	{
		for (i = 0; i < GAME_BORDERS && ans == false; i++)
		{
			for (j = 0; j < GAME_BORDERS && ans == false; j++)
			{
				if (this->_gameBoard[i][j] && this->_gameBoard[i][j]->getColor() == turn)//if the player that its his turn own this piece
				{
					if (this->_gameBoard[i][j]->checkMove(this->_gameBoard, temp->getPlace()))//check if this piece can make a move on the king(if the piece can eat the king)
					{
						ans = true;
					}
				}

			}
		}
	}
	return ans;
}