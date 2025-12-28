#include "Knight.h"


Knight::Knight(int row, int col, bool is_black) :
	Piece(row, col, KNIGHT_TYPE, is_black)
{

}

Knight::~Knight()
{

}

bool Knight::isPathClear(const Board& board, int destRow, int destCol) const
{
	//the knight can go above anything so we dont need to check if the path is clear
	return isMoveValid(destRow, destCol);
}


bool Knight::isMoveValid(int destRow, int destCol) const
{
	//we find the diffrence in the col and row and check if they are valid
	int difCol = abs(abs(this->col) - abs(destCol));
	int difRow = abs(abs(this->row) - abs(destRow));

	//we check if one is big movement and the other is small movement
	if (difCol == BIG_MOVEMENT)
	{
		return (difRow == SMALL_MOVEMENT);
	}

	if (difRow == BIG_MOVEMENT)
	{
		return (difCol == SMALL_MOVEMENT);
	}


	return false;
}
