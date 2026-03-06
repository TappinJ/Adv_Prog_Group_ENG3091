#include <iostream>
#include <vector>
#include <random>
#include <fstream>


int main () {
    // Initialise the linear function
    double k = 1.4;
    double m = 2.0;
    int samples = 100;

    // Initialise vectors to hold data
    std::vector <float> x_data, y_data;
    
    // Fixed Random Seed
    unsigned data = 42;
    std::minstd_rand0 generator (data);

    // Defining the distribution
    std::uniform_real_distribution<double> x_dist(0.0, 10.0);
    std::normal_distribution<double> noise(0.0, 0.5);

    // Generate the data
    for (int i= 0; i < samples; ++i) {
        double x = x_dist(generator);
        double y = (k * x) + m;

        // Generate noise as double, stored as float
        x_data.push_back(x + noise(generator));
        y_data.push_back(y + noise(generator));

    }

        // Create a data.scv file
        std::ofstream my_file("dataset.csv");

        if (my_file.is_open()){
            my_file << "x,y\n";
            for (int i= 0; i< samples; ++i){
                my_file << x_data[i] << "," << y_data[i] << "\n";
            }
        }

        my_file.close();
        std::cout << "Data Saved!";
    

    return(0);
}
