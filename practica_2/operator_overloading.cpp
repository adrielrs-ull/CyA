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
// Sobrecarga del operador == para comparar dos strings
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include "operator_overloading.h"

//sobrecargo el operador pra comparar dos strings
bool operator==(const std::string& cadena1, const std::string& cadena2) {
  if (cadena1.size() == cadena2.size()) {
    for (int i{0}; i < static_cast<int>(cadena1.size()); i++) {
      if (cadena1[i] != cadena2[i]) {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}