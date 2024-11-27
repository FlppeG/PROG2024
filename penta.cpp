#include <iostream>
#include <string>
#include <cmath>

int pentaNum(int n);
bool isPenta(int n);
long long pentaindex(int n);

int main(int argc, char **argv) {

        int n = std::stoi(argv[1]);
    
        //for(int ii = 1,  jj = 1; ii, jj <= n; ++ii, ++jj) {
        for (int ii = 1; ii <= n; ++ii) {

            for (int jj = 1; jj <= n; ++jj) {  
            
            int suma = pentaNum(ii) + pentaNum(ii+jj); 
            int resta = abs(pentaNum(ii) - pentaNum(ii+jj));
            
                if(isPenta(suma) && isPenta(resta)) {
                    std::cout << pentaindex(ii) << "  " << pentaindex(ii + jj) << "  " << pentaNum(ii) << "  " << pentaNum(ii + jj) << "  " << suma << "  " << resta << std::endl;  
                } 
            }
        }

    return 0;
}

int pentaNum(int n) {
    return (n*((3*n)-1))/2;
}

bool isPenta(int n) {
    double k = (std::sqrt((24 * n) + 1) + 1)/6;
        //hace lo mismo que esta pendejada: if(k % 1 != 0).
        if (k == static_cast<int>(k)) {
            return true;
        } else {
            return false;
        }
        if(k < 1) {
            return false;
        }
}

long long pentaindex(int n) {
    double k = (std::sqrt((24 * n) + 1) + 1)/6;
    if(isPenta(n) == true) {
        return k;
    }
return k;
}