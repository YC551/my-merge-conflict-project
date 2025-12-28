#include "King.h"



King::King(int row, int col, bool is_black):
	Piece(row, col, KING_TYPE, is_black)
{

}

King::~King()
{
	//theres nothing to free
}

//checks if there is a piece in the way to dst and the movnent is valid
bool King::isPathClear(const Board& board, int destRow, int destCol) const
{
	return isMoveValid(destRow, destCol);
}


//checks if the piece can move by the rules
bool King::isMoveValid(int destRow, int destCol) const
{
	//if dRow is positive we go up and if negative we go down
	int dRow = destRow - this->row;
	//if dCol is positive we go right if negative we go left
	int dCol = destCol - this->col;

	//the king can only move 1 place in every direction so we check the diffrence
	return (abs(dRow) <= 1) && (abs(dCol) <= 1);

	
}
