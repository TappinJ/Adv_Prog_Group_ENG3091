#define METRICS_H

#include <vector>

//======= TOOL TO FIND R^2 ======
// Coefficient of determination
// Finding the accuracy of Regression models
// R^2 - Coefficient of determination

// Taking two vectors - true values and model's predictions
// "inline" prevents multiple definition errors
inline double calculate_Rsquared(const std::vector<double>& y_actual, const std::vector<double>& y_predicted){
   
    // PARITY CHECK - confirming that the vector size matches
    if(y_actual.empty() || y_actual.size() != y_predicted.size()) return 0.0;

    // Accumulators for sum of squares residuals and total sum of squares
    double ss_res{};
    double ss_tot{};
    double sum_y{};
    size_t m = y_actual.size();

    // 1 - Finding mean values of y_actual
    for (size_t i=0; i<m; i++){
        sum_y += y_actual[i];
    }
    double mean_y = sum_y/m;

    // 2 - Single pass variance calculation
    // Calculate ss_res (model error) and ss_tot (deviation from the mean)
    for (size_t i=0; i<m; i++){
        // Residual: distance between the reality and the predicted value
        double residual = y_actual[i] - y_predicted[i];
        ss_res += (residual*residual);

        // Total distance
        // distance between realioty and the baseline mean
        double total_diff = y_actual[i] - mean_y;
        ss_tot += (total_diff*total_diff);
    }

    // Normalisation
    // Safety check - avoid division by 0
    if (ss_tot == 0.0) return 0.0;
    
    // 3 - Return the final R^2 ratio
    return 1.0 - (ss_res/ss_tot);
};