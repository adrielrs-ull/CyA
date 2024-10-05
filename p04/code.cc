/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Informatica Basica
 *
 * @brief Ejercicios de programacion
 *        Version 1: Funcion factorial
 *
 * @see https://github.com/IB-2023-2024/IB-class-code-examples/
 */


/**
 * pepe
 * pepe
 */

/**
 * asdasdadasd
 */




/**
 * a
 * asd
 * asd
 */
#include <iostream>
#include <cassert>

// Función que calcula el factorial del argumento
int Factorial(int number) {
    switch (number) {
        case 0:
        case 1:
            return 1;
        default:
            int factorial = 1;
            for (int i = 1; i <= number; ++i) {
                factorial *= i;
            }
            return factorial;
    }
}

int main() {
    std::cout << "Introduzca el numero de factoriales a calcular: ";
    int limit;
    std::cin >> limit;
    for (int i = 1; i <= limit; ++i) {
        std::cout << i << "! = " << (double)Factorial(i) << std::endl;
    }
    return 0;
}
