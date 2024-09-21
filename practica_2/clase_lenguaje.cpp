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
