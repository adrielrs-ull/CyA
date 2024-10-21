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
/**
 * @brief Construct a new Alfabeto:: Alfabeto object
 * 
 */
Alfabeto::Alfabeto() {
  alfabeto_ = alfabeto_;
}
/**
 * @brief Construct a new Alfabeto:: Alfabeto object
 * 
 * @param alfabeto 
 */
Alfabeto::Alfabeto(std::set<symbol>& alfabeto) {
  alfabeto_ = alfabeto;
}
/**
 * @brief Getter del alfabeto
 * 
 * @return std::set<symbol> 
 */
std::set<symbol> Alfabeto::GetAlfabeto() {
  return alfabeto_;
}

/**
 * @brief Mostrar el alfabeto
 * 
 * @param os 
 * @param alfabeto 
 * @return std::ostream& 
 */
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

/**
 * @brief Inserción de alfabeto
 * 
 * @param is 
 * @param alfabeto 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, Alfabeto& alfabeto) {
  std::string aux;
  is >> aux;
  for (int i{0}; i < static_cast<int>(aux.size()); i++) {
    alfabeto.InsertarEnAlfabeto(aux[i]);
  }
  return is;
}

/**
 * @brief Añadir nuevos elementos al alfabeto
 * 
 * @param simbolo 
 */
void Alfabeto::InsertarEnAlfabeto(const symbol& simbolo) {
  alfabeto_.insert(simbolo);
}

/**
 * @brief Comprobar si un simbolo existe en el alfabeto
 * Hay que destacar que & no existe en el alfabeto pero está para que las epsilon transiciones puedan hacerse
 * @param simbolo 
 * @return true 
 * @return false 
 */
bool Alfabeto::ExisteEnAlfabeto(symbol simbolo) {
  if ((alfabeto_.find(simbolo) != alfabeto_.end()) || simbolo == '&') {
    return true;
  }
  return false;
}