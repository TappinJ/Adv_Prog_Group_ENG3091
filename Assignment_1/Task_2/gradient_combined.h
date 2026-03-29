// gradient_combined.h
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

// === SAFETY CHECK FUNCTION ===
bool safety_check(std::ifstream& file, std::string filename){
    // Check 1 == Check if the file exists
    if(!file.is_open()){
        std::cout << "Error: " << filename << "not found.\n";

        return false;   // Failed to find the dataset!
    }

    // Check 2 == Check if data exists inside of the file
    if(file.peek() == std::ifstream::traits_type::eof()){
        std::cout << "Error: " << filename << "has no data.\n";
        return false;
    }
    return true;        // Dataset exists!
}

//=========================================
// TOOL 1 == SIMPLE LINEAR REGRESSION (SLR)
//=========================================
struct SLR_gradient
{
    std::vector<double> x;
    std::vector<double> y;

    // Making member variables
    // so they can be used in a comparison function
    double w{0};
    double b{0};
    const double n{0.001};      // Learning Rate

    // 1 == Data Loader
    void dataset(){
        std::ifstream file("single_dataset.csv");

        if(!safety_check(file, "single_dataset.csv")) return;
    
        std::string header;
        std::getline(file, header);

        double xt, yt;
        char c; 
        while (file >> xt >> c >> yt) {
        x.push_back(xt);
        y.push_back(yt);
        }
    }
    // 2 == Derivative functions
double deriv_w(const std::vector<double>& x,
               const std::vector<double>& y,
               double w, double b)
{
    double deriv = 0.0;
    int m = x.size();

    for(int i = 0; i < m; i++)
    {
        deriv += (w * x[i] + b - y[i]) * x[i];
    }

    return deriv / m;
}

double deriv_b(const std::vector<double>& x,
               const std::vector<double>& y,
               double w, double b)
{
    double deriv = 0.0;
    int m = x.size();

    for(int i = 0; i < m; i++)
    {
        deriv += (w * x[i] + b - y[i]);
    }

    return deriv / m;
}

// 3 == SLR - Main Solver Logic
void solve(){
    if (x.empty()){
        std::cout << "Error: No data loaded.\n";
        return;
    }

    // Iterative Gradient Descent Loop
    for(int i = 0; i < 10000; i++)
    {
        w = w - n * deriv_w(x, y, w, b);
        b = b - n * deriv_b(x, y, w, b);
    }

    std::cout << "===SLR Gradient Descent Result===" << std::endl;
    std::cout << "w = " << w << std::endl;
    std::cout << "b = " << b << std::endl;
}
};

//=======================================
// TOOL 2 == MULTIPLE LINEAR REGRESSION
//=======================================

struct MLR_gradient{
    // Data storage//
    std::vector<double> x1;
    std::vector<double> x2;
    std::vector<double> y;

    // Initialised using uniform brace initialisation
    // Prevents accidental narrowing conversions
    // Initialised outside of the void function in case the variables are needed in the future
    // Being outside of the void function makes these stand out.
    double w1{};
    double w2{};
    double b{};
    // n is the learning rate, controls the step size during the gradient descent. 
        const double n{0.001};          // Value of 0.001 chosen to ensure stable convergence
        const int epochs{1000};         // epochs - training iterations. Defines the number of passes over the dataset

    // 1 == DATA LOADER
    // Void function as the dataset will no longer be needed after the parameters are saved in the data storage vectors
    void dataset(){
        std::ifstream file("multi_dataset.csv");

        if(!safety_check(file, "multi_dataset.csv")) return;

        std::string header;
        std::getline(file, header);

        double temp_x1, temp_x2, yt;
        char c1, c2;

        // Read the formatted rows and drop the values into the corresponding bins
        while (file >> temp_x1 >> c1 >> temp_x2 >> c2 >> yt){
            x1.push_back(temp_x1);
            x2.push_back(temp_x2);
            y.push_back(yt);
        }
    }

    // 2 == Derivative Function Loop
    // Calculating all 3 gradients in a single pass
    // It calculates the steepness and error surface for all 3 parameters simultaneously.
    // The use of pass-by-reference is chosen to increase efficiency.
    void compute_gradients(double w1, double w2, double b, 
                            double& step_w1, double& step_w2, double& step_b)
    {

        // ---Resetting the accumulators---
        // Because step_w1, step_w2 and step_b are references 
        // Setting them to 0.0 directly clears the values in the solve() function's memory
        // Ensuresnew gradients aren't accidentally added to the previous iteration.
        step_w1 = 0.0;
        step_w2 = 0.0;
        step_b = 0.0;
        
        // size_t prevents signed/unsigned comparison warnings
        size_t m = x1.size();       // Scaling factor (m). 
                                    // Represents the total number of data points
                                    // Used to calculate the mean in mean squared error.

        // ---Optimisation---
        // Loop for optimising the batch gradient descent
        // Iterates through the entire set (m samples) to calculate the collective error
        for(size_t i=0; i<m; i++){

            // 1 - Calculating the residual error (distance the model is from reality)
            // compute prediction using the MLR state y = w1*x1 + w2*x2 + b
            // error is the difference between this prediction and y[i]
            double error = (w1 * x1[i]) + (w2 * x2[i]) + b - y[i];

            // 2 - Accumulating the partial derivatives
            // Chain rule - how much w1 contributed to the error
            // multiply residual by the input value 
            // these "step_" variables act as accumulators for the total gradient vector
            step_w1 += error*x1[i];         // Derivative w.r.t. w1
            step_w2 += error*x2[i];         // Derivative w.r.t. w2
            step_b += error;                // Derivative w.r.t. bias
        }
        // 3 - Normalisation (the mean gradient)
        // Divide by "m" to calculate the AVG gradient across the dataset
        // Mean Squared Error approach - ensured total step size remains constant
        // Regardless of the number of rows
        // Kept outside of the loop for single pass optimisation
        // saves (m-1) division operations
        step_w1 /= m;
        step_w2 /= m;
        step_b /= m;
    }

    // 3 == MAIN SOLVER LOOP ==
    // Iterative optimisation phase
    // Model "learns" by descending the surface towards the global minimum
    // inside "void" as values do not need returning - data is updated into vectors.
    void solve(){
        
        // loop runs through the fixed number of "epochs"
        // Each epoch represents one full pass and update on the entire dataset
        for(int i=0; i<epochs; i++){

            double step_w1{};       // Accumulators for the current epoch's gradient vector
            double step_w2{};       // Initialised to 0
            double step_b{};        // New calculation for each iteration

            // Calls the previously defined function
            // Calculates the direction and magnitude of the steepest ascent
            compute_gradients(w1, w2, b, step_w1, step_w2, step_b);

            // Update - parameter adjustment
            // Gradient scaled by the learning rate
            // Substracted to move the parameters in the opposite direction of the error increase
            w1 = w1 - n*step_w1;
            w2 = w2 - n*step_w2;
            b = b - n*step_b;
        }
    }

    // 4 == Mean Squared Error
    // Quantifies the model accuracy by calculating the Loss Function 
    // Const ensures that this new function (calculate_mse) doesnt modify any of the gradient variables
    // Turns the function into a "read-only" operation.
    double calculate_mse() const {
        double total_squared_error{0.0};
        size_t m = y.size();

        for (size_t i = 0; i < m; i++) {
            // Prediction based on the calculated parameters
            double prediction = (w1 * x1[i]) + (w2 * x2[i]) + b;
            double residual = prediction - y[i];
            total_squared_error += (residual * residual);
        }

        // Returns the loss scaled by 2m
        return total_squared_error / (2.0 * m);
    }

};

//============================================
// TOOL 3 == Pearson Correlation Coefficient
//============================================

double pearson_correlation(const std::vector<double>& x, const std::vector<double>& y) {
    size_t n{x.size()};

    double sumXY{0.0};
    double sumX{0.0};
    double sumY{0.0};
    double sumX_squared{0.0};
    double sumY_squared{0.0};

    for(size_t i=0; i < n; i++) {
        sumXY += x[i] * y[i];
        sumX += x[i];
        sumY += y[i];
        sumX_squared += x[i] * x[i];
        sumY_squared += y[i] * y[i];
    }

    // Calculate the numerator and denominator
    double num{(n * sumXY) - (sumX * sumY)};
    double den{std::sqrt((n * sumX_squared - (sumX*sumX)) * (n * sumY_squared - (sumY*sumY)))};

    // Safety Check
     if(den == 0.0) {
        std::cout << "Error: Cannot calculate correlation as denominator is zero.\n";
        return 0.0;
    }

    double r{num / den};
    return r;
}
