#pragma once

#include "Piece.h"
#define GO_UP 1
#define GO_DOWN -1
#define LEFT -1
#define RIGHT 1

class King : public Piece
{
	
		
	public:
		King(int row, int col, bool is_black);
		virtual ~King();

		//checks if there is a piece in the way to dst and the movnent is valid
		virtual bool isPathClear(Board* board, int destRow, int destCol) const;


		//checks if the piece can move by the rules
		virtual bool isMoveValid(int destRow, int destCol) const;

		//returns true if theres a check 
		bool isCheck(Board* board) const;
		//we go in straight lines around the king to see if theres a rook or a queen
		bool checkUpAndDown(Board* board, int change) const;
		bool checkRightAndLeft(Board* board, int change) const;

		

		//we go in a cross around the king to see if theres a bishop or a queen
		bool checkCross(Board* board, int changRow, int changCol) const;

};
