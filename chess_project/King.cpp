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
bool King::isPathClear(Board* board, int destRow, int destCol) const
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
	if ((abs(dRow) <= 1) && (abs(dCol) <= 1))
	{
		return true;
	}

	return false;

	
}

bool King::isCheck(Board* board) const
{
	//we go in lines from the king to see if we reach a rook, queen or a bishop
	//we go around the king and check if theres a knight
	
	//we check up 
	if (checkUpAndDown(board, GO_UP))
	{
		return true; //true if theres a check
	}

	//we check down
	if (checkUpAndDown(board, GO_DOWN))
	{
		return true; //true if theres a check
	}


	//we check right
	if (checkRightAndLeft(board, RIGHT))
	{
		return true; //true if theres a check
	}

	//we check left
	if (checkRightAndLeft(board, LEFT))
	{
		return true; //true if theres a check
	}


	//we check up right
	if (checkCross(board, -1, 1))
	{
		return true;
	}

	//we checl up left
	if (checkCross(board, -1, -1))
	{
		return true;
	}

	//we check down right
	if (checkCross(board, 1, 1))
	{
		return true;
	}


	//we check down left
	if (checkCross(board, 1, -1))
	{
		return true;
	}


	return false;

}


bool King::checkUpAndDown(Board* board, int change) const
{
	int i = 0;
	Piece* piece = nullptr;

	//we go down and look for rook or queen
	for (i = this->row + change; i < CHESS_ROW_LEN && i >= 0; i += change)
	{
		piece = board->getPieceFromArray(i, this->col);

		//we check if we reached a piece
		if (piece != nullptr )
		{
			//we check if the closest piece is a diffrent color
			if (this->is_black != piece->getIs_black())
			{
				//we check if the closest piece is a rook or a queen
				if (piece->getType() == ROOK_TYPE || piece->getType() == QUEEN_TYPE)
				{
					return true;
				}
			}

			//if the closest piece is the same type we stop the check
			else
			{
				return false;
			}
		}
		
		
	}

	//if there are only nulls we return false
	return false;


}

bool King::checkRightAndLeft(Board* board, int change) const
{
	int i = 0;
	Piece* piece = nullptr;

	//we go down and look for rook or queen
	for (i = this->col + change; i < CHESS_COL_LEN && i >= 0; i += change)
	{
		piece = board->getPieceFromArray(this->row, i);

		//we check if we reached a piece
		if (piece != nullptr)
		{
			//we check if the closest piece is a diffrent color
			if (this->is_black != piece->getIs_black())
			{
				//we check if the closest piece is a rook or a queen
				if (piece->getType() == ROOK_TYPE || piece->getType() == QUEEN_TYPE)
				{
					return true;
				}
			}

			//if the closest piece is the same type we stop the check
			else
			{
				return false;
			}
		}


	}

	//if there are only nulls we return false
	return false;
}

bool King::checkCross(Board* board, int changeRow, int changeCol) const
{
	bool firstStep = true;
	int i = 0, j = 0;
	Piece* piece = nullptr;

	//i will be the rows and j will be the cols
	//we add the change to them and make sure they are still in valid range
	for (i = this->row + changeRow, j = this->col + changeCol; (i >= 0 && i < CHESS_ROW_LEN) && (j >= 0 && j < CHESS_COL_LEN); i += changeRow, j += changeCol)
	{
		//we go to the next place in the array
		piece = board->getPieceFromArray(i, j);

		//we check if we reached a piece
		if (piece != nullptr)
		{
			//we check if we reached a piece with a diffrent color
			if (piece->getIs_black() != this->is_black)
			{
				//we check if we are on the first loop
				if (firstStep)
				{
					firstStep = false;
					//we check if the piece is a pawn
					if (piece->getType() == PAWN_TYPE)
					{
						//we check which way the pawn is going
						if ((this->is_black && changeRow == -1) || ( !(this->is_black) && changeRow == 1))
						{
							return true;
						}
					}
				}

				if (piece->getType() == QUEEN_TYPE || piece->getType() == BISHOP_TYPE)
				{
					return true;
				}

			}

			else
			{
				return false;
			}
			
			
		}

		
	}

	//if there are only nulls we return false
	return false;
}
