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

/**
 * @brief Construct a new Grammar C N F:: Grammar C N F object
 * 
 * @param archivo_entrada 
 */
GrammarCNF::GrammarCNF(std::ifstream& archivo_entrada) {
  // Compruebo si el archivo está abierto
  if (!archivo_entrada.is_open()) {
    std::cerr << "Ha habido un problema al abrir el archivo" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  std::string numero_terminales, simbolo;
  // Leo el número de terminales
  archivo_entrada >> numero_terminales;
  int n_terminales = std::stoi(numero_terminales);
  // Almaceno los terminales en el alfabeto
  for (int i{0}; i < n_terminales; ++i) {
    archivo_entrada >> simbolo;
    // Si hay más de un símbolo o no hay nada se genera un error
    if (static_cast<int>(simbolo.size()) > 1 || static_cast<int>(simbolo.size()) == 0) {
      std::cerr << "Un símbolo no cumple las necesidades" << std::endl;
      std::exit(EXIT_FAILURE);
    }
    alfabeto_.InsertarEnAlfabeto(simbolo[0]);
  }

  std::string numero_no_terminales, no_terminal;
  // Leo el número de no termianales
  archivo_entrada >> numero_no_terminales;
  int n_no_terminales = std::stoi(numero_no_terminales);
  // Almaceno los no terminales
  for (int i{0}; i < n_no_terminales; ++i) {
    archivo_entrada >> no_terminal;
    // Si hay más de un no terminal o no hay nada se genera un error
    if (static_cast<int>(simbolo.size()) == 0) {
      std::cerr << "Un No Terminal no cumple las necesidades" << std::endl;
      std::exit(EXIT_FAILURE);
    }
    no_terminales_.emplace_back(no_terminal);
  }

  // Defino el simbolo de arranque
  std::string simbolo_arranque_aux = no_terminales_[0];
  simbolo_arranque_ = simbolo_arranque_aux[0];
  std::string numero_producciones, producciones;
  std::istringstream iss;
  // Leo el número de producciones
  archivo_entrada >> numero_producciones;
  int n_producciones = std::stoi(numero_producciones);
  // Ignorar hasta el final de la línea para el correcto funcionamiento del getline
  archivo_entrada.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  // Almaceno las producciones
  for (int i{0}; i < n_producciones; ++i) {
    std::getline(archivo_entrada, producciones);
    // Limpio el iss
    iss.clear();
    // Le asigno la nueva cadena de la produccion
    iss.str(producciones);
    std::string left, right;
    // Asigno el simobolo que produce y la producción
    iss >> left >> right;
    // Comprobamos si hay alguna producción inútil en el lado izquierdo o derecho de la producción
    if (!NoTerminalExistente(left)) {
      std::cerr << "Se ha encontrado una producción inútil" << std::endl;
      std::exit(EXIT_FAILURE);
    }
    int stop{0};
    // Comprobamos si el último simbolo de la produccion es un no terminal que está formado su nombre por dos caracteres
    // Así en el bucle logramos parar en el último simbolo no terminal o terminal
    if (NoTerminalExistente(std::string(1, right[static_cast<int>(right.size() - 2)]) + std::string(1, right[static_cast<int>(right.size() - 1)]))) {
      stop = 1;
    }
    for (int i{0}; i < static_cast<int>(right.size()) - stop; ++i) {
      // Esta variable son para los casos en los que tengamos una gramatica en CNF y halla simbolos como Ca donde a es un simbolo del alfabeto
      std::string simbolo_compuesto = std::string(1, right[i]) + std::string(1, right[i+1]);
      if (!alfabeto_.ExisteEnAlfabeto(right[i]) && !NoTerminalExistente(std::string(1, right[i])) && !NoTerminalExistente(simbolo_compuesto)) {
        std::cerr << "Se ha encontrado una producción inútil" << std::endl;
        std::exit(EXIT_FAILURE);
      } 
    }
    // Si en la produccion solo hay una produccion y no es un termianl salta el error de produccion unitaria
    if (static_cast<int>(right.size()) == 1 && NoTerminalExistente(right)) {
      std::cerr << "Se ha encontrado una producción unitaria" << std::endl;
      std::exit(EXIT_FAILURE);
      // Si en el lado derecho existe la cadena vacia y el simbolo que produce es distinto al de arranque se produce el error de cadena vacia
    } else if (ExisteCadenaVacia(right) && left[0] != simbolo_arranque_) {
      std::cerr << "ERROR: Cadena vacía encontrada" << std::endl;
      std::exit(EXIT_FAILURE);
    }
    // Inserto en la gramática
    grammar_.insert({left, right});
  }
  archivo_entrada.close();
}


/**
 * @brief Comprobar si un terminal existe o no
 * 
 * @param no_terminal 
 * @return true 
 * @return false 
 */
bool GrammarCNF::NoTerminalExistente(const std::string& no_terminal) {
  for (std::string character : no_terminales_) {
    if (character == no_terminal) {
      return true;
    }
  }
  return false;
}


/**
 * @brief Función para comprobar la existencia de la cadena vacía en una producción
 * 
 * @param cadena 
 * @return true 
 * @return false 
 */
bool GrammarCNF::ExisteCadenaVacia(const std::string& cadena) {
  for (symbol character : cadena) {
    if (character == '&') {
      return true;
    }
  }
  return false;
}


/**
 * @brief Función para mostrar por terminal la gramática almacenada
 * 
 */
void GrammarCNF::MostrarGrammarInicial() {
  alfabeto_.MostrarAlfabeto();
  for (auto& prod : grammar_) {
    std::cout << prod.first << " -> " << prod.second << std::endl;
  }
}


/**
 * @brief Crear la nueva gramática en CNF
 * 
 * @param archivo_salida 
 */
void GrammarCNF::NewGrammarCNF(std::ofstream& archivo_salida) {
  bool non_phase1{true};
  bool non_phase2{true};
  // FASE 1
  // Creo una gramática auxiliar
  std::multimap<std::string, std::string> new_grammar;
  // Leo la gramática y asigno el símbolo qyue produce y la producción
  for (auto& produccion : grammar_) {
    std::string left = produccion.first;
    std::string right = produccion.second;
    bool simbolo_alfabeto{false};
    // Debido a los simbolos compuestos en CNF busco coincidecias Ca donde a es un simbolo del alfabeto y le resto 1 al size para que cuente como un único no terminal
    int rigth_size{static_cast<int>(right.size())};
    for (int i{0}; i < rigth_size; ++i) {
      // Si encontramos Ca donde a es un simbolo del alfabeto y desplazamos uno para recorrer bien el bucle
      if (NoTerminalExistente(std::string(1, right[i]) + std::string(1, right[i + 1]))) {
        ++i;
      } else if (alfabeto_.ExisteEnAlfabeto(right[i])) {
        // Si hay un simbolo del alfabeto lo marcamos
        simbolo_alfabeto = true;
      }

    }
    
    // Si la producción no produce solo un terminal y además se encuentra un simbolo del alfabeto en la producción
    if (right.size() >= 2 && simbolo_alfabeto) {
      // Marcamos que se ha entrado a la fase 1
      non_phase1 = false;
      // Creo una variable auxiliar
      std::string new_rigth;
      // Recorro la producción
      for (symbol Xi : right) {
        // Si el símbolo existe en el alfabeto, es decir, si es un terminal
        if (alfabeto_.ExisteEnAlfabeto(Xi)) {
          // Genero un nuevo no termianl que producirá este terminal
          std::string new_no_terminal = "C" + std::string(1, Xi);
          // Si no se encuentra en el conjunto de los no terminales lo añado y lo inserto en la gramática
          if (new_grammar.find(new_no_terminal) == new_grammar.end()) {
            new_grammar.insert({new_no_terminal, std::string(1, Xi)});
            no_terminales_.push_back(new_no_terminal);
          }
          // Añado a la nueva producción este no terminal
          new_rigth += new_no_terminal;
        } else {
          // Si estamos ante uno de los no terminales simplemente lo añadimos a la nueva producción
          new_rigth += std::string(1, Xi);
        }
      }
      // Insertamos en la gramática la producción
      new_grammar.insert({left, new_rigth});
    } else {
      // Si la producción solo tiene un terminal la añadimos a la gramática
      new_grammar.insert({left, right});
    }
  }

  //FASE 2
  // Creamos una variable que nos ayudará para enumerar los no terminales auxiliares que añadiremos a la gramática
  int n_new_production{0};
  // Creamos la gramática resultante en Forma Normal de Chomsky
  std::multimap<std::string, std::string> grammar_cnf;
  // Recorro la gramática generada por la primera fase
  for (auto produccion : new_grammar) {
    // Establezo la producción y quién la produce
    std::string left = produccion.first;
    std::string rigth = produccion.second;
    // Debido a los simbolos compuestos en CNF busco coincidecias Ca donde a es un simbolo del alfabeto y le resto 1 al size para que cuente como un único no terminal
    int rigth_size{static_cast<int>(rigth.size())};
    for (int i{0}; i < rigth_size; ++i) {
      if (NoTerminalExistente(std::string(1, rigth[i]) + std::string(1, rigth[i + 1]))) {
        --rigth_size;
      }
    }    
    // Si la producción tiene más de dos no terminales
    if (rigth_size >= 3) {
      // Marcamos que se ha entrado a la fase 2
      non_phase2 = false;
      // Creo una nueva producción auxiliar
      std::string new_right;
      int rigth_size = static_cast<int>(rigth.size());
      
      // Debido a los nombres de las producciones que generan los terminales ej: Ca
      // tengo que calcular condiciones por si al final de la producción se encuentra
      // una, dos o ninguna de estas producciones para varias el punto de parada
      // porque será distinto para cada caso
      int stop;
      std::string condition1 = std::string(1, rigth[static_cast<int>(rigth.size()) - 3]) + std::string(1, rigth[static_cast<int>(rigth.size()) - 2]);
      std::string condition2 = std::string(1, rigth[static_cast<int>(rigth.size()) - 2]) + std::string(1, rigth[static_cast<int>(rigth.size()) - 1]);
      std::string condition3 = std::string(1, rigth[static_cast<int>(rigth.size()) - 4]) + std::string(1, rigth[static_cast<int>(rigth.size()) - 3]);
      if (NoTerminalExistente(condition2) && NoTerminalExistente(condition3)) {
        stop = 4;
      } else if (NoTerminalExistente(condition1) || NoTerminalExistente(condition2)) {
        stop = 3;
      } else {
        stop = 2;
      }

      // Recorro las producciones hasta este punto variable de parada
      for (int i{0}; i < rigth_size - stop; ++i) {
        // Creo las producciones 'D' auxiliares
        std::string D = "D" + std::to_string(n_new_production);
        no_terminales_.emplace_back(D);
        // Incremento el contador para aumentar el número del nombre de estas producciones
        n_new_production++;
        // Aquí compruebo si estoy ante algún no terminal del tipo 'C', puesto que si es así
        // no solo tendré que coger el caracter que lo representa sino también el siguiente
        // y avanzar uno más en la iteración
        // Para ello simplemente compruebo si el simbolo siguiente es un terminal puesto 
        // que todos están ya eliminados y los únicos que quedan son las de estas producciones
        if (alfabeto_.ExisteEnAlfabeto(rigth[i + 1])) {
          new_right = std::string(1, rigth[i]) + std::string(1, rigth[i + 1]) + D;
          ++i;
        } else {
          new_right = std::string(1, rigth[i]) + D;
        }
        // inserto en la gramática la producción
        grammar_cnf.insert({left, new_right});
        // Actualizo el 'D' para mantener esta estructura "recursiva"
        left = D; 
      }
      // Dependiendo de la posición de parada añadiré el resto de la producción
      new_right = rigth.substr((static_cast<int>(rigth.size()) - stop));
      grammar_cnf.insert({left, new_right});
    } else {
      grammar_cnf.insert({left, rigth});
    }
  }

  if(!archivo_salida.is_open()) {
    std::cerr << "Ha habido un problema al abrir el archivo" << std::endl;
    std::exit(EXIT_FAILURE); 
  }
  // Si no ha entrado en ninguna de las dos fases es porque ya estaba en CNF
  if (non_phase1 && non_phase2) {
    archivo_salida << "La gramática introducida ya se encontraba en Forma Normal de Chomsky" << std::endl;
  } else {
    // Imprimimos el resultado en el archivo de salida
    archivo_salida << alfabeto_.GetSizeAlfabeto() << std::endl;
    archivo_salida << alfabeto_;
    archivo_salida << no_terminales_.size() << std::endl;
    for (int i{0}; i < static_cast<int>(no_terminales_.size()); ++i) {
      archivo_salida << no_terminales_[i] << std::endl;
    }
    archivo_salida << grammar_cnf.size() << std::endl;
    for (auto& prod : grammar_cnf) {
      archivo_salida << prod.first << " " << prod.second << std::endl;
    }
  }
  
  archivo_salida.close();
}


/**
 * @brief Insertar un no terminal en el conjunto de los no terminales
 * 
 * @param no_terminal 
 */
void GrammarCNF::InsertarNoTerminal(const std::string& no_terminal) {
  no_terminales_.push_back(no_terminal);
}

