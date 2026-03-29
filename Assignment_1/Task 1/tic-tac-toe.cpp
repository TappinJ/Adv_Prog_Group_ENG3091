#include <iostream>                                                                                 // For std::cout
#include "play.h"                                                                                   // Header for play structure
#include "Board.h"                                                                                  // Header for Board structure
#include <vector>                                                                                   // For std::vector


std::pair<bool, bool> gameWon(std::vector<std::vector<char>>& board){                               // Function to determine winner
    std::pair<bool, bool> result{false, false};                                                     // Initialise gameover and player Win, will change if the player wins or losses
                                                                   

    // Loop for horizontal win
    for (int i = 0; i < 3; i++ ) {                                                                  
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.') {       // Check if there are three X's or o's in a row
            result.first = {true};                                                                  // Set gameover to true
            if (board[i][0] == 'x') {                                                               // Check if player won
                result.second = {true};                                                             // Set player won to true
            }
        }
    }

    // Loop for vertical win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.') {       // Check if there are three X's or o's in a column
            result.first = {true};                                                                  // Set gameover to true
            if (board[0][i] == 'x') {                                                               // Check if player won
                result.second = {true};                                                             // Set player won to true
            }
        }
    }

    // Check for a diagonal win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') {           // Check if there are three X's or O's in a diagonal from left to right
        result.first = {true};                                                                      // Set gameover to true
        if (board[0][0] == 'x') {                                                                   // Check if player won
            result.second = {true};                                                                 // Set player won to true                 
        }                                          
    }                
    
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.') {           // Check if there are three X's or O's in a diagonal from right to left
        result.first = {true};                                                                      // Set gameover to true
        if (board[0][2] == 'x') {                                                                   // Check if player won
            result.second = {true};                                                                 // Set player won to true
        }
    }

    return result;                                                                                  // Return game Won and game over decision
}
    

int main(){
    Board base;                                                                                     // Create an object of Board structure
    play moves;                                                                                     // Create an object of play structure
    
    std::vector<std::vector<char>>& board = base.getBoard();                                           // Create the tic tac toe board
    std::pair<bool, bool> result = gameWon(board);                                                  // Check if the game is won initially
    bool& gameOver = result.first;                                                                   // Take gameover status from result
    bool& playerWin = result.second;                                                                 // Take playerWin status from result

    while (gameOver == false){                                                                      // Loop until the game is over
        base.displayboard();                                                                   // Display the current state of the board
        double position;
        bool valid{false};                                                                          // Initialise players move validity

        while (valid == false) {                                                                    // Loop until the player makes a valid move
            std::cout << "Make your move (numpad) \n";                      
            std::cin >> position;                                                                   // Get players move input
            valid = moves.player(board, position);                                                  // Determine if the players move is valid and place x if it is
        }
        
        moves.computer(board);                                                                      // Computer moves

        std::pair<bool, bool> result = gameWon(board);                                              // Check if the game has been won after both moves
        gameOver = result.first;                                                                    // Update gameover status
        playerWin = result.second;                                                                  // Update playerWin status
    };
    
    base.displayboard();                                                                       // Display the final game board
    
    // Check for the Winner
    if (playerWin == true){
        std::cout << "Game Over! You won\n" << std::endl;
    } else {
        std::cout << "Game Over Loser!!!\n";
    }
    return 0;                                                                                       // End program
}
