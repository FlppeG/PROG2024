#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

//Puntero para Fx y Fy.
using ForceComponent = double(double);

// Declaración de funciones.
double Fx(double x);
double Fy(double x);
double y(double x);
double dy_dx(double x);
double gauss_quadrature(int n, double a, double b, ForceComponent Fx, ForceComponent Fy);

int main() {
    
    double m = 1.2345; // mass in kg

    // Parámetros de integración
    int n = 100; // número de intervalos.
    double a = 0.0; // Inicio del intervalo. 
    double b = 1.0; // Final del intervalo.

    // Vectores que almacenan los valores de x, y y work.
    std::vector<double> x_values(n);
    std::vector<double> y_values(n);
    std::vector<double> work_values(n);

    // calcular el trabajo utilizando la cuadratura de Gauss. 
    double work = gauss_quadrature(n, a, b, Fx, Fy);

    // Dar valores de x e y y aproximar el trabajo realizado.
    for (int i = 0; i < n; ++i) {
        double x = a + i * (b - a) / n;
        x_values[i] = x;
        y_values[i] = y(x);
        work_values[i] = work * (i + 1) / n; 
    }

    // Calcular e imprimir la velocidad final.
    double v_final = std::sqrt(2 * work / m);
    std::cout << "La velocidad final es: " << v_final << " m/s" << std::endl;

    // Guardar los valores de x e y en un archivo.
    std::ofstream fout("datos.txt");

        for (int i = 0; i < n; ++i) {
            double v = std::sqrt(2 * work_values[i] / m); // Calcular v en cada paso
            fout << x_values[i] << "\t" << v << "\n"; // Guardar  x y v.
        }

        fout.close();

    return 0;
}

// Implementación de funciones 
double Fx(double x) {
    return std::log(std::sqrt(x)) + 1;
}

double Fy(double x) {
    double y = x * (1 - x); 
    return std::sin(std::pow(y, 2));
}

double y(double x) {
    return x * (1 - x);
}

double dy_dx(double x) {
    return 1 - 2 * x;
}

double gauss_quadrature(int n, double a, double b, ForceComponent Fx, ForceComponent Fy) {
    
    const double weights[2] = {1.0, 1.0};
    const double nodes[2] = {-1.0 / std::sqrt(3), 1.0 / std::sqrt(3)};

    double total_work = 0.0;

    for (int i = 0; i < n; ++i) {
        double x_start = a + i * (b - a) / n;
        double x_end = a + (i + 1) * (b - a) / n;
        double mid_point = 0.5 * (x_start + x_end);
        double half_width = 0.5 * (x_end - x_start);

        for (int j = 0; j < 2; ++j) {
            double x = mid_point + half_width * nodes[j];
            double dx = half_width;
            double dy = dy_dx(x) * dx;

            total_work += weights[j] * (Fx(x) * dx + Fy(x) * dy);
        }
    }

    return total_work;
}
