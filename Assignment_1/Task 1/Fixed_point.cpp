//Leandro's attempt at task 1

#include <iostream>                 // for std::cout
#include <cmath>                    // for std::sqrt and std::abs
#include "Task1a.h"           // for function prototypes

double g(double x) {                //define function for g(x) and pass in x (pass by value)
    return 0.5 * (x + 5 / x);      // return the result of g(x)
}

double fixed_point(double x0, int niters , double tol) {       // Function for Fixed point iteration 
    double xold{};                     // define variable
    double xnew{};

    xold = x0;               

    for (int i = 1; i <= niters; i++) {         // loop for each iteration
        xnew = g(xold);      // function call to g()
   
        if (std::abs(xnew - xold) < tol) {      // compare values (convergence check)
            std::cout << "Solution converges at iteration step " << i << std::endl;
            return xnew;                        // return answer
        }

        xold = xnew;
    }

    std::cout << "Warning: Method did not converge within the maxinum number of iterations\n";
    return 0;
}


void Run() {
    double sqrt_of_five{};
    double ans{};

    std::cout << "Fixed Point Calculation\n";

    sqrt_of_five = fixed_point(2.0);     // function call to fixed point solver
    ans = std::sqrt(5.0);               // define variable to find square root
    std::cout << "sqrt(5)            = " << sqrt_of_five << std::endl;
    std::cout << "sqrt(5) using math = " << ans << "\n" << std::endl;

}

