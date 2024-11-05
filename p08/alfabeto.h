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
  Alfabeto();
  Alfabeto(std::set<symbol>&);
  bool ExisteEnAlfabeto(symbol);
  std::set<symbol> GetAlfabeto();
  void MostrarAlfabeto();
  int GetSizeAlfabeto() const;
  friend std::ostream& operator<<(std::ostream&, Alfabeto&);
  friend std::istream& operator>>(std::istream&, Alfabeto&);
  void InsertarEnAlfabeto(const symbol&);

 private:
  std::set<symbol> alfabeto_;
};


#endif