// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 17/09/2024
// Clase lenguaje con atributos cadena
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo
#include <iostream>
#include <set>
#include "clase_cadena.h"
#include "clase_lenguaje.h"
#include <fstream>

//Constructor para la clase lenguaje
Lenguaje::Lenguaje() {
  Cadena cadena_vacía("&");
  lenguaje_.insert(cadena_vacía);
}

//Opcion de añadir las cadenas al lenguaje
void Lenguaje::AñadirCadena(Cadena& cadena) {
  lenguaje_.insert(cadena);
}

//Opcion para mostrar el lenguaje
void Lenguaje::EscribirLenguaje(std::ofstream& salida) {
  salida << "{";
  //recorro la cadena y cuando llegue al final cierro las llaves
  int counter{0};
  for (Cadena cadena : lenguaje_) {
    if (counter == static_cast<int>(lenguaje_.size()) - 1) {
      salida << cadena.GetCadena() << "}" << std::endl;
    } else {
      salida << cadena.GetCadena() << ",";
    }
    counter++;
  }
  
}
