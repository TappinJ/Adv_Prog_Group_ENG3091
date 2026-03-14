#include <iostream>
#include <random>
#include <fstream>
#include <string>

//Data generator made as struct for future headerfile
struct data_generator {
    
    unsigned seed = 42;         // Fixed random seed for repeatability.

    // 1 - First feature, data gen for Simple Linear Regression
    void slr_generator (int samples = 100, std::string filename = "single_dataset.csv"){
        double m = 1.4;
        double c = 2.0;

        std::minstd_rand0 generator(seed);
        std::uniform_real_distribution <double> x_dist(0.0, 10.0);
        std::normal_distribution <double> noise(0.0, 0.5);
        
        std::ofstream file(filename);
        if (file.is_open()){
            file << "x,y \n";
            for (int i=0; i < samples; ++i){
                double x = x_dist(generator);
                double y = (m*x)+c;

                file << x + noise(generator) << ","
                    << y + noise(generator) << "\n";
            }
        }
    }

    // 2 - Second feature, data gen for /multiple Linear Regression
    void mlr_generator(int samples = 100, std::string filename = "multi_dataset.csv"){
        double w1 = 1.4;
        double w2 = -0.5;
        double b = 2.0;

        std::minstd_rand0 generator (seed);
        std::uniform_real_distribution<double> x_dist(0.0, 10.0);
        std::normal_distribution<double> noise(0.0, 0.5);

        std::ofstream file(filename);
        if (file.is_open()) {
            file<<"x1,x2,y\n";
            for(int i=0; i < samples; ++i){
                double x1 = x_dist(generator);
                double x2 = x_dist(generator);
                double y = (w1*x1) + (w2*x2) +b;

                file << x1 + noise(generator) << ","
                     << x2 + noise(generator) << ","
                     << y + noise(generator) << "\n";
            }
        }
    }

};