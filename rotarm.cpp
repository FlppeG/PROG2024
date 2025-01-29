#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using std::sin;
using std::cos;

// Declaración de funciones.
void setarm(double &vx, double &vy, double &vz, double thetax, double thetay, double thetaz);

void matmul(const std::vector<double> &A, const std::vector<double> &B, int m,
            int n, int p, std::vector<double> &C);

void matvecmul(const std::vector<double> &A, const std::vector<double> &v, int m,
            int n, std::vector<double> &result);

void checkargs(int argc, char **argv);

int main(int argc, char **argv) {
    
    // Argumentos de entrada.
    double vx = std::stod(argv[1]);
    double vy = std::stod(argv[2]);
    double vz = std::stod(argv[3]);
    double thetax = std::stod(argv[4]);
    double thetay = std::stod(argv[5]);
    double thetaz = std::stod(argv[6]);

    // Rotar el vector (vx, vy, vz) con la función setarm.
    setarm(vx, vy, vz, thetax, thetay, thetaz);

    // Imprimir el vector rotado.
    std::cout << "Vrot = (" << vx << ", " << vy << ", " << vz << ")\n";

    return 0;
}

// Revisar los argumentos del programa.
void checkargs(int argc, char **argv) 
{
    if (argc != 7) {
        std::cerr << "Usage: " << argv[0] << " vx vy vz thetax thetay thetaz\n";
        std::exit(1);
    }
}

// Multiplicación entre matrices.
void matmul(const std::vector<double> &A, const std::vector<double> &B, int m,
            int n, int p, std::vector<double> &C)
{
    // Revisar dimensiones de las matrices a multiplicar.
    assert(A.size() == m * n);
    assert(B.size() == n * p);
    assert(C.size() == m * p);

    // Ciclos for anidados para recorrer los ínidices y posteriormente multiplicarlos.
    for (int ii = 0; ii < m; ++ii) {
        for (int jj = 0; jj < p; ++jj) {
            double result = 0.0;
            for (int kk = 0; kk < n; ++kk) {
                result += A[ii * n + kk] * B[kk * p + jj];
            }
            C[ii * p + jj] = result;
        }
    }
}

// Multiplicación de matrices con vectores.
void matvecmul(const std::vector<double> &A, const std::vector<double> &v, int m,
            int n, std::vector<double> &result) 
{
    // Revisar las dimensiones de los elementos a multiplicar.
    assert(A.size() == m * n);
    assert(v.size() == n);
    assert(result.size() == m);

    // Ciclos for anidados para recorrer los inidices y posteriormente multiplicarlos.
    for (int ii = 0; ii < m; ++ii) {
        result[ii] = 0.0;
        for (int jj = 0; jj < n; ++jj) {
            result[ii] += A[ii * n + jj] * v[jj];
        }
    }
}

// Aplicar la transformación de rotación al vector (vx, vy, vz).
void setarm(double &vx, double &vy, double &vz, double thetax, double thetay, double thetaz) 
{
    // Matrices de rotación.
    std::vector<double> rotx = {
        1, 0, 0,
        0, cos(thetax), -sin(thetax),
        0, sin(thetax), cos(thetax)};

    std::vector<double> roty = {
        cos(thetay), 0, sin(thetay),
        0, 1, 0,
        -sin(thetay), 0, cos(thetay)};

    std::vector<double> rotz = {
        cos(thetaz), -sin(thetaz), 0,
        sin(thetaz), cos(thetaz), 0,
        0, 0, 1 };

    // Combinar las rotaciones en el siguiente orden: R = rotz * roty * rotx. 
    //Temp es una matriz que guarda el resultado de rotz * roty. Luego, Temp se multiplica por rotx,
    //Terminando la combinación. 
    std::vector<double> temp(3 * 3, 0.0);
    std::vector<double> Rot(3 * 3, 0.0);
    matmul(rotz, roty, 3, 3, 3, temp);
    matmul(temp, rotx, 3, 3, 3, Rot);

    // Rotación del vector. Se multiplica el vector (vx, vy, vz) con la matriz de rotación combinada del paso anterior.
    std::vector<double> v = {vx, vy, vz};
    std::vector<double> vrot(3, 0.0);
    matvecmul(Rot, v, 3, 3, vrot);

    // Se actualizan las entradas del vector (vx, vy, vz).
    vx = vrot[0];
    vy = vrot[1];
    vz = vrot[2];
}
