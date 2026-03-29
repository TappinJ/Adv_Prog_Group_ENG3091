#include <iostream>                                                                                 // For std::cout
#include <vector>                                                                                   // For std::vector
#include <cstdlib>                                                                                  // For std::rand() and std::srand()
#include <ctime>                                                                                    // For std::time()
#include "play.h"                                                                                   // Header for play class
#include "Board.h"                                                                                  // Header for Board class
#include "GameResult.h"                                                                             // Header for gameWon class

                     

int main(){
    std::srand(std::time(0));                                                                       // Seed the random number generator
    Board base;                                                                                     // Create an object of Board class
    play moves;                                                                                     // Create an object of play class
    gameWon result;                                                                                 // Create an object of gameWon class
    
    std::vector<std::vector<char>>& board = base.getBoard();                                        // Create the tic tac toe board
    result.checkWin(board);                                                                         // Check if the game is won initially
    bool& gameOver = result.gameover;                                                               // Take gameover status from result
    bool& playerWin = result.playerWin;                                                              // Take playerWin status from result 
    bool& draw = result.draw;                                                                       // Take draw status from result

    while (gameOver == false){                                                                      // Loop until the game is over
        base.displayboard();                                                                        // Display the current state of the board
        double position;
        bool valid{false};                                                                          // Initialise players move validity

        while (valid == false) {                                                                    // Loop until the player makes a valid move
            std::cout << "Make your move (numpad) \n";                      
            std::cin >> position;                                                                   // Get players move input
            valid = moves.player(board, position);                                                  // Determine if the players move is valid and place x if it is
        }
        
        moves.computer(board);                                                                      // Computer moves

        result.checkWin(board);                                                                     // Check if the game has been won after both moves
        gameOver = result.gameover;                                                                 // Update gameover status
        playerWin = result.playerWin;                                                               // Update playerWin status
        draw = result.draw;                                                                         // Update draw status
    };
    
    base.displayboard();                                                                            // Display the final game board
    
    // Check for the Winner
    if (playerWin == true) {
        std::cout << "Game Over! You won\n" << std::endl;
    } else if (draw == true) {
        std::cout << "Game Over! It was a draw\n" << std::endl;
    } else {
        std::cout << "Game Over Loser!!!\n";
    }
    return 0;                                                                                       // End program
}
