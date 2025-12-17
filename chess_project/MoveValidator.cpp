#include "MoveValidator.h"


int MoveValidator::validateMove(Board& board, int srcRow, int srcCol, int destRow, int destCol, bool currentPlayerBlack)
{
	
	if (areIndexOutOfBounds(srcRow, srcCol) || areIndexOutOfBounds(destRow, destCol))
	{
		return ERROR_5; //if the indexes are not valid
	}
	if (isSourceEmptyOrWrongColor(board, srcRow, srcCol, currentPlayerBlack))
	{
		return ERROR_2; //if the piece we want to move is a diffrent color
	}


	if (isSourceEqualDestination(srcRow, srcCol, destRow, destCol))
	{
		return ERROR_7; //if the piece didnt move
	}

	if (isDestinationOccupiedByPlayer(board, destRow, destCol, currentPlayerBlack))
	{
		return ERROR_3; //if the place we go to has a piece with the same color
	}

	if (isPieceMoveInvalid(board, srcRow, srcCol, destRow, destCol))
	{
		return ERROR_6; //if the path is not clear or if the piece moves in a invalid way
	}



	if(makesCheck(board, srcRow, srcCol, destRow, destCol, currentPlayerBlack))
	{
		return ERROR_4; //if the move gives the player a self check
	}


	//if the move is valid we see if it makes a check on the other player
	if (makesCheck(board, srcRow, srcCol, destRow, destCol, !currentPlayerBlack))
	{
		return ERROR_1; //if the other player is checked
	}


	//if the move is valid and didnt check the other player 
	return ERROR_0;



}

bool MoveValidator::isSourceEmptyOrWrongColor(const Board& board, int srcRow, int srcCol, bool currentPlayerBlack)
{
	Piece* piece = board.getPieceFromArray(srcRow, srcCol);

	if (piece != nullptr)
	{
		if (piece->getIs_black() == currentPlayerBlack)
		{
			return false;
		}
	}

	//if the piece we want to move has the same color we return true
	return true;
}

bool MoveValidator::isDestinationOccupiedByPlayer(const Board& board, int destRow, int destCol, bool currentPlayerBlack)
{
	Piece* piece = board.getPieceFromArray(destRow, destCol);

	//we check if there is a piece
	if (piece == nullptr)
	{
		return false;
	}

	//we check if the piece is the same color
	if (piece->getIs_black() != currentPlayerBlack)
	{
		return false;
	}
	
	//if theres a piece with the same color we return true
	return true;


}

bool MoveValidator::makesCheck(Board& board, int srcRow, int srcCol, int destRow, int destCol, bool currentPlayerBlack)
{
	//we get the piece at the destination and at the source
	Piece* tempDesPiece = board.getPieceFromArray(destRow, destCol);
	Piece* srcPiece = board.getPieceFromArray(srcRow, srcCol);
	bool checkHappened = false;

	//update current source piece and array tempereroly
	srcPiece->setCol(destCol);
	srcPiece->setRow(destRow);
	board.pieces[ srcRow ][ srcCol ] = nullptr;
	board.pieces[ destRow ][ destCol ] = srcPiece;

	//we see if the current player is checked
	checkHappened = isCheck(board, currentPlayerBlack);

	//we revert the move to the piece and reset the array
	srcPiece->setCol(srcCol);
	srcPiece->setRow(srcRow);
	board.pieces[ srcRow][ srcCol ] = srcPiece;
	board.pieces[ destRow ][ destCol ] = tempDesPiece;

	return checkHappened;

}

bool MoveValidator::areIndexOutOfBounds(int row, int col)
{
	if (row < 0 || row >= CHESS_ROW_LEN)
	{
		return true;
	}

	if (col < 0 || col >= CHESS_COL_LEN)
	{
		return true;
	}
	
	//if col or row is not valid
	return false;
}

bool MoveValidator::isPieceMoveInvalid(const Board& board, int srcRow, int srcCol, int destRow, int destCol)
{
	Piece* piece = board.getPieceFromArray(srcRow, srcCol);

	return !piece->isPathClear(board, destRow, destCol);
}

bool MoveValidator::isSourceEqualDestination(int srcRow, int srcCol, int destRow, int destCol)
{
	if (destRow == srcRow && destCol == srcCol)
	{
		return true;
	}

	return false;

}


bool MoveValidator::isCheck(const Board& board, bool blackTurn)
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


bool MoveValidator::checkUpAndDown(const Board& board, int change, bool blackTurn) 
{
	int i = 0;
	bool firstStep = true;
	Piece* piece = nullptr;
	Piece* king = board.findKing(blackTurn);

	//we go down and look for rook or queen
	for (i = king->getRow() + change; i < CHESS_ROW_LEN && i >= 0; i += change)
	{
		piece = board.getPieceFromArray(i, king->getCol());

		//we check if we reached a piece
		if (piece != nullptr)
		{
			//we check if the closest piece is a diffrent color
			if (king->getIs_black() != piece->getIs_black())
			{
				
				//we check if the closest piece is a rook or a queen
				if (piece->getType() == ROOK_TYPE || piece->getType() == QUEEN_TYPE || (firstStep && piece->getType() == KING_TYPE))
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

		firstStep = false;

	}

	//if there are only nulls we return false
	return false;


}


bool MoveValidator::checkRightAndLeft(const Board& board, int change, bool blackTurn) 
{
	int i = 0;
	bool firstStep = true;
	Piece* piece = nullptr;
	Piece* king = board.findKing(blackTurn);

	//we go down and look for rook or queen
	for (i = king->getCol() + change; i < CHESS_COL_LEN && i >= 0; i += change)
	{
		piece = board.getPieceFromArray(king->getRow(), i);

		//we check if we reached a piece
		if (piece != nullptr)
		{
			//we check if the closest piece is a diffrent color
			if (king->getIs_black() != piece->getIs_black())
			{
				//we check if the closest piece is a rook or a queen
				if (piece->getType() == ROOK_TYPE || piece->getType() == QUEEN_TYPE || (firstStep && piece->getType() == KING_TYPE))
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

		firstStep = false;

	}

	//if there are only nulls we return false
	return false;
}


bool MoveValidator::checkCross(const Board& board, int changeRow, int changeCol, bool blackTurn) 
{
	bool firstStep = true;
	int i = 0, j = 0;
	Piece* piece = nullptr;
	Piece* king = board.findKing(blackTurn);

	//i will be the rows and j will be the cols
	//we add the change to them and make sure they are still in valid range
	for (i = king->getRow() + changeRow, j = king->getCol() + changeCol; (i >= 0 && i < CHESS_ROW_LEN) && (j >= 0 && j < CHESS_COL_LEN); i += changeRow, j += changeCol)
	{
		//we go to the next place in the array
		piece = board.getPieceFromArray(i, j);

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
					//we check if the piece is a pawn or a king
					if (piece->getType() == PAWN_TYPE)
					{
						
						//we check which way the pawn is going
						if ((king->getIs_black() && changeRow == -1) || (!(king->getIs_black()) && changeRow == 1))
						{
							return true;
						}
					}

					if (piece->getType() ==  KING_TYPE)
					{
						return true;
					}
				}  

				if (piece->getType() == QUEEN_TYPE || piece->getType() == BISHOP_TYPE )
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


bool MoveValidator::checkKnight(const Board& board, bool blackTurn) 
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
	Piece* king = board.findKing(blackTurn);
	int i = 0, rowOffset = 0, colOffset = 0;

	//we go through the array and get the index of a posaible knight
	for (i = 0; i < POSSIBLE_KNIGHT_MOVES; i++)
	{
		rowOffset = king->getRow() + moves[ i ][ 0 ];
		colOffset = king->getCol() + moves[ i ] [ 1 ];

		//we check if the index is in range
		if ((rowOffset >= 0 && rowOffset < CHESS_ROW_LEN) && (colOffset >= 0 && colOffset < CHESS_COL_LEN))
		{
			piece = board.getPieceFromArray(rowOffset, colOffset);

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
