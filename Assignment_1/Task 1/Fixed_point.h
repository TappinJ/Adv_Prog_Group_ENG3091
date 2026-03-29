//Fixed_point.h
#include <iostream>                 // For std::cout
#include <cmath>                    // For std::sqrt and std::abs (math functions)

// Class created for Fixed Point method solver
class Fixed
{
    private:
        double g(const double &x) {               // Private member function takes x value and returns g(x)
            return 0.5 * (x + 5 / x);       // return the result of g(x)
        }
    
    public:
        double fixed_point(const double& x0, int niters=100, double tol=1e-6) {   // Main solver with x0 as initial guess for the root, niters as maximum iterations, and tol as tolerance
    // Returns the approximate fixed point (root) as a double
            double xold{x0};                // Initialize current approximation to starting guess x0                                

        for (int i = 1; i <= niters; i++) {         // Loop up to niters times
            double xnew {g(xold)};                  // Compute next approximation by applying fixed-point function g(x)
   
            if (std::abs(xnew - xold) < tol) {      // Check if change between next approximations is below tolerance 
                std::cout << "Solution converges at iteration step " << i << std::endl;         // Print success message with iteration count where convergence occurred
                return xnew;                        // Return the converged fixed point
            }

        xold = xnew;                                // Update current approximation for next iteration
        }
        // If loop completes without convergence then print failure message
        std::cout << "Warning: Method did not converge within the maxinum number of iterations\n";
        return xold;
    }

};



    

  



