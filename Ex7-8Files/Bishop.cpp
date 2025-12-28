#include "Bishop.h"

Bishop::Bishop(int row, int col, bool is_black):
	Piece(row, col, BISHOP_TYPE, is_black)
{

}

Bishop::~Bishop()
{

}

bool Bishop::isPathClear(const Board& board, int destRow, int destCol) const
{
	if (!isMoveValid(destRow, destCol))
	{
		return false;
	}
	
	int rowOff = 0, colOff = 0, i = 0, j = 0;
	Piece* piece = nullptr;
	//we check if the offsets are positive or negetive
	if (destRow > this->row)
	{
		rowOff = MOVE_UP;
	}

	else
	{
		rowOff = MOVE_DOWN;
	}

	if (destCol > this->col)
	{
		colOff = MOVE_RIGHT;
	}

	else
	{
		colOff = MOVE_LEFT;
	}

	
	//we go in the direction to check if the path is empty
	for (i = this->row + rowOff, j = this->col + colOff; i != destRow && j != destCol; i += rowOff, j += colOff)
	{
		piece = board.getPieceFromArray(i, j);

		if (piece != nullptr)
		{
			return false;
		}

	}

	return true;
}

bool Bishop::isMoveValid(int destRow, int destCol) const
{
	int difRow = 0, difCol = 0;

	//we check the diffrence in the place of the bishop
	difCol = abs(abs(this->col) - abs(destCol));
	difRow = abs(abs(this->row) - abs(destRow));

	//we check if the diffrence is the  same
	return (difRow == difCol);
}


