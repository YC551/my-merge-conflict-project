#pragma once

#include "Piece.h"
#include "Board.h"



class Rook : public Piece
{
	public:
		//make object
		Rook(int row, int col, bool is_black);
		virtual ~Rook();

		//checks if there is a piece in the way to dst and the movnent is valid
		virtual bool isPathClear(Board* board, int destRow, int destCol) const;


		//checks if the piece can move by the rules
		virtual bool isMoveValid(int destRow, int destCol) const;
		
		


};

