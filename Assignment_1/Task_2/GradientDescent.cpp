#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct data
{
    std::vector<double> x;
    std::vector<double> y;

    void dataset(){
        std::ifstream file("dataset.csv");

        if(!file){
        std::cout << "Error: dataset.csv not found!" << std::endl;
        return;
    }
        std::string header;
        std::getline(file, header);

        double xt, yt;
        char c; 
        while (file >> xt >> c >> yt) {
        x.push_back(xt);
        y.push_back(yt);
        }
    }
};

double deriv_w(const std::vector<double>& x,
               const std::vector<double>& y,
               double w, double b)
{
    double deriv{};
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
    double deriv{};
    int m = x.size();

    for(int i = 0; i < m; i++)
    {
        deriv += (w * x[i] + b - y[i]);
    }

    return deriv / m;
}

int main(){
    data d;
    d.dataset();
    std::cout << "Data points loaded: " << d.x.size() << std::endl;
    double w{0};
    double b{0};
    const double n{0.001}; 

    for(int i = 0; i < 10000; i++)
    {
        w = w - n * deriv_w(d.x, d.y, w, b);
        b = b - n * deriv_b(d.x, d.y, w, b);
    }

    std::cout << "Estimated parameters:" << std::endl;
    std::cout << "w = " << w << std::endl;
    std::cout << "b = " << b << std::endl;
    return 0;
}