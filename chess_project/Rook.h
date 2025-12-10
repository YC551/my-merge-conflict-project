#pragma once

#include "Piece.h"
#include "Board.h"
#define ROOK_TYPE 'R'


class Rook : public Piece
{
	public:
		//make object
		Rook(int row, int cow, bool is_black);
		virtual ~Rook();

		//checks if there is a piece in the way to dst and the movnent is valid
		virtual bool isPathClear(Board* board, int destRow, int destCol) const;


		//checks if the piece can move by the rules
		virtual bool isMoveValid(int destRow, int destCol) const;
		
		


};

