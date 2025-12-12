#pragma once
#include "Board.h"
#include "King.h"
#include "Rook.h"
#include "Piece.h"
#define ERROR_2 2
#define ERROR_3 3
#define ERROR_4 4
#define ERROR_5 5
#define ERROR_6 6 
#define ERROR_7 7

class MoveValidator
{
		
	public:
		
		
		static int validateMove(Board* board, int srcRow, int srcCol, int destRow, int destCol, bool currentPlayerBlack);

	private:

		//return true if the piece that is moved is the correct color - code 2
		static bool isSourceEmptyOrWrongColor(Board* board, int srcRow, int srcCol, bool currentPlayerBlack);

		//return true if there is a piece with the same color in the destination - code 3
		static bool isDestinationOccupiedByPlayer(Board* board, int destRow, int destCol, bool currentPlayerBlack);









		//returns true if theres a check on the king that matches blackturn 
		static bool isCheck(Board* board, bool blackTurn);

		//we go in straight lines around the king to see if theres a rook or a queen
		static bool checkUpAndDown(Board* board, int change, bool blackTurn);
		static bool checkRightAndLeft(Board* board, int change, bool blackTurn);

		//we go in a cross around the king to see if theres a bishop or a queen
		static bool checkCross(Board* board, int changRow, int changCol, bool blackTurn);


		//we check around the king if there are kinghts
		static bool checkKnight(Board* board, bool blackTurn);

	
		

};
