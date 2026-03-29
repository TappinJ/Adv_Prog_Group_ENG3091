//Board.h
#include <iostream>                                                                                     // For std::cout
#include <vector>                                                                                       // For std::vector

// Class created to make the game board
class Board
{
    private:
        std::vector<std::vector<char>> board_;                                                          // Private member variable storing the board state

        void create_() {                                                                                // Private function to create and initialize the tic tac toe board
            // Loop to create rows
            for (int i = 0; i < 3; i++){                                                                
                std::vector<char> row = {'.','.','.'};                                                  
                board_.push_back(row);                                                                  // Add row to private member board
            }
        }
    
    public:
        Board() {create_();}                                                                            // Initialize the board when object is created

        void displayboard() {                                                                           // Function to display the current board state
            for (int i = 0; i < 3; i++) {                                                               
                std::cout << board_[i][0] << " " << board_[i][1] << " " << board_[i][2] << std::endl;   // Display row with spaces between cells
            }
        }
        std::vector<std::vector<char>>& getBoard() {return board_;}                                     // Public accessor to get the board
            
        
};
