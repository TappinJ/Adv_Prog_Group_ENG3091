#include <iostream>
#include <cmath>
#include "gradient_combined.h"
#include "numerical_method_slr.h"

int main(){
    // 1 == Equation Solver
    SLR_equation normal;
    normal.dataset();
    normal.solve();

    // 2 == Gradient Solver
    SLR_gradient gradient;
    gradient.dataset();
    gradient.solve();

    // 3 == Math Comparison
    double w_error = std::abs(normal.w_star - gradient.w);
    double b_error = std::abs(normal.b_star - gradient.b);

    // 4 == Output Error Calcs
    std::cout << "\n ===Equation vs the Gradient method===" << std::endl;
    std::cout << "w difference = " << w_error << std::endl;
    std::cout << "b difference = " << b_error << std::endl;   

    return 0;
}