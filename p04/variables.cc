/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Oct 5 2024
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief Definición de la clase Variables
  * @bug There are no known bugs
  * 
  */

#include "variables.h"
//getters
std::vector<std::pair<std::string, std::string>> Variables::GetVariables() const {
  return variables_;
}

int Variables::GetIntCounter() const {
  return int_counter_;
}

int Variables::GetDoubleCounter() const {
  return double_counter_;
}

std::vector<int> Variables::GetLines() const {
  return lines_;
}
//me permite añadir la línea, el tipo de variable y la inicialización de esta
void Variables::AddLine(const std::string& type, const std::string& variable, int line) {
  variables_.push_back(std::make_pair(type, variable));
  lines_.push_back(line);
}

//contadores
void Variables::AddInt() {
  int_counter_++;
}

void Variables::AddDouble() {
  double_counter_++;
}

//comprobar si el vector está vacío
bool Variables::Empty() {
  return variables_.empty();
}
//sobrecarga del operador extracción
std::ostream& operator<<(std::ostream& os, Variables& variable) {
  for (int i{0}; i < static_cast<int>(variable.GetVariables().size()); i++) {
    os << "[Line " << variable.GetLines()[i] << "] ";
    if (variable.GetVariables()[i].first == "int") {
      os << "INT: ";
    } else if (variable.GetVariables()[i].first == "double") {
      os << "DOUBLE: ";
    }
    os << variable.GetVariables()[i].second << std::endl;
  }
  return os;
}