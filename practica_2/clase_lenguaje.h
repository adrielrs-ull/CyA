#ifndef CLASE_LENGUAJE_H
#define CLASE_LENGUAJE_H
#include <iostream>
#include <set>
#include "clase_cadena.h"

class Lenguaje {
 public:
  Lenguaje();
  void AñadirCadena(Cadena& cadena);
  void EscribirLenguaje(std::ofstream&);

 private:
  std::set<Cadena> lenguaje_;
};


#endif