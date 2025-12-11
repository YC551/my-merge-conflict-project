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

		

		

		

};
