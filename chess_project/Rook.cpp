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
	if ((this->col == destCol) || (this->row == destRow))
	{
		return true;
	}

	return false;

}



bool Rook::isPathClear(const Board& board, int destRow, int destCol) const
{
	int i = 0;

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
			//we check if there isnt a piece in the path
			for (i = destRow + 1; i < this->row; i++)// start after destRow, go up to row-1
			{
				if (board.getPieceFromArray(i, this->col) != nullptr)
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
			for (i = this->row + 1; i < destRow; i++)// start after row, go up to destRow-1
			{
				if (board.getPieceFromArray(i, this->col) != nullptr)
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
			for (i = destCol + 1; i < this->col; i++)// start after destCol, go up to col-1
			{
				if (board.getPieceFromArray(this->row, i) != nullptr)
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
			for (i = this->col + 1; i < destCol; i++)// start after col, go up to destCol-1
			{
				if (board.getPieceFromArray(this->row, i) != nullptr)
				{
					return false;
				}
			}

			return true;
		}
	}


}



