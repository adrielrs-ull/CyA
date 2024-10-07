/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Oct 5 2024
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief Definición de la clase Loops
  * @bug There are no known bugs
  * 
  */

#include "loops.h"

void Loops::AddLoop(const std::string& loop, int lines) {
  loops_.push_back(loop);
  lines_.push_back(lines);
}

//getters
std::vector<std::string> Loops::GetLoop() const {
  return loops_;
}

std::vector<int> Loops::GetLines() const {
  return lines_;
}

int Loops::GetCounterFor() {
  return counter_for_;
}

int Loops::GetCounterWhile() {
  return counter_while_;
}

std::ostream& operator<<(std::ostream& os, Loops& loop) {
  for (int i{0}; i < static_cast<int>(loop.GetLoop().size()); i++) {
    os << "[Line " << loop.GetLines()[i] << "] LOOP: " << loop.GetLoop()[i] << std::endl;
  }
  return os;
}

//devuelve si el vector de los loops está vacío
bool Loops::Empty() {
  return loops_.empty();
}

//suma al contador de los bucles
void Loops::AddCounterFor() {
  counter_for_++;
}

void Loops::AddCounterWhile() {
  counter_while_++;
}

