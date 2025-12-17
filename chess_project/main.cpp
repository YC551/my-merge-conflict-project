#include <iostream>
#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "MoveValidator.h"

int mafin()
{
    Board board;


    // white pices
    board.pieces[0][0] = new Rook(0, 0, false);  // a8 - white rook
    board.pieces[0][7] = new Rook(0, 7, false);  // h8 - white rook
    board.pieces[0][3] = new King(0, 3, false);  // d8 - white king



    // black pices
    board.pieces[7][0] = new Rook(7, 0, true);   // a1 - black rook
    board.pieces[7][7] = new Rook(7, 7, true);   // h1 - black rook
    board.pieces[7][3] = new King(7, 3, true);   // d1 - black king

    std::cout << "Initial board setup:\n";
    


   
    board.changePieceLocation("a8c1");
    //board.changePieceLocation("h8d6");
    board.printBoard();

    std::string updateStr = "a1b2";
    
    board.printBoard();
    std::string srcLocation = updateStr.substr(0, 2); //get first part
    std::string dstLocation = updateStr.substr(2, 2); //get second part

    //we get the src and destination for the array
    int srcRow = board.getRowFromString(srcLocation);
    int srcCol = board.getColFromString(srcLocation);

    int dstRow = board.getRowFromString(dstLocation);
    int dstCol = board.getColFromString(dstLocation);
    
    std::cout << "code" << MoveValidator::validateMove(board, srcRow, srcCol, dstRow, dstCol, true);
  
    return 0;
}
