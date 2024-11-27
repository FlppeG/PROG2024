#include <iostream>
#include <cmath>
#include <string>

bool isPrime(long n);
void nth_twin_primes(long n); 
/*
int main(int argc, char **argv) {
    
    int n = std::stol(argv[1]);
    
    if (n <= 0) {
        std::cerr << "Por favor, ingrese un número entero positivo mayor que 0.\n";
    } else {
        nth_twin_primes(n);
    }

    return 0;
}
*/
bool isPrime(long n) {
    for (long ii = 2; ii*ii <= n; ++ii)
        if (n%ii == 0) return false;

    return true;
}

void nth_twin_primes(long n) {
    long counter = 0;
    for(int ii = 2; ; ++ii) {
        if (isPrime(ii) and isPrime(ii+2)) {
            counter++;
            if (counter == n) {
                std::cout << "(" << ii << ", " << ii+2 << ")\n";
                break;
            }
        }
    }
}