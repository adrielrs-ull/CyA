// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 17/09/2024
// Clase cadena para la práctica basada en std::string
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include "clase_cadena.h"

//constructor por defecto
Cadena::Cadena() {
  cadena_ = "";
}

//constructor predefinido
Cadena::Cadena(const std::string& string) {
  cadena_ = string;
}

//getter
std::string Cadena::GetCadena() const {
  return cadena_;
};

//setter
void Cadena::SetCadena(symbol& simbolo) {
  cadena_.push_back(simbolo);
}

std::ostream& operator<<(std::ostream& os, Cadena& string) {
  os << string.GetCadena();
  return os;
}

//sobrecarga de inserción
std::istream& operator>>(std::istream& is, Cadena& string) {
  is >> string.cadena_;
  return is;
}

//esto es para que el set los ordene por tamaño y no por orden alfabético porque si no no se imprimiría en el orden correcto
bool Cadena::operator<(const Cadena& other) const {
  if (cadena_.size() != other.GetCadena().size()) {
    return cadena_.size() < other.GetCadena().size();
  }
  return cadena_ < other.GetCadena();
}

//este operador sirve para comparar que dos cadenas sean distintas
bool Cadena::operator!=(const Cadena& other) const {
  if (cadena_ != other.GetCadena()) {
    return true;
  }
  return false;
  
}

bool Cadena::operator==(const Cadena& other) const {
  if (cadena_ == other.GetCadena()) {
    return true;
  }
  return false;
  
}

//añade al final de una cadena otra
Cadena Cadena::Potencia(const int numero) {
  std::string aux{""};
  for (int i{0}; i < numero; i++) {
    aux += cadena_;
  }
  Cadena cadena_potencia(aux);
  return cadena_potencia;
}

Cadena Cadena::Inversa() {
  Cadena cadena_inversa;
  //añado a una nueva cadena los símbolos en orden invertido  
  for (int i{static_cast<int>(cadena_.size()) - 1}; i >= 0; i--) {
    cadena_inversa.SetCadena(cadena_[i]);
  }
  return cadena_inversa;
}

std::set<Cadena> Cadena::Sufijos() {
  std::set<Cadena> lenguaje;
      
  //el bucle funciona de tal manera que lo que sería el límite va aumentando hasta el tamaño de la cadena. Por tanto el tamaño del prefijo aumenta tmb
  for (int i{static_cast<int>(cadena_.size()) - 1}; i >= 0 ; i--) {
  
    //esta cadena auxiliar nos sirve para los prefijos
    Cadena sufijo;
    for (int j{i}; j < static_cast<int>(cadena_.size()); j++) {
        
      //añado los simbolos de la cadena a prefijos
      sufijo.SetCadena(cadena_[j]);
    }
        
    //añado el prefijo al lenguaje
    lenguaje.insert(sufijo);
  }
  return lenguaje;
}

std::set<Cadena> Cadena::Prefijos() {
  std::set<Cadena> lenguaje;
  //el bucle funciona de tal manera que lo que sería el límite va aumentando hasta el tamaño de la cadena. Por tanto el tamaño del prefijo aumenta también
  for (int i{0}; i < static_cast<int>(cadena_.size()); i++) {
  
    //esta cadena auxiliar nos sirve para los prefijos
    Cadena prefijo;
    for (int j{0}; j <= i; j++) {
    
      //añado los simbolos de la cadena a prefijos
      prefijo.SetCadena(cadena_[j]);
    }
        
    //añado el prefijo al lenguaje
    lenguaje.insert(prefijo);
  }
  return lenguaje;
}

std::set<symbol> Cadena::AlfabetoAsociado(Alfabeto& alfabeto) {
  std::set<symbol> aux;
  //si un simbolo de la primera cadena está en el alfabeto lo inserto en su alfabeto asociado
  for (int i{0}; i < static_cast<int>(cadena_.size()); i++) {
    for (symbol elem : alfabeto.GetAlfabeto()) {
      if (cadena_[i] == elem) {
        aux.insert(cadena_[i]);
      }
    }
  }
  return aux;
}

int Cadena::Longitud() {
  int longitud{static_cast<int>(cadena_.size())}; //le doy el valor del size de la cadena a la variable longitud
  return longitud;
}