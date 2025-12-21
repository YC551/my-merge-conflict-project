#pragma once
#include "Piece.h"
#include "Queen.h"
#define BLACK_FIRST_ROW 1
#define WHITE_FIRST_ROW 6

#define STAY_IN_ROW 0
#define SHORT_MOVE_FORWARD 1
#define LONG_MOVE_FORWARD 2

#define MIN_ROW_CHANGE 1
#define MAX_ROW_CHANGE 2



class Pawn : public Piece
{
	public:
		Pawn(int row, int col, bool is_black);
		~Pawn() override;

		//checks if there is a piece in the way to dst and the movnent is valid
		bool isPathClear(const Board& board, int destRow, int destCol) const override;

		//checks if the piece can move by the rules
		bool isMoveValid(int destRow, int destCol) const override;
};
