/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Oct 5 2024
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief Definición de la clase Case
  * @bug There are no known bugs
  * 
  */

#include "case.h"
//getters
std::vector<std::string> Case::GetCase() const {
  return case_;
}

std::vector<int> Case::GetLines() const {
  return lines_;
}
//me permite añadir la línea, el tipo de variable y la inicialización de esta
void Case::AddLine(const std::string& switch_case, int line) {
  case_.push_back(switch_case);
  lines_.push_back(line);
}

//comprobar si el vector está vacío
bool Case::Empty() {
  return case_.empty();
}
//sobrecarga del operador extracción
std::ostream& operator<<(std::ostream& os, Case& switch_case) {
  for (int i{0}; i < static_cast<int>(switch_case.GetCase().size()); i++) {
    os << "[Line " << switch_case.GetLines()[i] << "] CASE: " << switch_case.GetCase()[i] << std::endl; 
  }
  return os;
}