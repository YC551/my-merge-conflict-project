#include "Piece.h"

Piece::Piece(int row, int col, char type, bool is_black)
{
    this->row = row;
    this->col = col;      
    this->type = type;
    this->is_black = is_black;
}


Piece::~Piece()
{
    //there is nothing to free
}

int Piece::getRow() const
{
    return this->row;
}

void Piece::setRow(int row)
{
    this->row = row;
}

int Piece::getCol() const
{
    return this->col;
}

void Piece::setCol(int col)
{
    this->col = col;
}

bool Piece::getIs_black() const
{
    return this->is_black;
}


char Piece::getType() const
{
    return this->type;
}

