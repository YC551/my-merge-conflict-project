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
			this->pieces[i][j] = nullptr;
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

void Board::printBoard() const
{
	int col = 0, row = 0;
	
	//Print the column headers at the top
	std::cout << "  a b c d e f g h\n";

	// Loop through each row of the board
	for (row = 0; row < CHESS_ROW_LEN; row++)
	{
		//Print the row number on the left (8 to 1)
		std::cout << CHESS_ROW_LEN - row << " ";

		//Loop through each column in the current row
		for (col = 0; col < CHESS_COL_LEN; col++)
		{
			Piece* piece = this->pieces[ row ][ col ]; //Get the piece at this position

			//if there is a piece we print the type
			if (piece != nullptr)
				std::cout << piece->getType() << " ";
			else
				std::cout << " # "; //Print a # if the square is empty
		}

		//Print the row number on the right side
		std::cout << CHESS_ROW_LEN - row << "\n";
	}

	//Print the column headers again at the bottom
	std::cout << "  a b c d e f g h\n";

}
