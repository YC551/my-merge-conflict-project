#include "Board.h"


Board::~Board()
{
	int i = 0, j = 0;

	for (i = 0; i < CHESS_ROW_LEN; i++)
	{
		for (j = 0; j < CHESS_COL_LEN; j++)
		{
			if (this->pieces[i][j])
			{
				delete this->pieces[i][j];
			}
			this->pieces[i][j]; = nullptr;
		}
	}
}

void Board::changePieceLocation(std::string updateStr)
{
	
	std::string srcLocation = updateStr.substr(0, 2); //get first part
	std::string dstLocation = updateStr.substr(2, 2); //get second part

	//we get the src and destination for the array
	int srcRow = getRowFromString(srcLocation);
	int srcCol = getColFromString(srcLocation);

	int dstRow = getRowFromString(dstLocation);
	int dstCol = getColFromString(dstLocation);

	//we save the piece
	Piece* piece = this->pieces[ srcRow ][ srcCol ];

	//if theres a variable at the destination we need to free it
	if (this->pieces[dstRow][dstCol] != nullptr)
	{
		delete this->pieces[dstRow][dstCol];
	}

	
	//we update the array
	this->pieces[dstRow][dstCol] = piece;
	this->pieces[srcRow][srcCol] = nullptr;

	piece->setCol(dstCol);
	piece->setRow(dstRow);
	
	
	
}



int Board::getColFromString(std::string location)
{
	//turn letters to alphabet index 
	return location[ COL_INDEX ] - FIRST_ALPHABET_LETTER;
}

int Board::getRowFromString(std::string location)
{
	//turns '8' to 0, '7' to 1
	return CHESS_COL_LEN - (location[ ROW_INDEX ] - ZERO_CHAR);
}

Piece* Board::getPieceFromArray(int row, int col) const
{
	return this->pieces[ row ][ col ];
}
