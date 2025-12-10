#pragma once
#include<string>
#include <iostream>
#include "Board.h"

class Board;

class Piece
{
	protected:
		char type;
		int col;
		int row;
		
		bool is_black;

	public:
		Piece(int row, int cow, char type, bool is_black);
		

		int getRow() const;
		void setRow(int row);
		
		int getCol() const;
		void setCol(int col);

		

		bool getIs_black() const;
		void setIs_black(bool is_black);

		char getType() const;
		void setType(char type);

		//checks if there is a piece in the way to dst
		virtual bool isPathClear(Board* board, int destRow, int destCol) const = 0;

		//checks if the piece can move by the rules
		virtual bool isMoveValid(int destRow, int destCol) const = 0;

		



};
