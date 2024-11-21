#include <iostream>
#include <iomanip>
#include <cmath>
#define M_PI 3.14159265358979323846 //Definición del "valor real de Pi (porque mi compu no lo agarraba bien pipipipi)"

//Declaración de la función de aproximación de Pi.
long double pi_aprox(int n);

int main() {
    
    
    //Ciclo for para calcular la aproximación de Pi con n términos, de 1 a 20.
    for(int n = 1; n <= 20; ++n) {
           
    //Declaración e impresión de la aproximación de Pi con n términos y con una precisión decimal de 15.
    long double pi = pi_aprox(n);
    std::cout << "Aproximacion de pi con " << n << " terminos: ";
    std::cout << std::setprecision(18) << pi << "\n";
                
    //Declaración e impresión del error relativo de la aproximación de Pi con n términos con el valor real.
    long double errpi = fabsl((pi - M_PI) / M_PI); 
    std::cout << "Error relativo de la aproximacion con el valor real: ";
    std::cout << std::fixed << std::setprecision(18) << errpi << "\n\n";

    }
        //Aclaración sobre la computación de las aproximaciones de Pi y su error relativo.
        std::cout << "La suma BBP converge muy rapido a Pi, porl lo cual, desde \n"
            << "n=10 las aproximaciones son tan buenas que son mas pequenas que el \n"
            << "que el minimo valor representable para la variable long double (1e-18).\n"
            << "Con todo, desde la iteracion 10 el error permanece en 0 y las aproximaciones \n"
            << "no se computan.";

    return 0;
}

//Función de aproximación de Pi.
long double pi_aprox(int n) {

    //Inicialización de la variable Pi.
    long double pi = 0.0;

    //Ciclo for para calcular n términos en la fórmula de Bailey-Borwein-Plouffe.
    for (int k = 0; k <= n; ++k) {

    //Se divide la fórmula de BBP en el término con potencia (powk) y en el término con fracciones (sumak).
    long double powk = 1.0 / std::pow(16, k);
    long double sumak = (4.0 / (8.0 * k + 1)) - (2.0 / (8.0 * k + 4)) 
                     - (1.0 / (8.0 * k + 5)) - (1.0 / (8.0 * k + 6));

    //Sumar el término calculado a la aproximación de Pi.
    pi += powk * sumak;

    }
    return pi;
}