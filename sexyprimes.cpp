#include <iostream>
#include <cmath>
#include <string>

bool isPrime(int n);
void nth_sexy_primes(long n); 

int main(int argc, char **argv) {
    
    int n = std::stol(argv[1]);
    
    if (n <= 0) {
        std::cerr << "Por favor, ingrese un número entero positivo mayor que 0.\n";
    } else {
        nth_sexy_primes(n);
    }

    return 0;
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) 
            return false;  
    }
    
return true;
}

void nth_sexy_primes(long n) {
    long counter = 0;
    for(int ii = 2; ; ++ii) {
        if (isPrime(ii) and isPrime(ii+6)) {
            counter++;
            if (counter == n) {
                std::cout << "(" << ii << ", " << ii+6 << ")\n";
                break;
            }
        }
    }
}