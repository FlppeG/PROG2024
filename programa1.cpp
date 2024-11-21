#include <iostream>
#include <cmath>

// Declaración de las funciones. isPrime verifica si un número es primo y sumPrime suma los primos menores o iguales a n.
bool isPrime(int n);
long long sumPrime(int n);

int main(void) {
    
    //Declaración de la variable que almacenará el número ingresado en la terminal 
    long long num;
        std::cout << "Introduce un numero: ";
        std::cin >> num;

    //Impresión en pantalla de la suma.
    std::cout << "La suma de los numeros primos menores o iguales a " << num << " es: " << sumPrime(num) << "\n";

return 0;
}

// Función para verificar si un número es primo.
bool isPrime(int n) {

    //Ciclo for para verificar los números primos menores o iguales a un número ingresado. Si es divisible por otro número, no es primo.
    for (int i = 2; i <= sqrt(n); ++i) {
       
        if (n % i == 0) 
            return false;  
    }
    
return true;
}

// Función para sumar los números primos menores o iguales a n.
long long sumPrime(int n) {
    
    //Declaración e inicialización de la variable que almacena la suma de los primos menores o iguales al número ingresado (int num).
    long long suma = 0;

        //Ciclo for para sumar todos los primos menores o iguales a el número ingresado (int num).
        for (int i = 2; i <= n; ++i) {
            
            if (isPrime(i) == true) {
                suma += i;
            }
        }

return suma;
}