#include "stdafx.h"
#include <iostream>
#include <thread>
#include <cstdlib> // for srand, rand
#include <ctime>   // for time
#include <string>
#include "Pipe.h"
#include "Game.h"
#define LOWEST_CODE 48
#define VALID '0'
#define VALID_CHESS '1'


void main()
{
	srand(time_t(NULL));

	string start = "r#######r#####K####r#############RRr######RR##k###rr###########R1";
	Pipe p;
	Game* game = 0;
	bool isConnect = p.connect();
	char answer[2] = { 0,0 };
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	game = new Game(start);//starting a new game with the starting string
	strcpy_s(msgToGraphics, start.c_str()); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

											  // get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		// YOUR CODE
		answer[0] = game->makeMove(msgFromGraphics)+LOWEST_CODE;//getting the response code, adding 48 in order to make it the ascii value to send it as char
		strcpy_s(msgToGraphics, answer); // msgToGraphics should contain the result of the operation
		if (answer[0] == VALID || answer[0] == VALID_CHESS)//if it was a valid move
		{
			game->switchTurn();
		}


										 // return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();

		
	}
	delete game;
	p.close();
}