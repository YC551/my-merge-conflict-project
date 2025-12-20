#pragma once
#include "Rook.h"
#include "Bishop.h"
#include "Piece.h"

class Queen : public Piece
{

	public:
		Queen(int row, int col, bool is_black);
		~Queen() override;

		//checks if there is a piece in the way to dst and the movnent is valid
		bool isPathClear(const Board& board, int destRow, int destCol) const override;


		//checks if the piece can move by the rules
		bool isMoveValid(int destRow, int destCol) const override;

};