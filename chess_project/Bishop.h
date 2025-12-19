#pragma once
#include "Piece.h"

class Bishop : public Piece
{
	public:
		Bishop(int row, int col, bool is_black);
		~Bishop() override;

		//checks if there is a piece in the way to dst and the movnent is valid
		bool isPathClear(const Board& board, int destRow, int destCol) const override;


		//checks if the piece can move by the rules
		bool isMoveValid(int destRow, int destCol) const override;


};

