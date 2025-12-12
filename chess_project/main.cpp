#include <iostream>
#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "MoveValidator.h"

int main()
{
    Board board;
    MoveValidator validator;

    // white pices
    board.pieces[7][0] = new Rook(7, 0, false);  // a1 - white rook
    board.pieces[7][7] = new Rook(7, 7, false);  // h1 - white rook
    board.pieces[7][3] = new King(7, 3, false);  // d1 - white king



    // black pices
    board.pieces[0][0] = new Rook(0, 0, true);   // a8 - black rook
    board.pieces[0][7] = new Rook(0, 7, true);   // h8 - black rook
    board.pieces[0][3] = new King(0, 3, true);   // d8 - black king

    
    std::cout << "Initial board setup:\n";
    board.printBoard();

    board.changePieceLocation("a1d2");
    

    

    
    board.printBoard();

    if (validator.isCheck(&board, true))//check if there is a check on black
    {
        std::cout << "black check\n";
    }


    if (validator.isCheck(&board, false))//check if there is a check on white
    {
        std::cout << "white check\n";
    }
   

    return 0;
}
