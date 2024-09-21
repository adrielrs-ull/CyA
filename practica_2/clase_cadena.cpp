// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 17/09/2024
// Clase cadena para la práctica basada en std::string
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include "clase_cadena.h"

Cadena::Cadena(const std::string& string) {
  cadena_ = string;
}

std::string Cadena::GetCadena() {
  return cadena_;
};

std::ifstream& operator>>(std::istream& is, Cadena string) {
  is >> string.cadena_;
}
