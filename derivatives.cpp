#include <iostream>
#include <cmath>
#include <string>


double f(double x);
double forwarddiff(double x, double h);
double centraldiff(double x, double h);

int main(int argc, char **argv) {

    double x = std::stod(argv[1]);
    double h = std::stod(argv[2]);

    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    
    std::cout << x << "  " << h << "  " 
            << forwarddiff(x,h) << "  " 
            << centraldiff(x,h) << std::endl;

return 0;
}

double f(double x) {
    return std::sin(x*x);
}

double forwarddiff(double x, double h) {
    return (f(x+h)-f(x))/h;
}

double centraldiff(double x, double h) {
    return (f(x+h)-f(x-h))/(2*h);
}