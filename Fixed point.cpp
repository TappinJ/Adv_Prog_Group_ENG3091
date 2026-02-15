//Leandro's attempt at task 1

#include <iostream>                 // for std::cout
#include <cmath>                    // for std::sqrt and std::abs

double g(double x) {                //define function for g(x) and pass in x (pass by value)
    return 0.5 * (x + 5 / x);      // return the result of g(x)
}

double fixed_point(double x0, int niters = 1000, double tol = 1e-6) {       // Function for Fixed point iteration 
    double xold = x0;               // define variable

    for (int i = 1; i <= niters; i++) {         // loop for each iteration
        double xnew = g(xold);      // function call to g()
   
        if (std::abs(xnew - xold) < tol) {      // compare values (convergence check)
            std::cout << "Solution converges at iteration step " << i << std::endl;
            return xnew;                        // return answer
        }

        xold = xnew;
    }

    std::cout << "Warning: Method did not converge within the maxinum number of iterations\n";
    return 0;
}


int main() {
    double sqrt_of_five = fixed_point(2.0);     // function call to fixed point solver
    double ans = std::sqrt(5.0);               // define variable to find square root
    std::cout << "sqrt(5)            = " << sqrt_of_five << std::endl;
    std::cout << "sqrt(5) using math = " << ans << std::endl;

    return 0;
}


