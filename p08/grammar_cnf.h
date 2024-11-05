#ifndef GRAMMAR_CNF_H
#define GRAMAR_CNF_H

#include <iostream>
#include "alfabeto.h"
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class GrammarCNF {
 public:
  GrammarCNF(std::ifstream& archivo_entrada);
  bool NoTerminalExistente(const std::string&);
  bool ExisteCadenaVacia(const std::string&);
  void MostrarGrammarInicial();
  void NewGrammarCNF(std::ofstream&);
  void InsertarNoTerminal(const std::string&);
 private:
  Alfabeto alfabeto_;
  std::multimap<std::string, std::string> grammar_;
  std::vector<std::string> no_terminales_;
  symbol simbolo_arranque_;
};


#endif