#pragma once

#include <string>
#include <iostream>
#include "Piece.h"
#define FIRST_ALPHABET_LETTER 'a'
#define ZERO_CHAR '0'
#define COL_INDEX 0
#define ROW_INDEX 1
#define CHESS_COL_LEN 8
#define CHESS_ROW_LEN 8


class Piece;

class Board
{
	public:
		Piece* pieces[ CHESS_ROW_LEN ][ CHESS_COL_LEN ];
		~Board();

	//update piece and array
	void changePieceLocation(std::string updateStr);

	//get place on chess board and return col or row
	static int getColFromString(std::string location);
	static int getRowFromString(std::string location);

	
	//returns pointer to a piece from array
	Piece* getPieceFromArray(int row, int col) const;



};
