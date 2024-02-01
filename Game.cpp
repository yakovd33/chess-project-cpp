#include "Game.h"

/*
constructor will construct the game
input:
	startTemplate- the starting template of the board, f.e - "rqPP##nK......"
output:
	none
*/
Game::Game(string startTemplate) : Board(startTemplate)
{
	this->_turn = startTemplate[START_COLOR]- LOWEST_COLOR;//the 65th char in the start template is the color of who is starting so to turn it to int we're just subbing the ascii value of 0.
}

/*
the deconstructor will deconstruct the game
input:
	none
output:
	none
*/
Game::~Game()
{
	//nothing to delete, Board already deleting his attributes
}

/*
function will make a move at the game board and will return the response code
input:
	moveStr- the move instruction, f.e - a3a6
output:
	the code response to the move
*/
int Game::makeMove(string moveStr)
{
	return move(Point(moveStr.substr(SOURCE_START, MOVE_LENGTH)), Point(moveStr.substr(DEST_START, MOVE_LENGTH)), this->_turn);//move(src,dest,turn)
}

/*
function will switch the turn
input:
	none
output:
	none
*/
void Game::switchTurn()
{
	this->_turn == WHITE ? this->_turn = BLACK : this->_turn = WHITE;
}
