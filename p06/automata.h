#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <vector>
#include "alfabeto.h"

typedef char symbol;

class Automata {
 public:
  Automata(std::ifstream& archivo_entrada);
  Alfabeto GetAlfabeto() const;
  int GetNumeroEstados() const;
  std::set<int> GetEstadoArranque() const;
  std::map<std::pair<int, symbol>, std::set<int>> GetTransiciones() const;
  std::set<int> GetEstadosAceptacion() const;
  std::vector<int> GetTransicionesEstados() const;
  bool EsDeAceptacion(int);
  bool EstadoExistente(int);
  std::set<int> EpsilonTransicion(std::set<int>&);
  bool CadenaReconocida(const std::string&, std::set<int>&, int);
  void LeerCadenas(std::ifstream& archivo_entrada);
  friend std::ostream& operator<<(std::ostream&, Automata&);
 private:
  Alfabeto alfabeto_;
  int numero_estados_;
  std::set<int> estado_arranque_;
  std::map<std::pair<int, symbol>, std::set<int>> transiciones_;
  std::set<int> estados_aceptacion_;
  std::vector<int> transiciones_estados_;
  std::set<int> estados_automata_;
};

#endif