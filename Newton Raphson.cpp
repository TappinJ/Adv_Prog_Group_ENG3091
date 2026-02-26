#include <iostream>                 // for std::cout
#include <cmath>  
#include <vector>

double f(double x){
  return std::exp(-0.1 * x) * std::sin(2 * x); 
}

double df(double x){
  double exp = std::exp(-0.1 * x);
  double trig = (2 * std::cos(2 * x)) - (0.1 * std::sin(2 * x));
  return exp * trig;
}

double newton_raphson(double x0, int niters=100, double tol=1e-6){ 
  double xold{x0};
  for (int i = 1; i <= niters; i++){

    double fval {f(xold)};
    double dfval {df(xold)};
    if (std::abs(dfval) < 1e-15){
      std::cout << "Divergence: Derivative is zero at x = " << xold << "at iteration " << i << std::endl;
    } 

    double xnew {xold - fval / dfval};

    if (std::abs(xnew - xold) < tol){
      std::cout << "solution converges at step " << i << std::endl;
      return xnew;
    }
    xold = xnew;
  }
  std::cout << "Divergence: Root not found within the defined number of iterations and tolerance" << std::endl;
  return xold;
}

void graph(){
  std::vector<double> x;
  std::vector<double> h;

  double N{10.0 / 1000.0};

  for (int i = 0; i <= 1000; i++) {
    
    x.push_back(i * N);
    h.push_back(std::exp(-0.1 * (i * N)) * std::sin(2 * (i * N)));

  }

  

}

int main() {

  std::vector<double> roots;
  std::vector<double> x0_list;

  for (int i = 0; i < 7; i++) {
    x0_list.push_back(1.5 * i);
  }

  for (double x0:x0_list) {
    double root{newton_raphson(x0)};
    roots.push_back(root);
  }

  for (double r : roots) {
    std::cout << r <<  " ";
  }

  std::cout << std::endl;

  return 0;
}
