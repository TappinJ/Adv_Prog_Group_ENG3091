//Newton_Raphson.h
#include <iostream>                 // For std::cout
#include <cmath>                    // For math function

// Class created for Newton Raphson method solver
class Newton
{
  private:
    double f(const double &x){             // Private member function that takes an x value and returns f(x)
    return std::exp(-0.1 * x) * std::sin(2 * x); 
    }
  
    double df(const double &x){            // Private member function to return the derivative of x
    double exp = std::exp(-0.1 * x);
    double trig = (2 * std::cos(2 * x)) - (0.1 * std::sin(2 * x));
    return exp * trig;
  }

  public:
    double newton_raphson(const double &x0, int niters=100, double tol=1e-6){  // Main solver with x0 as initial guess for the root, niters as maximum iterations, and tol as tolerance
    // Returns the approximate root as a double

    double xold{x0};                                                    // Initialize current approximation to the starting guess x0       

    for (int i = 1; i <= niters; i++){                                  // Loop up to niters times

      double fval {f(xold)};                                            // Evaluate the function at current point
      double dfval {df(xold)};                                          // Evaluate the derivative at current point

      if (std::abs(dfval) < 1e-15){                                     // Check if derivative is essentially zero
        std::cout << "Divergence: Derivative is zero at x = " << xold << "at iteration " << i << std::endl;  // Print warning message showing where and when derivative became zero
        return xold;                                                    // Exit to prevent division by zero
      } 
        
      double xnew {xold - fval / dfval};                                // Update the approximation to be closer to the root

      if (std::abs(xnew - xold) < tol){                                 // Check if change between approximations is smaller than tolerance
        std::cout << "solution converges at step " << i << std::endl;   // Print success message with approximation count
        return xnew;                                                    // Return converged root
      } 
      xold = xnew;                                                      // Update old approximation for new loop
    }
    // If loop completes without convergence then print failure message
    std::cout << "Divergence: Root not found within the defined number of iterations and tolerance" << std::endl;          
    return xold;                                                        // Return last approximation
  }
};



