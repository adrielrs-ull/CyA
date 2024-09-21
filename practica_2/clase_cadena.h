#ifndef CLASE_CADENA_H
#define CLASE_CADENA_H
#include <iostream>
#include <vector>

typedef char symbol;

class Cadena {
 public:
  Cadena();
  Cadena(const std::string& string);
  std::string GetCadena() const;
  void SetCadena(symbol&);
  friend std::istream& operator>>(std::istream& is, Cadena& string);
  bool operator<(const Cadena& other) const;
 private:
  std::string cadena_;
};



#endif