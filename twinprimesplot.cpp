#include <iostream>
#include <cmath>
#include <string>

bool isPrime(long n);
int nth_twin_primesdata(long n); 

int main() {
   
    for (int ii = 1; ii <= 100; ++ii) {
        int prime1 = nth_twin_primesdata(ii);
        int prime2 = prime1 + 2;
        std::cout << ii << "," << sqrt(( prime1 * prime1 ) + ( (prime2) * (prime2) )) << "\n";
     
    }
    
    return 0;
}

bool isPrime(long n) {
    for (long ii = 2; ii*ii <= n; ++ii)
        if (n%ii == 0) return false;

    return true;
}

int nth_twin_primesdata(long n) {
    long counter = 0;
    for(int ii = 2; ; ++ii) {
        if (isPrime(ii) and isPrime(ii+2)) {
            counter++;
            if (counter == n) {
                return ii;
            }
        }
    }
}