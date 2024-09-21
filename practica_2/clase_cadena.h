#ifndef CLASE_CADENA_H
#define CLASE_CADENA_H
#include <iostream>
#include <vector>

class Cadena {
 public:
  Cadena();
  Cadena(const std::string& string);
  std::string GetCadena();
  friend std::ifstream& operator>>(std::istream& is, Cadena string);

 private:
  std::string cadena_;
};



#endif