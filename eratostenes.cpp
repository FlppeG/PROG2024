#include <iostream>
#include <vector>

int main() {
    // Solicitar al usuario que ingrese un número límite
    long limite;
    std::cout << "Introduce un número: ";
    std::cin >> limite;

    // Manejar el caso en el que el límite sea menor que 2
    if (limite < 2) {
        std::cout << "La suma de los números primos menores o iguales a " << limite << " es: 0" << std::endl;
        return 0;
    }

    // Crear un vector de booleanos para marcar números como primos o no
    std::vector<bool> esPrimo(limite + 1, true);
    esPrimo[0] = esPrimo[1] = false; // 0 y 1 no son primos

    // Criba de Eratóstenes para marcar números compuestos
    for (long i = 2; i * i <= limite; ++i) {
        if (esPrimo[i]) {
            for (long j = i * i; j <= limite; j += i) {
                esPrimo[j] = false;
            }
        }
    }

    // Sumar todos los números primos
    long sumaPrimos = 0;
    for (long i = 2; i <= limite; ++i) {
        if (esPrimo[i]) {
            sumaPrimos += i;
        }
    }

    // Imprimir la suma de los números primos
    std::cout << "La suma de los números primos menores o iguales a " << limite << " es: " << sumaPrimos << std::endl;
    return 0;
}
