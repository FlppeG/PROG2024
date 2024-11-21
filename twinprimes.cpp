#include <iostream>
#include <cmath>

bool isPrime(int n) {

    //Ciclo for para verificar los números primos menores o iguales a un número ingresado. Si es divisible por otro número, no es primo.
    for (int i = 2; i <= sqrt(n); ++i) {
       
        if (n % i == 0) 
            return false;  
    }
    
return true;
}

void nth_twin_primes(int n) {
    int count = 0;  // Contador de pares de primos gemelos encontrados
    int num = 3;    // Primer número impar a evaluar (los gemelos empiezan en 3 y 5)

    while (true) {
        if (isPrime(num) && isPrime(num + 2)) {  // Verifica si `num` y `num + 2` son primos
            ++count;  // Incrementa el contador
            if (count == n) {  // Si se encuentra la nth pareja
                std::cout << "La " << n << "th pareja de primos gemelos es: (" 
                          << num << ", " << num + 2 << ")\n";
                return;
            }
        }
        num += 2;  // Avanzamos al siguiente número impar
    }
return;
}

int main() {
    int n;
    std::cout << "Ingrese el valor de n para encontrar la nth pareja de primos gemelos: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Por favor, ingrese un número entero positivo mayor que 0.\n";
    } else {
        nth_twin_primes(n);
    }

    return 0;
}