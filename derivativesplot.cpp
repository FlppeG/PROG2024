#include <iostream>
#include <cmath>
#include <string>
#include <fstream>



double f(double x);
double fprime(double x);
double forwarddiff(double x, double h);
double centraldiff(double x, double h);
double richardsondiff(double x, double h, int p);

int main(int argc, char **argv) {

    double x = std::stod(argv[1]);
    double fp = fprime(x);

    std::ofstream fout("datos.txt");
    fout.precision(16);
    fout.setf(std::ios::scientific);
    
    for(double h = 1.0; h >= 1.0e-16; h = h/10.0) {
        
        double dfx = forwarddiff(x, h);
        double deltaf = std::fabs(1 - fp/dfx);
        double dcx = centraldiff(x, h);
        double deltac = std::fabs(1 - fp/dcx);
        double drcx = richardsondiff(x, h, 2);
        double deltarc = std::fabs(1 - fp/drcx);

        fout << x << "  " << h 
            << "  " << dfx << "  " << deltaf
            << "  " << dcx << "  " << deltac
            << "  " << drcx << "  " << deltarc
            << "  \n";
  
    }
   

    fout.close();

return 0;
}

double f(double x) {
    return std::sin(x*x);
}

double fprime(double x) {
    return (2*x)*(cos(x*x));
}

double forwarddiff(double x, double h) {
    return (f(x+h)-f(x))/h;
}

double centraldiff(double x, double h) {
    return (f(x+h)-f(x-h))/(2*h);
}

double richardsondiff(double x, double h, int p) {
    return ((std::pow(2.0, p)*forwarddiff(x, h/2)) - forwarddiff(x, h))/(std::pow(2.0, p) - 1);
}