//play.h
#include <iostream>                                                                                             // For std::cout
#include <vector>                                                                                               // For std::vector

// Class created for player and computer to make their moves
class play
{
    public:
    bool player(std::vector<std::vector<char>>& board, double& positionP){
        int numberPlacement[10][2] = {                                                              // Array mapping numpad positions to board coordinates
        {-1, -1},   // 0 
        {2, 0},     // 1 
        {2, 1},     // 2 
        {2, 2},     // 3
        {1, 0},     // 4 
        {1, 1},     // 5 
        {1, 2},     // 6 
        {0, 0},     // 7 
        {0, 1},     // 8 
        {0, 2}      // 9 
        };

        if (positionP >= 1 && positionP <= 9) {                                                     // Check if input is within valid range (numpad)
            int row = numberPlacement[(int)positionP][0];                                           // Get row from lookup table
            int col = numberPlacement[(int)positionP][1];                                           // Get column from lookup table

            if (board[row][col] == '.'){                                                            // Check if position is empty
                board[row][col] = 'x';                                                              // Place player's marker
                return true;                                                                        // Return true for valid move
            }
            else {                                                                                  
                std::cout << "Warning : This position is already occupied. Select empty space: " << std::endl;  
                return false;                                                                       // Return false for invalid move
            }
        }
        return false;                                                                               // Return false if input out of range
    }

    void computer(std::vector<std::vector<char>>& board){                                           // Function for computer to make random move    
        bool boardFull = true;                                                                      //Check if board is full

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '.') {
                    boardFull = false;
                    break;
                }
            }
            if (boardFull == false) break;
        }
    
        // Only let computer move if there's space
        if (boardFull == true) return;

        bool a{false};                                                                              // initialise computer move validity

        while (a == false){                                                                         // Loop until computer finds empty space
            int row = std::rand() %3;                                                               // Generate random row (0-2)
            int col = std::rand() %3;                                                               // Generate random column (0-2)

            if (board[row][col] == '.'){                                                          
                board[row][col] = 'o';                                                              // Place computer's marker if position is empty
                a = true;                                                                           // Set computer input to valid
            }
        }
    }
};