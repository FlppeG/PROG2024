#include <iostream>

//Declaración de la función que calcula la suma de los términos impares de Fibonacci menores o iguales a n.
int sumfibonacci(int n);

int main() {
    
    //Declaración en inicialización desde la terminal de la variable n.
    int n;
        std::cout << "Ingrese un numero entero n >= 2: ";
        std::cin >> n;

    //Imprime la suma de los términos impares de la secuencia de Fibonnacci menores o iguales a n.
    std::cout << "La suma de los términos impares de la secuencia de Fibonacci menores o iguales a " << n << " es: " << sumfibonacci(n) << "\n";

    return 0;
}

// Función que calcula la suma de los términos impares de Fibonacci menores o iguales a n.
int sumfibonacci(int n) {
    
    //Declaración e inicialización de los dos primeros términos de la susesión de Fibonacci.
    int a = 1, b = 2;

    //Declaración e inicialización de la variable que almacenará la suma de los terminos impares de la susesión de Fibonacci.
    int sumaImpares = 0;

    //Ciclo while para a menor o igual que n. 
    while (a <= n) {
        
        //Si a es impar (su módulo no es cero), entonces se suma 
        if (a % 2 != 0) {
        
            sumaImpares += a;
        
        }

        //Se calcula el siguiente término de la secuencia de Fibonacci como siguiente = a + b y se actualizan los valores de a y b.
        int siguiente = a + b;
            a = b;
            b = siguiente;
    }

return sumaImpares;
}

