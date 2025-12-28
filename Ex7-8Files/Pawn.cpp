#include "Pawn.h"

Pawn::Pawn(int row, int col, bool is_black):
	Piece(row, col, PAWN_TYPE, is_black)
{

}

Pawn::~Pawn()
{

}

bool Pawn::isPathClear(const Board& board, int destRow, int destCol) const
{
	Piece* piece = board.getPieceFromArray(destRow, destCol);
	Queen queen(this->row, this->col, is_black);
	

	//we check if the move is possible for a pawn
	if (!isMoveValid(destRow, destCol))
	{
		return false;
	}

	//all the possible moves for a pawn are possible for a queen
	if (!(queen.isPathClear(board, destRow, destCol)))
	{
		return false;
	}
	
	//if the pawn goes forward make sure destination is clear because pawns cant eat straight
	if (this->col == destCol)
	{
		
		if (piece != nullptr)
		{
			return false;
		}
	}

	//if we move diagnoly we check if theres a piece with a diffrent color
	else
	{
		
		if(piece == nullptr)
		{
			return false;
		}

		if(piece->getIs_black() == this->is_black)
		{
			return false;
		}
	}


	return true;
	
	
}

bool Pawn::isMoveValid(int destRow, int destCol) const
{
	int difCol = abs(abs(this->col) - abs(destCol));
	int difRow = destRow - this->row;

	//if pawn is black the row diffrence is positive and if white its negative
	//we make the col diffrence positive if its white because white pawn can go from row 6 to 5 
	if (!(this->is_black))
	{
		//now if row diffrence is negative it will be illegal
		difRow *= -1;
	}
	
	

	//we check if the pawns make a move forward 1 place or 2 places
	if ((difCol == STAY_IN_ROW ) && ((difRow == MIN_ROW_CHANGE) || (difRow == MAX_ROW_CHANGE)))
	{
		//we check if the pawn moves 2 places
		if (difRow == MAX_ROW_CHANGE)
		{
			//we check if the pawn can move 2 places
			//we check if the pawns are at starting location
			if (this->is_black)
			{
				if (this->row != BLACK_FIRST_ROW)
				{
					return false;
				}
			}

			else
			{
				if (this->row != WHITE_FIRST_ROW)
				{
					return false;
				}
			}
		}

		return true;
		
	}
	

	//we check if the pawn goes diagnoly the right amount
	return (difCol == SHORT_MOVE_FORWARD) && (difRow == MIN_ROW_CHANGE);

}
