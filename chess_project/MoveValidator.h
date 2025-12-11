#pragma once
#include "Board.h"
#include "King.h"
#include "Rook.h"
#include "Piece.h"

class MoveValidator
{
	public:	
		//returns true if theres a check on the king that matches blackturn 
		bool isCheck(Board* board, bool blackTurn) const;
		//we go in straight lines around the king to see if theres a rook or a queen
		bool checkUpAndDown(Board* board, int change, bool blackTurn) const;
		bool checkRightAndLeft(Board* board, int change, bool blackTurn) const;

		//we go in a cross around the king to see if theres a bishop or a queen
		bool checkCross(Board* board, int changRow, int changCol, bool blackTurn) const;

};
