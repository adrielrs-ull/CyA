#ifndef ALFABETO_CLASE_H
#define ALFABETO_CLASE_H

#include <iostream>
#include <set>
#include <fstream>

class Alfabeto {
 public:
  //Dejo el constructor y destructor por defecto
  void MostrarAlfabeto(std::ofstream&);
  void InsertarEnAlfabeto(const char&);

 private:
  std::set<char> alfabeto_;
};


#endif