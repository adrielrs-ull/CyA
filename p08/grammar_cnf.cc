// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 6
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 20/10/2024
// Declaración de la clase GrammarCNF
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include "grammar_cnf.h"
#include <limits>

typedef char symbol;

GrammarCNF::GrammarCNF(std::ifstream& archivo_entrada) {
  if (!archivo_entrada.is_open()) {
    std::cerr << "Ha habido un problema al abrir el archivo" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  std::string numero_terminales, simbolo;

  archivo_entrada >> numero_terminales;
  int n_terminales = std::stoi(numero_terminales);
  for (int i{0}; i < n_terminales; ++i) {
    archivo_entrada >> simbolo;
    if (static_cast<int>(simbolo.size()) > 1 || static_cast<int>(simbolo.size()) == 0) {
      std::cerr << "Un símbolo no cumple las necesidades" << std::endl;
      std::exit(EXIT_FAILURE);
    }
    alfabeto_.InsertarEnAlfabeto(simbolo[0]);
  }

  std::string numero_no_terminales, no_terminal;
  
  archivo_entrada >> numero_no_terminales;
  int n_no_terminales = std::stoi(numero_no_terminales);
  for (int i{0}; i < n_no_terminales; ++i) {
    archivo_entrada >> no_terminal;
    if (static_cast<int>(simbolo.size()) > 1 || static_cast<int>(simbolo.size()) == 0) {
      std::cerr << "Un No Terminal no cumple las necesidades" << std::endl;
      std::exit(EXIT_FAILURE);
    }
    no_terminales_.emplace_back(no_terminal);
  }

  std::string simbolo_arranque_aux = no_terminales_[0];
  simbolo_arranque_ = simbolo_arranque_aux[0];

  std::string numero_producciones, producciones;
  std::istringstream iss;

  archivo_entrada >> numero_producciones;
  int n_producciones = std::stoi(numero_producciones);
  // Ignorar hasta el final de la línea para el correcto funcionamiento del getline
  archivo_entrada.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  for (int i{0}; i < n_producciones; ++i) {
    std::getline(archivo_entrada, producciones);
    iss.clear();
    iss.str(producciones);
    std::string left, right;
    iss >> left >> right;
    if (static_cast<int>(right.size()) == 1 && NoTerminalExistente(right)) {
      std::cerr << "Se ha encontrado una producción unitaria" << std::endl;
      std::exit(EXIT_FAILURE);
    } else if (ExisteCadenaVacia(right) && left[0] != simbolo_arranque_) {
      std::cerr << "ERROR: Cadena vacía encontrada" << std::endl;
      std::exit(EXIT_FAILURE);
    }
    grammar_.insert({left, right});
  }
  archivo_entrada.close();
}

bool GrammarCNF::NoTerminalExistente(const std::string& no_terminal) {
  for (std::string character : no_terminales_) {
    if (character == no_terminal) {
      return true;
    }
  }
  return false;
}

bool GrammarCNF::ExisteCadenaVacia(const std::string& cadena) {
  for (symbol character : cadena) {
    if (character == '&') {
      return true;
    }
  }
  return false;
}

void GrammarCNF::MostrarGrammarInicial() {
  alfabeto_.MostrarAlfabeto();
  for (auto& prod : grammar_) {
    std::cout << prod.first << " -> " << prod.second << std::endl;
  }
}


void GrammarCNF::NewGrammarCNF(std::ofstream& archivo_salida) {
  //FASE 1
  std::multimap<std::string, std::string> new_grammar;
  for (auto& produccion : grammar_) {
    std::string left = produccion.first;
    std::string right = produccion.second;
    
    if (right.size() >= 2) {
      std::string new_rigth;
      for (symbol Xi : right) {
        if (alfabeto_.ExisteEnAlfabeto(Xi)) {
          std::string new_no_terminal = "C" + std::string(1, Xi);
          if (new_grammar.find(new_no_terminal) == new_grammar.end()) {
            new_grammar.insert({new_no_terminal, std::string(1, Xi)});
            no_terminales_.push_back(new_no_terminal);
          }
          new_rigth += new_no_terminal;
        } else {
          new_rigth += std::string(1, Xi);
        }
      }
      new_grammar.insert({left, new_rigth});
    } else {
      new_grammar.insert({left, right});
    }
  }

  //FASE 2
  int n_new_production{0};
  for (auto produccion : new_grammar) {
    std::string left = produccion.first;
    std::string rigth = produccion.second;
    if (rigth.size() >= 3) {
      std::string new_right;
      int rigth_size = static_cast<int>(rigth.size());
      
      int stop;
      std::string condition1 = std::string(1, rigth[static_cast<int>(rigth.size()) - 3]) + std::string(1, rigth[static_cast<int>(rigth.size()) - 2]);
      std::string condition2 = std::string(1, rigth[static_cast<int>(rigth.size()) - 2]) + std::string(1, rigth[static_cast<int>(rigth.size()) - 1]);
      std::string condition3 = std::string(1, rigth[static_cast<int>(rigth.size()) - 4]) + std::string(1, rigth[static_cast<int>(rigth.size()) - 3]);

      if (NoTerminalExistente(condition2) && NoTerminalExistente(condition3)) {
        stop = 4;
        std::cout << "stop 4" << std::endl;
      } else if (NoTerminalExistente(condition1) || NoTerminalExistente(condition2)) {
        stop = 3;
        std::cout << "stop 3" << std::endl;
      } else {
        stop = 2;
        std::cout << "stop 2" << std::endl;
      }

      for (int i{0}; i < rigth_size - stop; ++i) {
        std::string D = "D" + std::to_string(n_new_production);
        n_new_production++;
        if (alfabeto_.ExisteEnAlfabeto(rigth[i + 1])) {
          new_right = std::string(1, rigth[i]) + std::string(1, rigth[i + 1]) + D;
          ++i;
        } else {
          new_right = std::string(1, rigth[i]) + D;
        }
        grammar_cnf_.insert({left, new_right});
        left = D; 
      }
      if (stop == 4) {
        new_right = std::string(1, rigth[rigth_size - 4]) + std::string(1, rigth[rigth_size - 3]) + std::string(1, rigth[rigth_size - 2]) + std::string(1, rigth[rigth_size - 1]);
      } else if (stop == 3) {
        new_right = std::string(1, rigth[rigth_size - 3]) + std::string(1, rigth[rigth_size - 2]) + std::string(1, rigth[rigth_size - 1]);
      } else {
        new_right = std::string(1, rigth[rigth_size - 2]) + std::string(1, rigth[rigth_size - 1]);
      }
      grammar_cnf_.insert({left, new_right});
    } else {
      grammar_cnf_.insert({left, rigth});
    }
  }

  for (auto& prod : new_grammar) {
    archivo_salida << prod.first << " -> " << prod.second << std::endl;
  }
  archivo_salida << std::endl;
  archivo_salida << std::endl;
  for (auto& prod : grammar_cnf_) {
    archivo_salida << prod.first << " -> " << prod.second << std::endl;
  }
}

void GrammarCNF::InsertarNoTerminal(const std::string& no_terminal) {
  no_terminales_.push_back(no_terminal);
}