#include "logic.hpp"
#include "player.hpp"
#include "board.hpp"
#include "move.hpp"

#include <iostream>

namespace checkers {
    Logic::Logic(Player* p1, Player* p2, Board* board): playerOne(p1), playerTwo(p2), gameboard(board) { currentPlayer = &p1; }

    bool Logic::gameOver() {
        return playerOne->getPoints() == (BOARD_SIZE*BOARD_SIZE)/2 || playerTwo->getPoints() == (BOARD_SIZE*BOARD_SIZE)/2;
    }
    
    void Logic::makeMove(Move move) {
        try {
            std::cout << "MAKING MOVE TO " << "ROW " << move.row << " COL " << move.col << std::endl;
            gameboard->placePiece((*currentPlayer)->getColor(), move.row, move.col);
        } catch(InvalidMoveException) {
            std::cout << "NOPE" << std::endl;
        }
    }
}
