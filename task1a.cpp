#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

// Abstract Solver: Works for ANY function f and derivative df
double newton_raphson(std::function<double(double)> f, 
                      std::function<double(double)> df, 
                      double x0, 
                      double tol = 1e-6, 
                      int max_iters = 100) {
    double x = x0;
    for (int i = 0; i < max_iters; ++i) {
        double fx = f(x);
        double dfx = df(x);

        if (std::abs(dfx) < 1e-12) { // Avoid division by zero
            std::cout << "Derivative too small, stopping.\n";
            break;
        }

        double x_next = x - (fx / dfx);

        if (std::abs(x_next - x) < tol) {
            std::cout << "Converged in " << i + 1 << " iterations.\n";
            return x_next;
        }
        x = x_next;
    }
    return x;
}
int main() {
    double a, b, c;
    std::cout << "Enter coefficients a, b, and c for ax^2 + bx + c (no commas): ";
    if (!(std::cin >> a >> b >> c)) return 1;

    // Define the function f(x) = ax^2 + bx + c
    auto f = [a, b, c](double x) { 
        return a * std::pow(x, 2) + b * x + c; 
    };

    // Define the derivative f'(x) = 2ax + b
    auto df = [a, b](double x) { 
        return 2 * a * x + b; 
    };

    double initial_guess = 1.0;
    double root = newton_raphson(f, df, initial_guess);

    std::cout << "Found root: " << root  << std::endl;

    return 0;
}