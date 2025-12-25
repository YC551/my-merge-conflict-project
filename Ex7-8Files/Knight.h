#pragma once
#include "Piece.h"
#define BIG_MOVEMENT 2
#define SMALL_MOVEMENT 1

class Knight : public Piece
{
	public:
	
		Knight(int row, int col, bool is_black);
		~Knight() override;

		//checks if there is a piece in the way to dst and the movnent is valid
		bool isPathClear(const Board& board, int destRow, int destCol) const override;

		//checks if the piece can move by the rules
		bool isMoveValid(int destRow, int destCol) const override;
};
