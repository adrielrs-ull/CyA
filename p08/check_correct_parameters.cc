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
    std::cout << "Modo de empleo: ./Grammar2CNF input.gra output.gra" << std::endl;
    std::cout << "Pruebe ‘Grammar2CNF --help’ para más información." << std::endl;
    return false;
  }
  std::string help = argv[1];
  if (argc == kLimit) {
    return true;
  } else if (argc == 2 && help == "--help") {
      std::cout << "Usage: ./Grammar2CNF input.gra output.gra\n\n";
      std::cout << "Grammar2CNF is a program that reads a .gra file containing the specification of a\n";
      std::cout << "context-free grammar and generates another .gra file with an equivalent grammar\n";
      std::cout << "in Chomsky Normal Form (CNF), where L(G_in) = L(G_out).\n\n";
      std::cout << "Before conversion, the program verifies that the input grammar G_in has no unit or\n";
      std::cout << "empty productions. Note: The program does not check for useless symbols or productions\n";
      std::cout << "for simplicity. The transformation to CNF is done following Algorithm 1.\n\n";
      
      std::cout << "Command-line Usage:\n";
      std::cout << "  $ ./Grammar2CNF input.gra output.gra\n";
      std::cout << "Where 'input.gra' and 'output.gra' are the filenames specifying the input and output\n";
      std::cout << "grammars respectively. Run './Grammar2CNF --help' to view this help message.\n\n";
      
      std::cout << "File Format (.gra):\n";
      std::cout << "The .gra files are plain text files containing the defining elements of a grammar\n";
      std::cout << "G ≡ (Σ, V, S, P) in the following order:\n";
      std::cout << "  1. Alphabet symbols (Σ):\n";
      std::cout << "     - A line containing N, the number of symbols in the alphabet, followed by\n";
      std::cout << "       N lines, each containing a single printable character symbol from the alphabet.\n";
      std::cout << "  2. Non-terminal symbols (V):\n";
      std::cout << "     - A line with V, the number of non-terminal symbols, followed by V lines with\n";
      std::cout << "       each line containing an alphanumeric string (without spaces). The first\n";
      std::cout << "       symbol in this list is the start symbol.\n";
      std::cout << "  3. Productions (P):\n";
      std::cout << "     - A line containing P, the number of productions, followed by P lines each\n";
      std::cout << "       specifying a production in the format 'A α' where α ∈ (Σ ∪ V)*. This is a\n";
      std::cout << "       sequence of terminals and/or non-terminals. The empty string (ϵ) is represented\n";
      std::cout << "       by the character '&'.\n\n";
      
      std::cout << "Example of a .gra File Format:\n";
      std::cout << "For a grammar conversion example to CNF, the .gra file format might look like this:\n";
      std::cout << "  3\n  a\n  b\n  c\n  3\n  S\n  X\n  Y\n  13\n";
      std::cout << "  S aXbX\n  S abX\n  S aXb\n  S ab\n  X aY\n  X bY\n  X a\n  X b\n";
      std::cout << "  Y aY\n  Y bY\n  Y a\n  Y b\n  Y c\n\n";
      
      std::cout << "This example indicates:\n";
      std::cout << "  - 3 terminal symbols: 'a', 'b', 'c'.\n";
      std::cout << "  - 3 non-terminal symbols: 'S', 'X', 'Y', with 'S' as the start symbol.\n";
      std::cout << "  - 13 productions for the grammar.\n\n";
      std::cout << "For further details, refer to the documentation.\n";
      return false;
    }
    return false;
}