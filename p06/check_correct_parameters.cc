// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 17/09/2024
// Contiene la funci´on CheckCorrectParameters
// Para comprobar que los elementos introducidos por la terminal son los correctos, además de brindar la opciónde ayuda y mostrar
// el método de empleo en caso de error
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include <cstring>
#include <string>
#include "check_correct_parameters.h"

/**
 * @brief Función que comprueba que el número de parámetros pasados al ejecutable sea el correcto e imprime información sobre él
 * 
 * @param argc 
 * @param argv 
 * @param kLimit 
 * @return true 
 * @return false 
 */
bool CheckCorrectParameters(int argc, char* argv[], const int kLimit) {
  if (argc == 1) {
    std::cout << "Modo de empleo: ./p06_automata_simulator input.fa input.txt" << std::endl;
    std::cout << "Pruebe ’p06_automata_simulator --help’ para más información." << std::endl;
    return false;
  } else {
    std::string help = argv[1];
    if (argc == kLimit) {
      return true;
    } else if (argc == 2 && help == "--help") {
      std::cout << "Uso: p06_automata_simulator [opciones]\n";
      std::cout << "Opciones:\n";
      std::cout << "  --help    Muestra este mensaje de ayuda y termina\n";
      std::cout << "\nFormato del fichero de especificación del autómata finito:\n";
      std::cout << "  - Línea 1: Símbolos del alfabeto separados por espacios.\n";
      std::cout << "  - Línea 2: Número total de estados del autómata.\n";
      std::cout << "  - Línea 3: Estado de arranque del autómata.\n";
      std::cout << "  - A continuación, una línea para cada estado con:\n";
      std::cout << "    * Número identificador del estado.\n";
      std::cout << "    * Un 1 si es un estado de aceptación, 0 en caso contrario.\n";
      std::cout << "    * Número de transiciones que posee el estado.\n";
      std::cout << "    * Detalle de cada transición con:\n";
      std::cout << "      - Símbolo de entrada necesario para la transición (use '&' para cadena vacía).\n";
      std::cout << "      - Estado destino de la transición.\n";
      std::cout << "\nEjemplo de fichero .fa:\n";
      std::cout << "  a b\n";
      std::cout << "  3\n";
      std::cout << "  0\n";
      std::cout << "  0 0 2 a 1 b 2\n";
      std::cout << "  1 1 1 b 2\n";
      std::cout << "  2 0 1 a 0\n";
      return false;
    }
}