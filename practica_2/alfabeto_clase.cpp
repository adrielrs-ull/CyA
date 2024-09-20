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
#include "alfabeto_clase.h"

//Esta función la usamos para mostrar el alfabeto en el archivo de salida
void Alfabeto::MostrarAlfabeto(std::ofstream& salida) {
  int counter{0};
  for (char simbolo : alfabeto_) {
    if (counter == 0) {
      salida << "{";
    }
    
    if (counter == static_cast<int>(alfabeto_.size()) - 1) {
      salida << simbolo << "}" << std::endl;
    } else {
      salida << simbolo << ", ";
    }
    counter++;
  }
}

//Esta función sirve para insertar en el set el nuevo simbolo
void Alfabeto::InsertarEnAlfabeto(const char& simbolo) {
  alfabeto_.insert(simbolo);
}