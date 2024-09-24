// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 17/09/2024
// Contiene las funciones que actúan sobre la cadena vacía
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo
#include <iostream>
#include <fstream>
#include "cadena_vacia_funciones.h"

void CadenaVaciaAlfabeto(std::ostream& salida) {
  salida << "La cadena vacía denotada por '&' no tiene ningún alfabeto asociado." << std::endl;
}

void CadenaVaciaLongitud(std::ostream& salida) {
  salida << "La cadena vacía denotada por '&' tiene longitud 0." << std::endl;
}
