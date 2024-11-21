#include <iostream>
#include <string>
#include <cmath>

//Declaración de la función que calcula el factor primo más grande de un número.
long long maxprimefact(long long num);

int main() {
    
    //Declaración de la variable que almacenará el número elegido para calcular su factor primo más grande.
    std::string input;
        std::cout << "Ingrese un numero: ";
        std::cin >> input;
    
    //Con std::stoll, se lee el valor numérico de la variable string y lo transforma a long long.
    long long num = std::stoll(input);

    //Se imprime en pantalla el factor primo más grande de un número n.
    std::cout << "El factor primo mas grande es: " << maxprimefact(num) << "\n";

    return 0;
}


// Función que calcula el factor primo más grande de un número
long long maxprimefact(long long num) {
    
    //Se inicializa la variable que almacena el factor primo más grande.
    long long maxFactor = 0;

    // Usamos un ciclo for para dividir por 2 repetidamente. 
    //Como no se inicializa una variable en la primer ranura del ciclo for, solo se pone un ;.
    for (; num % 2 == 0; num /= 2) {
        
        maxFactor = 2;
    
    }

    //Declaración e inicialización de la variable j para optimizar los cálculos del ciclo for. 
    //Concretamente, esto permite que no se calcule la raiz cuadrada de num por cada iteración del ciclo for.
    long long j = sqrt(num); 
    
    // Usamos un ciclo for para dividir por números impares.
    for (long long i = 3; i <= j; i += 2) {
        
        for (; num % i == 0; num /= i) {
            
                maxFactor = i;
                j = sqrt(num);
        
        }
    }

    // Si num es un número primo mayor que 2.
    if (num > 2) {
        
        maxFactor = num;
    
    }

return maxFactor;
}
