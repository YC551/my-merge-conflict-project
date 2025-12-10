#include "Rook.h"

Rook::Rook(int row, int cow, bool is_black):
	Piece(row,cow, ROOK_TYPE, is_black)
{

}

Rook::~Rook()
{
	
}

bool Rook::isPathClear(Board* board, int destRow, int destCol) const
{
	int i = 0;
	
	//we check if we need to change the row
	if(this->col == destCol)
	{
		//we check if we move up or down
		if (this->row > destRow)
		{
			//we check if there isnt a piece in the path
			for (i = this->row + 1; i < destRow; i++)
			{
				if (board->getPieceFromArray(this->col, i) != nullptr)
				{
					return false;
				}
			}

			return true;
		}

		//if we dont move up we go down
		else
		{
			//we check if there isnt a piece in the path
			for (i = this->row - 1; i > destRow; i--)
			{
				if (board->getPieceFromArray(this->col, i) != nullptr)
				{
					return false;
				}
			}

			return true;
		}
	}

	else
	{
		//we check if we move left or right
		if (this->col > destCol)
		{
			//we check if there isnt a piece in the path
			for (i = this->col + 1; i < destCol; i++)
			{
				if (board->getPieceFromArray(i, this->row) != nullptr)
				{
					return false;
				}
			}

			return true;
		}

		//if we dont move right we move left
		else
		{
			//we check if there isnt a piece in the path
			for (i = this->col - 1; i > destCol; i--)
			{
				if (board->getPieceFromArray(i, this->row) != nullptr)
				{
					return false;
				}
			}

			return true;
		}
	}


}


bool Rook::isMoveValid(int destRow, int destCol) const
{
	//the rook moves in a straight line so only row or only col changes
	if ((this->col == destCol) || (this->row == destRow))
	{
		return true;
	}

	return false;

}






