#include <iostream>
#include <cmath>
#include <iomanip> 
#include <vector>  
#include "gradient_combined.h"
#include "numerical_method_slr.h"
#include "metrics.h"

int main(){
    // 1 == Equation Solver (Analytical)
    SLR_equation normal;
    normal.dataset();
    normal.solve();

    // 2 == Gradient Solver (Iterative)
    SLR_gradient gradient;
    gradient.dataset();
    gradient.solve();

    // 3 == Math Comparison
    double w_error = std::abs(normal.w_star - gradient.w);
    double b_error = std::abs(normal.b_star - gradient.b);

    // 4 == Output Error Calcs
    std::cout << "\n=== Equation vs the Gradient method ===" << std::endl;
    std::cout << "w difference = " << w_error << std::endl;
    std::cout << "b difference = " << b_error << std::endl;   

    // 5 == Data Quality & Model Fitness
    // Generate the passive transformation prediction vector using the learned weights
    std::vector<double> predictions = gradient.predict();
    
    // Pass the actual true y value and model's predictions to find accuracy
    double Rsquared = calculate_Rsquared(gradient.y, predictions);

    std::cout << "\n=== Data Quality ===" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    
    // Multiply R^2 value by 100 to output %
    std::cout << "Model Predictability: " << (Rsquared * 100.0) << "%" << std::endl;
    
    return 0;
}