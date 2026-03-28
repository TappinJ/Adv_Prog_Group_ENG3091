//Board.h
#include <iostream>                                                                                 // For std::cout
#include <vector>                                                                                   // For std::vector

// Structure created to make the game board
struct Board
{
    std::vector<std::vector<char>> create() {                                                       // Function to create and initialize the tic tac toe board
        std::vector<std::vector<char>> board;                                                       // Create empty 2D vector
        // Loop to create rows
        for (int i = 0; i < 3; i++){                                                                
            std::vector<char> row = {'.','.','.'};                                                  
            board.push_back(row);                                                                   // Add row to board
        }
        return board;                                                                               // Return completed 3x3 board
    }

    void displayboard(std::vector<std::vector<char>>& board) {                                      // Function to display the current board state
        for (int i = 0; i < 3; i++) {                                                               
            std::cout << board[i][0] << " " << board[i][1] << " " << board[i][2] << std::endl;      // Display row with spaces between cells
        }
    }
};
    
