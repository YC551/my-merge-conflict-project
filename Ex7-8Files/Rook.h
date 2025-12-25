#pragma once

#include "Piece.h"
#include "Board.h"



class Rook : public Piece
{
	public:
		//make object
		Rook(int row, int col, bool is_black);
		~Rook() override;

		//checks if there is a piece in the way to dst and the movnent is valid
		bool isPathClear(const Board& board, int destRow, int destCol) const override;


		//checks if the piece can move by the rules
		bool isMoveValid(int destRow, int destCol) const override;
		
		


};

