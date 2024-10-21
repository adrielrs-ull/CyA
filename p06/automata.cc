// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 6
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 20/10/2024
// Definición clase Autómata
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include "automata.h"
#include <stack>

/**
 * @brief Constructor del programa leyendo un archivo
 * 
 * @param archivo_entrada 
 */
Automata::Automata(std::ifstream& archivo_entrada) {
  std::string line;
  //establezco un contador para ir aumentando las lineas
  int linea{0};
  //Creo este vector para posteriormente comparar si todos los destinos existen
  std::vector<int> transiciones;
  //leo el archivo linea a linea
  while (std::getline(archivo_entrada, line)) {
    //si la linea está vacía me la salto
    if (line.empty()) {
      continue;
    }

    switch (linea) {
      //si estoy en la primera linea construyo el alfabeto
      case 0:
        for (int i{0}; i < static_cast<int>(line.size()); i++) {
          if (line[i] == '&') {
            std::cerr << "ERROR: '&' no puede pertenecer al alfabeto -caracter reservado-" << std::endl;
            std::exit(EXIT_FAILURE);
          }
          if (line[i] != ' ') {
            alfabeto_.InsertarEnAlfabeto(line[i]);
          }
        }
        break;
      //si es la linea dos guardo el numero de estados totales
      case 1:
        numero_estados_ = std::stoi(line);
        break;
      //si estoy en el estado 3, guardo el estado de arranque
      case 2:
        if (static_cast<int>(line.size()) > 1) {
          std::cerr << "ERROR: hay más de un estado de aceptación o algún espacio en blanco" << std::endl;
          std::exit(EXIT_FAILURE);
        }
        estado_arranque_.insert(std::stoi(line));
        break;
      //para el resto de lineas hago lo siguiente
      default:
        //selecciono el estado del que estamos hablando
        int estado = line[0] - '0';
        estados_automata_.insert(estado);
        //compruebo si es estado final o no
        if (line[2] == '1') {
          estados_aceptacion_.insert(estado);
        }
        //si la cadena es mayor que 5, es decir, tiene al menos una transición
        if (line.size() > 5) {
          //creo una cadena con las secuencias del simbolo y a donde transita, elimino el estado, el numero de transiciones y si es de aceptacion o no
          std::string simbolo_transicion = line.substr(5);
          std::istringstream secuencia(simbolo_transicion);
          //recorro la secuencia estableciendo los estados a los que se transita
          std::string simbolo, destino;
          while (secuencia >> simbolo >> destino) {
            if (!alfabeto_.ExisteEnAlfabeto(simbolo[0])) {
              std::cerr << "ERROR: el simbolo " << simbolo << " no existe en el alfabeto " << alfabeto_;
              std::exit(EXIT_FAILURE);
            }
            transiciones.emplace_back(std::stoi(destino));
            //creo un paor con el estado y el simbolo correspondiente
            std::pair<int, symbol> par = std::make_pair(estado, simbolo[0]);
            //inserto en el mapa si no existen el estado y el simbolo para la transicion, si ya lo hacen, inserto el destino de esta transición
            transiciones_[par].insert(std::stoi(destino));
          }
        } else {
          // en caso de que la cadena se < 5, no dispondrá de trancisiones a otros estados por lo cual solo añado la transicion & a si mismo
          std::pair <int, symbol> par = std::make_pair(estado, '&');
          transiciones_[par].insert(par.first);
        }
        //Inserto el número de transiciones que tiene cada estado
        transiciones_estados_.emplace_back(line[4] - '0');
        break;
    }
    //aumento la linea para el uso del switch
    linea++;
  }
  if (linea - 3 != numero_estados_) {
    std::cerr << "ERROR: alguno de los estados falta por definir" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  for (int elemento : transiciones) {
    if (!EstadoExistente(elemento)) {
      std::cerr << "ERROR: el estado " << elemento << " no existe en el autómata" << std::endl;
      std::exit(EXIT_FAILURE); 
    }
  }
}

bool Automata::EstadoExistente(int estado) {
  return estados_automata_.find(estado) != estados_automata_.end();
}


/**
 * @brief Retorna el alfabeto
 * 
 * @return Alfabeto 
 */
Alfabeto Automata::GetAlfabeto() const {
  return alfabeto_;
}

/**
 * @brief Retorna el número de estados del autómata
 * 
 * @return int 
 */
int Automata::GetNumeroEstados() const {
  return numero_estados_;
}

/**
 * @brief retorna el estado de arranque del programa
 * 
 * @return std::set<int> 
 */
std::set<int> Automata::GetEstadoArranque() const {
  return estado_arranque_;
}

/**
 * @brief Devuelve los estados a los que transita un estado con un símbolo
 * 
 * @param estado 
 * @param simbolo 
 * @return std::set<int> 
 */
std::map<std::pair<int, symbol>, std::set<int>> Automata::GetTransiciones() const {
  return transiciones_;
}

/**
 * @brief Retorna el set con los estado sde aceptación
 * 
 * @return std::set<int> 
 */
std::set<int> Automata::GetEstadosAceptacion() const {
  return estados_aceptacion_;
}

/**
 * @brief Getter de el número de transiciones de cada estado
 * 
 * @return std::vector<int> 
 */
std::vector<int> Automata::GetTransicionesEstados() const {
  return transiciones_estados_;
}

/**
 * @brief Sobrecarga del operador para la extracción del automata
 * 
 * @param os 
 * @param automata 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, Automata& automata) {
  Alfabeto alfabeto_automata = automata.GetAlfabeto();
    os << "Alfabeto del lenguaje: " << alfabeto_automata;
    os << "El Autómata Finito tiene " << automata.GetNumeroEstados() << " estados en total" << std::endl;
    os << "Estado de arranque: ";
    for (int elemento : automata.GetEstadoArranque()) {
      os << elemento << std::endl;
    }
    
    const auto& transiciones = automata.GetTransiciones();
    for (auto& estado : transiciones) {
      const std::pair<int, symbol> pair = estado.first;
      const std::set<int>& destinos = estado.second;
      if (automata.GetTransiciones().find(pair) != automata.GetTransiciones().end()) {
        for (int elemento : destinos) {
          os << "Estado: " << pair.first << " Simbolo: " << pair.second << " --> " << elemento << std::endl;
        }
      }
    }
    os << "Estados de aceptación:";
    for (int estado : automata.GetEstadosAceptacion()) {
      os << " " << estado << std::endl;
    }
    for (int i{0}; i < static_cast<int>(automata.GetTransicionesEstados().size()); i++) {
      os << "El estado " << i << " tiene " << automata.GetTransicionesEstados()[i] << " estados" << std::endl;
    }
    return os;
}

/**
 * @brief comprueba si un estado es de acpetación o no
 * 
 * @param estado 
 * @return true 
 * @return false 
 */
bool Automata::EsDeAceptacion(int estado) {
  if (estados_aceptacion_.find(estado) != estados_aceptacion_.end()) {
    return true;
  }
  return false;
}


/**
 * @brief La función me ayuda a realizar la epsilon clausara de conjuntos de estados pasados
 * 
 * @param conjunto_estados 
 * @return std::set<int> 
 */
std::set<int> Automata::EpsilonTransicion(std::set<int>& conjunto_estados) {
  // Conjunto resultante que contendrá todos los estados alcanzados por epsilon transiciones
  std::set<int> epsilon_transicion_conjunto = conjunto_estados;
  
  // Pila para realizar la búsqueda iterativa 
  std::stack<int> pila_estados;

  // Inicializamos la pila con los estados del conjunto original
  for (int estado : conjunto_estados) {
    pila_estados.push(estado);
  }

  // Procesamos la pila mientras haya estados que revisar
  while (!pila_estados.empty()) {
    int estado_actual = pila_estados.top();
    pila_estados.pop();

    // Recorrer todas las transiciones de ese estado
    for (auto& transicion : transiciones_) {
      auto clave = transicion.first;
      auto destino = transicion.second;

      // Si la transición es una epsilon ('&') desde el estado actual
      if (clave.first == estado_actual && clave.second == '&') {
        // Añadir los estados de destino si no han sido visitados
        for (int estado_destino : destino) {
          if (epsilon_transicion_conjunto.find(estado_destino) == epsilon_transicion_conjunto.end()) {
            epsilon_transicion_conjunto.insert(estado_destino);
            pila_estados.push(estado_destino); // Agregar el nuevo estado a la pila para procesar sus transiciones
          }
        }
      }
    }
  }

  return epsilon_transicion_conjunto;
}


/**
 * @brief Función que reconoce si una cadena es aceptada o no
 * 
 * @param cadena 
 * @param estados_actuales 
 * @param posicion 
 * @return true 
 * @return false 
 */
bool Automata::CadenaReconocida(const std::string& cadena, std::set<int>& estados_actuales, int posicion) {
  
  if (posicion == static_cast<int>(cadena.size())) {
    for (auto& estado : estados_actuales) {
      if (estados_aceptacion_.find(estado) != estados_aceptacion_.end()) {
        return true;
      }
    }
    return false;
  }

  //creo la clausura del estado actual
  std::set<int> clausura = EpsilonTransicion(estados_actuales);
  //creo el conjunto de los estados siguientes
  std::set<int> estados_siguientes;
  //selecciono el simbolo
  symbol simbolo = cadena[posicion];
  //recorro las transiciones buscando mi estado actual y la transicion con el simbolo
  for (int estado : clausura) {
    //recorro las transiciones
    for (auto& transicion : transiciones_) {
      auto clave = transicion.first;
      auto destino = transicion.second;
      if (clave.first == estado && clave.second == simbolo) {
        for (auto& elemento : destino) {
          //compruebo si el elemento ya se encuentra en el conjunto
          if (estados_siguientes.find(elemento) == estados_siguientes.end()) {
            estados_siguientes.insert(elemento);
          }
        }
      }
    }
  }

  std::set<int> clausura_siguiente = EpsilonTransicion(estados_siguientes);

  return Automata::CadenaReconocida(cadena, clausura_siguiente, posicion + 1);
}

/**
 * @brief Esta función lee las cadenas e imprime por pantalla si es aceptada por el lenguaje o no
 * 
 * @param archivo_entrada 
 */
void Automata::LeerCadenas(std::ifstream& archivo_entrada) {
  const std::string aceptada = " --- Accepted";
  const std::string rechazada = " --- Rejected";
  std::string cadena;
  while(std::getline(archivo_entrada, cadena)) {
    std::cout << cadena << (CadenaReconocida(cadena, estado_arranque_, 0) ? aceptada : rechazada) << std::endl;
  }
}