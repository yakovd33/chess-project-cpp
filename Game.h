#pragma once
#include <iostream>
#include "Board.h"
#define LOWEST_COLOR 48
#define START_COLOR 64
#define SOURCE_START 0
#define MOVE_LENGTH 2
#define DEST_START 2
class Game : public Board
{
public:
	Game(string startTemplate);
	~Game();
	int makeMove(string moveStr);
	void switchTurn();
private:
	int _turn;
};