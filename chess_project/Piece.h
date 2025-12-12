#pragma once
#include<string>
#include <iostream>
#include "Board.h"


#define KING_TYPE 'K'
#define ROOK_TYPE 'R'
#define QUEEN_TYPE 'Q'
#define BISHOP_TYPE 'B'
#define PAWN_TYPE 'P'
#define KINGHT_TYPE 'N'
#define POSSIBLE_KNIGHT_MOVES 8

class Board;

class Piece
{
	protected:
		char type;
		int col;
		int row;
		bool is_black;


	public:
		//makes object
		Piece(int row, int col, char type, bool is_black);
		virtual ~Piece();

		int getRow() const;
		void setRow(int row);
		
		int getCol() const;
		void setCol(int col);

		bool getIs_black() const;
		char getType() const;
		
		//checks if there is a piece in the way to dst
		virtual bool isPathClear(Board* board, int destRow, int destCol) const = 0;

		//checks if the piece can move by the rules
		virtual bool isMoveValid(int destRow, int destCol) const = 0;

		



};
