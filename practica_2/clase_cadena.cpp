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

//constructor por defecto
Cadena::Cadena() {
  cadena_ = "";
}

//constructor predefinido
Cadena::Cadena(const std::string& string) {
  cadena_ = string;
}

//getter
std::string Cadena::GetCadena() const {
  return cadena_;
};

//setter
void Cadena::SetCadena(symbol& simbolo) {
  cadena_.push_back(simbolo);
}

//sobrecarga de inserción
std::istream& operator>>(std::istream& is, Cadena& string) {
  is >> string.cadena_;
  return is;
}

//esto es para que el set los ordene por tamaño y no por orden alfabético porque si no no se imprimiría en el orden correcto
bool Cadena::operator<(const Cadena& other) const {
  if (cadena_.size() != other.GetCadena().size()) {
    return cadena_.size() < other.GetCadena().size();
  }
  return cadena_ < other.GetCadena();
}