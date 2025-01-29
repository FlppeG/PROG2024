#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using std::sin;
using std::cos;

void setarm(double vx, double vy, double vz, double rotx, double roty, double rotz);


void matmul(const std::vector<double> &A, const std::vector<double> &B, int m,
            int n, int p, std::vector<double> &C);

int main(int argc, char **argv) {

    //Declaración de variables a utilizar.
    double vx = std::stod(argv[1]);
    double vy = std::stod(argv[2]);
    double vz = std::stod(argv[3]);

    double thetax = std::stod(argv[4]);
    double thetay = std::stod(argv[5]);
    double thetaz = std::stod(argv[6]);

    std::cout << "Rotated vector: (" << vx << ", " << vy << ", " << vz << ")\n";

    return 0;
}


void matmul(const std::vector<double> &A, const std::vector<double> &B, int m,
            int n, int p, std::vector<double> &C)
{
	// check dimensions
	assert(A.size() == m * n);
	assert(B.size() == n * p);
	assert(C.size() == m * p);

	// C = A * B
	for (int ii = 0; ii < m; ++ii) {
		for (int jj = 0; jj < p; ++jj) {
			double result = 0.0;
			for (int kk = 0; kk < n; ++kk) {
				result += A[ii*n + kk] * B[kk*p + jj];
			}
			C[ii*p + jj] = result;
		}
	}
}

void setarm(double &vx, double &vy, double &vz, double &thetax, double &thetay, double &thetaz) {

    //Declaración de matrices de rotación, del vector de posición inicial y del contenedor del vector rotado.
    std::vector<double> rotx = {1, 0, 0,
                                0, cos(thetax), -sin(thetax),
                                0, sin(thetax), cos(thetax)};
    
    std::vector<double> roty = {cos(thetay), 0, sin(thetay),
                                0, 1, 0,
                                -sin(thetay), 0, cos(thetay)};
    
    std::vector<double> rotz = {cos(thetaz), -sin(thetaz), 0,
                                sin(thetaz), cos(thetaz), 0,
                                0, 0, 1};

    //Declaración de los vectores de posición inicial y final.
    std::vector<double> v = {vx, vy, vz};
    std::vector<double> vrot = {0.0, 0.0, 0.0};
    

    std::vector<double> C(3*3, 0.0);
    matmul(rotx, roty, 3, 3, 3, C);
}     
