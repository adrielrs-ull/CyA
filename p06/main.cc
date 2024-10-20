// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 6
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 20/10/2024
// Main del programa
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include "automata.h"
#include "check_correct_parameters.h"

/**
 * @brief main del programa
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
  std::ifstream definicion_automata(argv[1]);
  std::ifstream cadenas(argv[2]);
  if (CheckCorrectParameters(argc, argv, 3)) {
    Automata automata(definicion_automata);
    std::cout << automata << std::endl;
    automata.LeerCadenas(cadenas);
  }
  return 0;
}