#define METRICS_H

#include <vector>

//======= TOOL TO FIND R^2 ======
// Finding the accuracy of Regression models
// R^2 - Coefficient of determination

// Taking two vectors - true values and model's predictions
// "inline" prevents multiple definition errors
inline double calculate_Rsquared(const std::vector<double>& y_actual, const std::vector<double>& y_predicted){
    // SAFETY CHECK - confirming that the vector size matches
    if(y_actual.empty() || y_actual.size() != y_predicted.size()) return 0.0;

    double ss_res{};
    double ss_tot{};
    double sum_y{};
    size_t m = y_actual.size();

    // 1 - Finding means of the actual y values
    for (size_t i=0; i<m; i++){
        sum_y += y_actual[i];
    }
    double mean_y = sum_y/m;

    // 2 - Calculate ss_res (model error) and ss_tot (deviation from the mean)
    for (size_t i=0; i<m; i++){
        double residual = y_actual[i] - y_predicted[i];
        ss_res += (residual*residual);

        double total_diff = y_actual[i] - mean_y;
        ss_tot += (total_diff*total_diff);
    }

    // 3 - Return the final R^2 ratio
    return 1.0 - (ss_res/ss_tot);
};