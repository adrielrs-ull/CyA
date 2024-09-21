#ifndef ALFABETO_CLASE_H
#define ALFABETO_CLASE_H

#include <iostream>
#include <set>
#include <fstream>

//podemos usar el tipo char como simbolos
typedef char symbol;

class Alfabeto {
 public:
  //Dejo el constructor y destructor por defecto
  void MostrarAlfabeto(std::ofstream&);
  void InsertarEnAlfabeto(const char&);

 private:
  std::set<symbol> alfabeto_;
};


#endif