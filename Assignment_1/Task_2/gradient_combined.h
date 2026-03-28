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
    std::vector<double> x1;
    std::vector<double> x2;
    std::vector<double> y;

    // 1 == DATA LOADER
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
void compute_gradients(double w1, double w2, double b, 
                        double& step_w1, double& step_w2, double& step_b)
{
    step_w1 = 0.0;
    step_w2 = 0.0;
    step_b = 0.0;
    int m = x1.size();

    for(int i=0; i<m; i++){
        double error = (w1 * x1[i]) + (w2 * x2[i]) + b - y[i];
        step_w1 += error*x1[i];
        step_w2 += error*x2[i];
        step_b += error;
    }

    step_w1 /= m;
    step_w2 /= m;
    step_b /= m;
}

// 3 == MAIN SOLVER LOOP ==
void solve(){
    double w1 = 0.0;
    double w2 = 0.0;
    double b = 0.0;
    const double n = 0.001;

    for(int i=0; i<10000; i++){
        double step_w1{};
        double step_w2{};
        double step_b{};

        compute_gradients(w1, w2, b, step_w1, step_w2, step_b);

        w1 = w1 - n*step_w1;
        w2 = w2 - n*step_w2;
        b = b - n*step_b;
    }

    std::cout << "===MLR Gradient Descent Result===\n";
    std::cout << "w1 = " << w1 << "\n";
    std::cout << "w2 = " << w2 << "\n";
    std::cout << "b = " << b << "\n";
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
