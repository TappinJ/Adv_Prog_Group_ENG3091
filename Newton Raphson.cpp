#include <iostream>                 // for std::cout
#include <cmath>  
#include <Eigen/Dense>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;


double f(x){
  return std::exp(-0.1 * x) * std::sin(2 * x); 
}

void df(x){
  double exp = std::exp(-0.1 * x);
  double trig = (2 * std::cos(2 * x)) - (o.1 * std::sin(2 * x));
  return exp, trig;
}

double newtoon_raphson(double func, double dfunc, double x0, niters=100, tol=1e-6){
  double xold;
  double xnew;
  
  xold = x0;
  for (int i = 0, i <= niters; i++){

    double fval {func(xold)};
    double dfval {dfunc(xold)};
    if (std::abs(dfval) < 1e-15){
      std::cout << "Divergence: Derivative is zero at x = " << xold << "at iteration " << i << std::endl;
    xnew = xold - fval / dfval;
    } 

    if (std::abs(xnew - xold) < tol){
      std::cout << "solution converges at step " << i+1 << std::endl;
      return xnew;
    }
    xold = xnew;
  }
  std::cout << "Divergence: Root not found within the defined number of iterations and tolerance" << std::endl
}




int main() {
  double x = Eigen::VectorXd::LinSpaced(1000, 0, 10);
  double h = std::exp(-0.1 * x) * np.sin(2 * x);
  std::vector<double> x = {x};
  std::vector<double> y = {h};

  plt::plot(x, y, x, std::zeros_like(x));
  plt::show();
}
