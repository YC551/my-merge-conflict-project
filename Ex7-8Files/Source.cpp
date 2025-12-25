/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#define _CRT_SECURE_NO_WRNINGS
#include <iostream>
#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include "MoveValidator.h"
#include "Pipe.h"
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <chrono>
#include <cstring>

#define BOARD_STR "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0"

using std::cout;
using std::endl;
using std::string;

enum Column { A, B, C, D, E, F, G, H };
enum Row { R8, R7, R6, R5, R4, R3, R2, R1 };



int main()
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
			return 0;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy(msgToGraphics, BOARD_STR);
	
	#ifdef WIN32
		p.sendMessageToGraphics(msgToGraphics);   // send the board string
	#endif

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	//we make the board
	Board board;


	// black pieces
	board.pieces[R8][A] = new Rook(R8, A, true);  // a8
	board.pieces[R8][H] = new Rook(R8, H, true);  // h8
	board.pieces[R8][E] = new King(R8, E, true);  // e8
	board.pieces[R8][C] = new Bishop(R8, C, true);  // c8
	board.pieces[R8][F] = new Bishop(R8, F, true);  // f8
	board.pieces[R8][D] = new Queen(R8, D, true);  // d8
	board.pieces[R8][B] = new Knight(R8, B, true);  // b8
	board.pieces[R8][G] = new Knight(R8, G, true);  // g8

	// black pawns
	for (int col = A; col <= H; col++)
	{
		board.pieces[R7][col] = new Pawn(R7, col, true);
	}


	// white pieces
	board.pieces[R1][A] = new Rook(R1, A, false); // a1
	board.pieces[R1][H] = new Rook(R1, H, false); // h1
	board.pieces[R1][E] = new King(R1, E, false); // e1
	board.pieces[R1][C] = new Bishop(R1, C, false); // c1
	board.pieces[R1][F] = new Bishop(R1, F, false); // f1
	board.pieces[R1][D] = new Queen(R1, D, false); // d1
	board.pieces[R1][B] = new Knight(R1, B, false); // b1
	board.pieces[R1][G] = new Knight(R1, G, false); // g1

	// white pawns
	for (int col = A; col <= H; col++)
	{
		board.pieces[R2][col] = new Pawn(R2, col, false);
	}


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


	return 0;
}