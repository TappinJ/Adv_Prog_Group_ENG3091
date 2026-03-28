//Main file
#include <iostream>                 // For std::cout
#include <cmath>                    // For std::sqrt and std::abs (math functions)
#include <vector>                   // For std::vector
#include "Newton_Raphson.h"         // Header for Newton_Raphson solver class
#include "Fixed_point.h"            // Header for Fixed Point solver class

int main() {
    

    std::cout << "Newton Raphson Calculation\n";

    std::vector<double> roots;      // Stores roots from Newton-Raphson solver
    std::vector<double> x0_list;    // Stores initial guesses 

    Newton solver1;                 // Create an object of Newton class 
    Fixed solver2;                  // Create an object of Fixed Point class 

    for (int i = 0; i < 7; i++) {   // Generate initial guesses
        x0_list.push_back(1.5 * i); // Add values to x0_list
    }

    // Apply Newton-Raphson method to each initial guess
    for (double x0:x0_list) {
        double root{solver1.newton_raphson(x0)};        // Find root starting from x0
        roots.push_back(root);                          // Store result
    }

    // Print all roots
    for (double r : roots) {
        std::cout << r <<  " ";
    }

    std::cout << std::endl;                             // Move to next line

    // Variables for Fixed Point method
    double sqrt_of_five{};                              // Store approximation of sqrt(5)
    double ans{};                                       // Store exact value of sqrt(5) found using the square root function

    std::cout << "Fixed Point Calculation\n";           // Call fixed point method starting from initial guess 2.0

    sqrt_of_five = solver2.fixed_point(2.0);            // Call fixed point method starting from initial guess 2.0
    ans = std::sqrt(5.0);                               // Find the actual sqrt(5) using standard library
    
    // Print results
    std::cout << "sqrt(5)            = " << sqrt_of_five << std::endl;
    std::cout << "sqrt(5) using math = " << ans << "\n" << std::endl;
}
