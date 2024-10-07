/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Oct 5 2024
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief Definición de la clase BlockComment
  * @bug There are no known bugs
  * 
  */

#include "block_comment.h"

BlockComment::BlockComment() {
  block_comment_.resize(1);
}


bool BlockComment::Empty() {
  return block_comment_.empty();
}
//recorremos el vector que almacena los bloques de cadenas (cada bloque es un vector de string) --> por eso tiene estructura matricial
std::ostream& operator<<(std::ostream& os, BlockComment& block_comment) {
  for(int i{0}; i < static_cast<int>(block_comment.GetBlockComment().size()); i++) {
    os << "[Line " << block_comment.GetBeginning(i) << "-" << block_comment.GetEnd(i) << "] " << std::endl;
    for (int j{0}; j < static_cast<int>(block_comment.GetBlockComment()[i].size()); j++) {
      os << block_comment.GetBlockComment()[i][j] << std::endl;
    }
  }
  return os;
}
//getters
std::vector<block_comment> BlockComment::GetBlockComment() const {
  return block_comment_;
}
std::vector<std::pair<int, int>> BlockComment::GetLines() const {
  return lines_;
}

int BlockComment::GetBeginning(int n) const {
  return lines_[n].first;
}

int BlockComment::GetEnd(int n) const {
  return lines_[n].second;
}

//setter
void BlockComment::SetLines(int line_number1, int line_number2) {
  lines_.push_back(std::make_pair(line_number1, line_number2));
}

//función push back para añadir la línea al bloque adecuado
void BlockComment::PushBack(std::string& line, int n) {
  block_comment_[n].push_back(line);
}

//función para mostrar las lineas de todos los bloques de comentarios
void BlockComment::MostrarLineas() {
  for (int i{0}; i < static_cast<int>(lines_.size()); i++) {
    std::cout << lines_[i].first << " " << lines_[i].second << std::endl;
  }
}

//función para porder hacer el resize del vector
void BlockComment::Resize(int n) {
  block_comment_.resize(n);
}