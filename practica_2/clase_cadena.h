#ifndef CLASE_CADENA_H
#define CLASE_CADENA_H
#include <iostream>
#include <vector>
#include <set>
#include "clase_alfabeto.h"

typedef char symbol;

class Cadena {
 public:
  Cadena();
  Cadena(const std::string& string);
  std::string GetCadena() const;
  void SetCadena(symbol&);
  friend std::istream& operator>>(std::istream& is, Cadena& string);
  friend std::ostream& operator<<(std::ostream& os, Cadena& string);
  bool operator<(const Cadena& other) const;
  bool operator!=(const Cadena& other) const;
  bool operator==(const Cadena& other) const;
  Cadena Potencia(const int);
  Cadena Inversa();
  std::set<Cadena> Prefijos();
  std::set<Cadena> Sufijos();
  std::set<symbol> AlfabetoAsociado(Alfabeto&);
  int Longitud();
 private:
  std::string cadena_;
};



#endif