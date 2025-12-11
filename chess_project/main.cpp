#include <iostream>
#include "Board.h"
#include "Rook.h"
#include "King.h"

int main()
{
    Board board;

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


    board.changePieceLocation("a1a8");
    board.printBoard();
   // board.pieces[0][3]->isCheck();

    return 0;
}
