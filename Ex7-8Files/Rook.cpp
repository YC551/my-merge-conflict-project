#include "Rook.h"
#include "King.h"

Rook::Rook(int row, int col, bool is_black):
	Piece(row,col, ROOK_TYPE, is_black)
{

}

Rook::~Rook()
{
	
}



bool Rook::isMoveValid(int destRow, int destCol) const
{
	//the rook moves in a straight line so only row or only col changes
	return (this->col == destCol) || (this->row == destRow);

}



bool Rook::isPathClear(const Board& board, int destRow, int destCol) const
{
	int i = 0;
	int change = 0;
	if (!(isMoveValid(destRow, destCol)))
	{
		return false;
	}


	//we check if we need to change the row
	if (this->col == destCol)
	{
		//we check if we move up or down
		if (this->row > destRow)
		{
			change = MOVE_DOWN;
		}
		else
		{
			change = MOVE_UP;
		}
		//we check if there isnt a piece in the path
		for (i = this->row + change; i != destRow; i += change)
		{
			if (board.getPieceFromArray(i, this->col) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else if (this->row == destRow)
	{
		if (this->col > destCol)
		{
			change = MOVE_LEFT;
		}
		else
		{
			change = MOVE_RIGHT;
		}
		//we check if there isnt a piece in the path
		for (i = this->col + change; i != destCol; i += change)
		{
			if (board.getPieceFromArray(this->row,i) != nullptr)
			{
				return false;
			}
		}
		return true;
	}


	return false;
}



