#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using fptr = double(double);
using dptr = double(fptr fun, double, double);

double f(double x);
double g(double x);
double forwarddiff(fptr fun, double x, double h);
double centraldiff(fptr fun, double x, double h);
double richardsondiff(dptr dx, double x, double h);

int main(int argc, char **argv) {

    double x = std::stod(argv[1]);
    double fp = g(x);

    std::ofstream fout("datos.txt");
    fout.precision(10);
    fout.setf(std::ios::scientific);
    
    for(double h = 1.0; h >= 1.0e-16; h = h/10.0) {
        
        double dfx = forwarddiff(f ,x, h);
        double deltaf = std::fabs(1 - fp/dfx);
        
        double dcx = centraldiff(f, x, h);
        double deltac = std::fabs(1 - fp/dcx);

        double drfx = richardsondiff(forwarddiff, x, h);
        double deltarf = std::fabs(1 - fp/drfx);

        double drcx = richardsondiff(centraldiff, x, h);
        double deltarc = std::fabs(1 - fp/drcx);

        fout << x << "," << h << "," << dfx << "," << deltaf
             << "," << dcx << "," << deltac << "," << drfx 
             << "," << deltarf << "," << drcx << "," << deltarc
             << "\n";
  
    }
   

    fout.close();

    return 0;
}

double f(double x) {
    return std::sin(x*x);
}

double g(double x) {
    return (2*x)*(cos(x*x));
}

double forwarddiff(fptr fun, double x, double h) {
    return (fun(x+h)-fun(x))/h;
}

double centraldiff(fptr fun, double x, double h) {
    return (fun(x+h)-fun(x-h))/(2*h);
}

double richardsondiff(dptr dx, double x, double h) {
    return ((std::pow(2.0, 2)*dx(f, x, h/2)) - dx(f, x, h))/(std::pow(2.0, 2) - 1);
}

