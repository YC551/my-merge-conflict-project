#pragma once
#include "Board.h"
#include "King.h"
#include "Rook.h"
#include "Piece.h"
#define ERROR_0 0
#define ERROR_1 1
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

		//we check if the player causes a check on himself
		static bool makesCheck(Board* board, int srcRow, int srcCol, int destRow, int destCol, bool currentPlayerBlack);

		//checks if any index is out of array
		static bool areIndexOutOfBounds(int row, int col);

		//check if the path is valid for the piece
		static bool isPieceMoveInvalid(Board* board, int srcRow, int srcCol, int destRow, int destCol);

		//we check if the piece moved
		static bool isSourceEqualDestination(int srcRow, int srcCol, int destRow, int destCol);



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
