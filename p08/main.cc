// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 8
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Definición Main del programa
// Referencias:
// Enlaces de inter´es

#include <iostream>
#include <fstream>
#include "grammar_cnf.h"

int main(int argc, char* argv[]) {
  std::ifstream archivo_entrada(argv[1]);
  std::ofstream archivo_salida(argv[2]);
  GrammarCNF grammar(archivo_entrada);
  grammar.MostrarGrammarInicial();
  grammar.NewGrammarCNF(archivo_salida);
  return 0;
}