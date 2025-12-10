#include "Piece.h"

Piece::Piece(int row, int col, char type, bool is_black)
{
    this->row = row;
    this->col = col;      
    this->type = type;
    this->is_black = is_black;
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

void Piece::setIs_black(bool is_black)
{
    this->is_black = is_black;
}

char Piece::getType() const
{
    return this->type;
}

void Piece::setType(char type)
{
    this->type = type;
}
