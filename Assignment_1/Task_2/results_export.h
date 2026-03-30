#define RESULTS_EXPORT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// 1 --- SLR Export
inline void SLR_export(const std::vector<double>& x, const std::vector<double>& y_actual, const std::vector<double> y_pred, const std::string& filename = "SLR_results.csv"){
    std::ofstream file(filename);
    file << "x, y_actual, y_predicted\n";
    for (size_t i=0; i<x.size(); ++i){
        file << x[i] << "," << y_actual[i] << "," << y_pred[i] << "\n";
    }
    file.close();
    std::cout << "Data successfully exported to:" << filename << std::endl;
}

// 2 --- MLR Export
inline void MLR_export(const std::vector<double>& x1, const std::vector<double>& x2, const std::vector<double>& y_actual, const std::vector<double>& y_pred, const std::string& filename = "MLR_results.csv"){
    std::ofstream file(filename);
    file << "x1, x2, y_actual, y_predicted\n";
    for (size_t i=0; i<y_actual.size(); ++i){
        file << x1[i] << "," << x2[i] << "," << y_actual[i] << "," << y_pred[i] << "\n";
    }
    file.close();
    std::cout << "Data successfully exported to:" << filename << std::endl;
}