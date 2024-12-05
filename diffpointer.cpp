#include <iostream>
#include <cmath>
#include <string>

//Punteros a funciones (fptr para derivadas, dptr para richardson).
using fptr = double(double);
using dptr = double(fptr fun, double, double);

//Declaración de funciones.
double f(double x);
double g(double x);
double forwarddiff(fptr fun, double x, double h);
double centraldiff(fptr fun, double x, double h);
double richardsondiff(dptr dx, double x, double h, int p);

int main(int argc, char **argv) {

    //Declaración de la variable x y de una variable auxiliar que almacene el valor de f prima (g(x)).
    double x = std::stod(argv[1]);
    double fp = g(x);
    
    //Para obtener los resultados con precisión de 16 cifras decimales y en notacón científica.
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    
    //Ciclo for para calcular las derivadas y la aproximación de Richardson con varios valores de h.
    for(double h = 1.0; h >= 1.0e-16; h = h/10.0) {
        
        //Forward derivative y su error.
        double dfx = forwarddiff(f ,x, h);
        double deltaf = std::fabs(1 - fp/dfx);
        
        //Central derivative y su error.
        double dcx = centraldiff(f, x, h);
        double deltac = std::fabs(1 - fp/dcx);

        //Aproximación de Richardson para forward derivative de segundo orden y su error.
        double drfx = richardsondiff(forwarddiff, x, h , 2);
        double deltarf = std::fabs(1 - fp/drfx);

        //Aproximación de Richardson para central derivative de segundo orden y su error.
        double drcx = richardsondiff(centraldiff, x, h, 2);
        double deltarc = std::fabs(1 - fp/drcx);

        //Imprimir los valores designados anteriormente.
        std::cout << x << "  " << h 
            << "  " << dfx << "  " << deltaf
            << "  " << dcx << "  " << deltac
            << "  " << drfx << "  " << deltarf
            << "  " << drcx << "  " << deltarc
            << "  \n";
    }

    return 0;
}

//Funciones a derivar.
double f(double x) {
    return std::sin(x*x);
}

double g(double x) {
    return (2*x)*(cos(x*x));
}

//Derivadas y aproximación de Richardson.
double forwarddiff(fptr fun, double x, double h) {
    return (fun(x+h)-fun(x))/h;
}

double centraldiff(fptr fun, double x, double h) {
    return (fun(x+h)-fun(x-h))/(2*h);
}

double richardsondiff(dptr dx, double x, double h, int p) {
    return ((std::pow(2.0, p)*dx(f, x, h/2)) - dx(f, x, h))/(std::pow(2.0, p) - 1);
}

