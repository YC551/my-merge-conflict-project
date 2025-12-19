/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/
#include <iostream>
#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "MoveValidator.h"
#include "Pipe.h"
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));
	bool isBlackTurn = false;
	int srcRow = 0, dstRow = 0, srcCol = 0, dstCol = 0, code = 0;
	std::string srcLocation = "", dstLocation = "";
	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
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

	strcpy_s(msgToGraphics, "r###k##r################################################R###K##R0"); 
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	//we make the board
	Board board;


	// black pices
	board.pieces[0][0] = new Rook(0, 0, true);  // a8 - black rook
	board.pieces[0][7] = new Rook(0, 7, true);  // h8 - black rook
	board.pieces[0][4] = new King(0, 4, true);  // d8 - black king



	// white pices
	board.pieces[7][0] = new Rook(7, 0, false);   // a1 - white rook
	board.pieces[7][7] = new Rook(7, 7, false);   // h1 - white rook
	board.pieces[7][4] = new King(7, 4, false);   // d1 - white king

	while (msgFromGraphics != "quit")
	{
		//update Src param  and Dst param From String
		board.updateSrcDstFromString(msgFromGraphics, srcRow, srcCol, dstRow, dstCol);

		//get code to return the front
		code = MoveValidator::validateMove(board, srcRow, srcCol, dstRow, dstCol, isBlackTurn);
		
		//we check if a valid turn was made and if not we dont change anything
		if ((code == ERROR_0) || (code == ERROR_1))
		{
			//if a valid turn was made we change the turn to the other player and change the board array
			isBlackTurn = !isBlackTurn;

			board.changePieceLocation(msgFromGraphics);
		}

		msgToGraphics[0] = (char)(code + '0');
		msgToGraphics[1] = 0;
		
		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();

	}

	p.close();
}