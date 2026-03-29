// GameResult.h
#include <iostream>
#include <vector>


struct gameWon
{
    bool gameover{false};                                                                           // Initialise gameover will change if the player wins or losses
    bool playerWin{false};                                                                          // Initialise player Win will change if the player wins or losses
    bool draw{false};                                                                               // Initialise draw will change if there is a draw

    void checkWin(std::vector<std::vector<char>>& board) {                                          // Function to determine winner
        // Reset 
        gameover = false;     
        playerWin = false;
        draw = false;
        // Loop for horizontal win
        for (int i = 0; i < 3; i++ ) {                                                                  
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.') {   // Check if there are three X's or o's in a row
                gameover = {true};                                                                  // Set gameover to true
                if (board[i][0] == 'x') {                                                           // Check if player won
                    playerWin = {true};                                                             // Set player won to true
                }
            }
        }

        // Loop for vertical win
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.') {   // Check if there are three X's or o's in a column
                gameover = {true};                                                                  // Set gameover to true
                if (board[0][i] == 'x') {                                                           // Check if player won
                    playerWin = {true};                                                             // Set player won to true
                }
            }
        }
        // Check for a diagonal win
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') {       // Check if there are three X's or O's in a diagonal from left to right
            gameover = {true};                                                                      // Set gameover to true
            if (board[0][0] == 'x') {                                                               // Check if player won
                playerWin = {true};                                                                 // Set player won to true                 
            }                                          
        }                
    
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.') {       // Check if there are three X's or O's in a diagonal from right to left
            gameover = {true};                                                                      // Set gameover to true
            if (board[0][2] == 'x') {                                                               // Check if player won
                playerWin = {true};                                                                 // Set player won to true
            }
        }

        // Check for a draw (is every space occupied)
        if (board[0][0] != '.' &&                                                                   
            board[0][1] != '.' &&
            board[0][2] != '.' &&
            board[1][0] != '.' &&
            board[1][1] != '.' &&
            board[1][2] != '.' &&
            board[2][0] != '.' &&
            board[2][1] != '.' &&
            board[2][2] != '.') {
                draw = {true};
                gameover = {true};
        }
    }
}; 