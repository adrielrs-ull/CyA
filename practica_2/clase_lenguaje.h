#ifndef CLASE_LENGUAJE_H
#define CLASE_LENGUAJE_H
#include <iostream>
#include <set>
#include "clase_cadena.h"

class Lenguaje {
 public:
  Lenguaje();
  Lenguaje(std::set<Cadena>&);
  void AñadirCadena(Cadena& cadena);
  friend std::ostream& operator<<(std::ostream& os, Lenguaje& lenguaje);
  std::set<Cadena> GetLenguaje();
 private:
  std::set<Cadena> lenguaje_;
};


#endif