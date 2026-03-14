#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>


// Structure for Equation method solver for Simple Linear Regression (SLR)

struct SLR_equation
{ 
    std::vector<double> x;
    std::vector<double> y;
    double w_star{};
    double b_star{};

    // 1 == THE LOADING FUNCTION

    void dataset(){
        //Opening the datafile
        std::ifstream file ("single_dataset.csv");

        //Safety net in case the single_dataset.csv hasn't been generated.
        if(!file){
            std::cout << "Error: single_dataset.csv not found!\n";
            return;
        }
    
        //code requesting the program to ignore headers in the .csv
        std::string header;             // Creates a blank text variable
        std::getline(file, header);     // The first row of the .csv is discarded

        // bins for the data
        double xt, yt;
        // comma bin
        char c;

        // Data Loader
        while (file >> xt >> c >> yt){
            x.push_back(xt);
            y.push_back(yt);
        }
    }
    // NORMAL EQUATION SIMPLE LINEAR REGRESSION PROGRAM

    // 2 == SOLVING FUNCTION
    void solve() {
        int n = x.size();
        // Safety check
        if (n == 0){
            std::cout << "Error: Data is empty.\n";
            return;
        }
        double x_sum = 0.0, y_sum = 0.0, xy_sum = 0.0, xx_sum = 0.0;
    
    // Single pass to accumulate all of the required sums
    for (int i = 0; i<n; ++i){
        x_sum += x[i];
        y_sum += y[i];
        xy_sum += x[i] * y[i];
        xx_sum += x[i] * x[i];
}
    // --CALCULATOR-- Slope - w*, Intercept - b*
    double denominator = (n * xx_sum) - (x_sum * x_sum);
    w_star = ((n * xy_sum) - (x_sum * y_sum))/ denominator;
    b_star = (y_sum - (w_star * x_sum))/n;

    // --RESULTS PRINTER--
    std::cout << "\n ===SLR Normal Equation Result=== " << std::endl;
    std::cout << "Slope w* = " << w_star << std::endl;
    std::cout << "Intercept b* = "<< b_star << std::endl;
    }
};











