#include "Queen.h"

Queen::Queen(int row, int col, bool is_black):
	Piece(row, col, QUEEN_TYPE, is_black)
{

}

Queen::~Queen()
{

}

bool Queen::isPathClear(const Board& board, int destRow, int destCol) const
{
	//we make a rook and a bishop to check if the move is valid for one of them
	Rook rook(this->row, this->col, is_black);
	Bishop bishop(this->row, this->col, is_black);

	//we check if the move is vallid for rook or a bishop
	return rook.isPathClear(board, destRow, destCol) || bishop.isPathClear(board, destRow, destCol);


}
bool Queen::isMoveValid(int destRow, int destCol) const
{
	//we use rook and bishop isPathClear that also have isMoveValid so we dont need to check again for queen
	return false;
}

