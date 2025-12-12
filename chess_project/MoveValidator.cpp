#include "MoveValidator.h"


bool MoveValidator::isCheck(Board* board, bool blackTurn) const
{
	//we go in lines from the king to see if we reach a rook, queen or a bishop
	//we go around the king and check if theres a knight

	//we check up 
	if (checkUpAndDown(board, GO_UP, blackTurn))
	{
		return true; //true if theres a check
	}

	//we check down
	if (checkUpAndDown(board, GO_DOWN, blackTurn))
	{
		return true; //true if theres a check
	}


	//we check right
	if (checkRightAndLeft(board, RIGHT, blackTurn))
	{
		return true; //true if theres a check
	}

	//we check left
	if (checkRightAndLeft(board, LEFT, blackTurn))
	{
		return true; //true if theres a check
	}


	//we check up right
	if (checkCross(board, -1, 1, blackTurn))
	{
		return true;
	}

	//we checl up left
	if (checkCross(board, -1, -1, blackTurn))
	{
		return true;
	}

	//we check down right
	if (checkCross(board, 1, 1, blackTurn))
	{
		return true;
	}


	//we check down left
	if (checkCross(board, 1, -1, blackTurn))
	{
		return true;
	}

	if (checkKnight(board, blackTurn))
	{
		return true;
	}

	return false;

}


bool MoveValidator::checkUpAndDown(Board* board, int change, bool blackTurn) const
{
	int i = 0;
	Piece* piece = nullptr;
	Piece* king = board->findKing(blackTurn);

	//we go down and look for rook or queen
	for (i = king->getRow() + change; i < CHESS_ROW_LEN && i >= 0; i += change)
	{
		piece = board->getPieceFromArray(i, king->getCol());

		//we check if we reached a piece
		if (piece != nullptr)
		{
			//we check if the closest piece is a diffrent color
			if (king->getIs_black() != piece->getIs_black())
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

bool MoveValidator::checkRightAndLeft(Board* board, int change, bool blackTurn) const
{
	int i = 0;
	Piece* piece = nullptr;
	Piece* king = board->findKing(blackTurn);

	//we go down and look for rook or queen
	for (i = king->getCol() + change; i < CHESS_COL_LEN && i >= 0; i += change)
	{
		piece = board->getPieceFromArray(king->getRow(), i);

		//we check if we reached a piece
		if (piece != nullptr)
		{
			//we check if the closest piece is a diffrent color
			if (king->getIs_black() != piece->getIs_black())
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

bool MoveValidator::checkCross(Board* board, int changeRow, int changeCol, bool blackTurn) const
{
	bool firstStep = true;
	int i = 0, j = 0;
	Piece* piece = nullptr;
	Piece* king = board->findKing(blackTurn);

	//i will be the rows and j will be the cols
	//we add the change to them and make sure they are still in valid range
	for (i = king->getRow() + changeRow, j = king->getCol() + changeCol; (i >= 0 && i < CHESS_ROW_LEN) && (j >= 0 && j < CHESS_COL_LEN); i += changeRow, j += changeCol)
	{
		//we go to the next place in the array
		piece = board->getPieceFromArray(i, j);

		//we check if we reached a piece
		if (piece != nullptr)
		{
			//we check if we reached a piece with a diffrent color
			if (piece->getIs_black() != king->getIs_black())
			{
				//we check if we are on the first loop
				if (firstStep)
				{
					firstStep = false;
					//we check if the piece is a pawn
					if (piece->getType() == PAWN_TYPE)
					{
						//we check which way the pawn is going
						if ((king->getIs_black() && changeRow == -1) || (!(king->getIs_black()) && changeRow == 1))
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



bool MoveValidator::checkKnight(Board* board, bool blackTurn) const
{
	//we make an array with all the possible places a kingt can check the king
	int moves[ POSSIBLE_KNIGHT_MOVES ][ 2 ] =
	{
		//up right and left
		{  2,  1 }, {  2, -1 },
		//down right and left
		{ -2,  1 }, { -2, -1 },
		//right and left up
		{  1,  2 }, {  1, -2 },
		//right and left down
		{ -1,  2 }, { -1, -2 }
	};


	Piece* piece = nullptr;
	Piece* king = board->findKing(blackTurn);
	int i = 0, rowOffset = 0, colOffset = 0;

	//we go through the array and get the index of a posaible knight
	for (i = 0; i < POSSIBLE_KNIGHT_MOVES; i++)
	{
		rowOffset = king->getRow() + moves[ i ][ 0 ];
		colOffset = king->getCol() + moves[ i ] [ 1 ];

		//we check if the index is in range
		if ((rowOffset >= 0 && rowOffset < CHESS_ROW_LEN) && (colOffset >= 0 && colOffset < CHESS_COL_LEN))
		{
			piece = board->getPieceFromArray(rowOffset, colOffset);

			//we check if we reached a piece
			if (piece != nullptr)
			{
				//we check if we reached a knight with a diffrent color
				if (piece->getType() == KNIGHT_TYPE && piece->getIs_black() != king->getIs_black())
				{
					return true;
				}
			}
		}
	}
		


	return false;
	


}
