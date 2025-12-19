#include "Board.h"


Board::Board()
{
	for (int r = 0; r < CHESS_ROW_LEN; r++)
	{
		for (int c = 0; c < CHESS_COL_LEN; c++)
		{
			pieces[r][c] = nullptr;
		}
	}
}



Board::~Board()
{
	int i = 0, j = 0;

	for (i = 0; i < CHESS_ROW_LEN; i++)
	{
		for (j = 0; j < CHESS_COL_LEN; j++)
		{
			//we only free the place if there is a piece
			if (this->pieces[i][j] != nullptr)
			{
				delete this->pieces[i][j];
			}

			//we make the place on the board empty
			this->pieces[i][j] = nullptr;
		}
	}


}

void Board::changePieceLocation(std::string updateStr)
{
	int srcRow = 0, srcCol = 0, dstRow = 0, dstCol = 0;
	updateSrcDstFromString(updateStr, srcRow, srcCol, dstRow, dstCol);

	//we save the piece
	Piece* piece = this->pieces[srcRow][srcCol];

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
	return location[COL_INDEX] - FIRST_ALPHABET_LETTER;
}

int Board::getRowFromString(std::string location)
{
	//turns '8' to 0, '7' to 1
	return CHESS_COL_LEN - (location[ROW_INDEX] - ZERO_CHAR);
}

Piece* Board::getPieceFromArray(int row, int col) const
{
	return this->pieces[row][col];
}

void Board::printBoard() const
{
	std::cout << "  a b c d e f g h\n";

	for (int row = 0; row < CHESS_ROW_LEN; row++)
	{
		std::cout << CHESS_ROW_LEN - row << " ";

		for (int col = 0; col < CHESS_COL_LEN; col++)
		{
			Piece* piece = pieces[row][col];
			char symbol;

			if (piece != nullptr)
			{
				symbol = piece->getType();

				//if black print lower
				if (piece->getIs_black())
				{
					symbol = std::tolower(symbol);
				}
			}
			else
			{
				symbol = '#';
			}

			std::cout << symbol << " ";
		}

		std::cout << CHESS_ROW_LEN - row << "\n";
	}

	std::cout << "  a b c d e f g h\n";
}


Piece* Board::findKing(bool findBlack) const
{
	int i = 0, j = 0;
	Piece* piece = nullptr;

	for (i = 0; i < CHESS_ROW_LEN; i++)
	{
		for (j = 0; j < CHESS_COL_LEN; j++)
		{
			piece = this->getPieceFromArray(i, j);
			
			//we check if we reached a piece
			if (piece != nullptr)
			{
				//we check if the piece is a king from a diffrent color
				if ((piece->getIs_black() == findBlack) && piece->getType() == KING_TYPE)
				{
					return piece;
				}
			}
			
		}
	}

}

void Board::updateSrcDstFromString(std::string updateStr, int& srcRow, int& srcCol, int& dstRow, int& dstCol)
{
	std::string srcLocation = updateStr.substr(0, 2); //get first part
	std::string dstLocation = updateStr.substr(2, 2); //get second part

	//we get the src and destination for the array
	srcRow = getRowFromString(srcLocation);
	srcCol = getColFromString(srcLocation);

	dstRow = getRowFromString(dstLocation);
	dstCol = getColFromString(dstLocation);
}

