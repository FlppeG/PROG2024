#include <iostream>
#include <string>
#include <cmath> 

long suma_de_primos (long m);
bool sera_primo (long n);

int main(void) {
    
    std::string input;
        std::cout << "Ingrese un numero: ";
        std::cin >> input;
    
    long numerito {std::stol(input)};
    
    std::cout <<"la suma de los primos menores iguales a " << numerito <<" es:\n";
    std::cout << suma_de_primos(numerito) <<"\n";
    
return 0;
}

long suma_de_primos (long m) {
    
    if(m < 2) {
    return 0;

    } else {
        
        long suma{2};
            for (long k{3}; k <= m; k = k + 2) {

            if(sera_primo(k) == true) {
                suma = suma + k;
            }
        } 
    
    return suma;
    }  
}

bool sera_primo (long n) {

    if (n <= 1 or (n > 2 and n % 2 == 0)) {
        return false;
    }
    
    for (int c{3}; c <= std::sqrt(n) + 1; c = c + 2) {
        
        if(n % c == 0){
            
            return false;
        }
    }
      
return true;
}