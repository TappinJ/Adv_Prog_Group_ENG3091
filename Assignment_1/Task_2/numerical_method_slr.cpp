#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>


// Loading and building data structure

struct data
{ 
    std::vector<double> x;
    std::vector<double> y;

    void dataset(){
        //Opening the datafile
        std::ifstream file ("dataset.csv");
    
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
};

// NORMAL EQUATION SIMPLE LINEAR REGRESSION PROGRAM

int main(){

    // 1 - Initiates the previously built struct
    data my_data;
    my_data.dataset();

    // 2 - Data Accessed
    int n = my_data.x.size();

    //safety check in case the data is empty or missing
    if (n == 0) return 1;

    double x_sum = 0.0, y_sum = 0.0, xy_sum = 0.0, xx_sum = 0.0;

// Single pass to accumulate all of the required sums
for (int i = 0; i<n; ++i){
    x_sum += my_data.x[i];
    y_sum += my_data.y[i];
    xy_sum += my_data.x[i] * my_data.y[i];
    xx_sum += my_data.x[i] * my_data.x[i];
}

// --CALCULATOR-- Slope - w*, Intercept - b*
double denominator = (n * xx_sum) - (x_sum * x_sum);
double w_star = ((n * xy_sum) - (x_sum * y_sum))/ denominator;
double b_star = (y_sum - (w_star * x_sum))/n;

// --RESULTS PRINTER--
std::cout << "Normal Equation Result \n";
std::cout << "Slope w* = " << w_star << "\n";
std::cout << "Intercept b* = "<< b_star << "\n";

return 0;

}








