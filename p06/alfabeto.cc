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
// Creo un objeto alfabeto para esta nueva estructura con sus funciones de mostrar e insertar en el alfabeto
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include <set>
#include "alfabeto.h"

Alfabeto::Alfabeto() {
  alfabeto_ = alfabeto_;
}

Alfabeto::Alfabeto(std::set<symbol>& alfabeto) {
  alfabeto_ = alfabeto;
}

std::set<symbol> Alfabeto::GetAlfabeto() {
  return alfabeto_;
}

//symbol es un typedef de char
//Esta función la usamos para mostrar el alfabeto en el archivo de salida
std::ostream& operator<<(std::ostream& os, Alfabeto& alfabeto) {
  int counter{0};
  //recorro el set con un contador para saber cuàndo llego al final y poder cerrar las llaves
  for (symbol simbolo : alfabeto.GetAlfabeto()) {
    if (counter == 0) {
      os << "{";
    }
    
    if (counter == static_cast<int>(alfabeto.GetAlfabeto().size()) - 1) {
      os << simbolo << "}" << std::endl;
    } else {
      os << simbolo << ", ";
    }
    counter++;
  }
  return os;
}

std::istream& operator>>(std::istream& is, Alfabeto& alfabeto) {
  std::string aux;
  is >> aux;
  for (int i{0}; i < static_cast<int>(aux.size()); i++) {
    alfabeto.InsertarEnAlfabeto(aux[i]);
  }
  return is;
}

//Esta función sirve para insertar en el set el nuevo simbolo
void Alfabeto::InsertarEnAlfabeto(const symbol& simbolo) {
  alfabeto_.insert(simbolo);
}

bool Alfabeto::ExisteEnAlfabeto(symbol simbolo) {
  if (alfabeto_.find(simbolo) != alfabeto_.end()) {
    return true;
  }
  return false;
}