/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Oct 5 2024
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief Definición de la clase Block_Comment
  * @bug There are no known bugs
  * 
  */

#include "block_comment.h"

Block_Comment::Block_Comment() {
  block_comment_.resize(1);
}



//recorremos el vector que almacena los bloques de cadenas (cada bloque es un vector de string) --> por eso tiene estructura matricial
std::ostream& operator<<(std::ostream& os, Block_Comment& block_comment) {
  for(int i{0}; i < static_cast<int>(block_comment.GetBlock_Comment().size()); i++) {
    os << "Line [" << block_comment.GetBeginning(i) << "-" << block_comment.GetEnd(i) << "]: " << std::endl;
    for (int j{0}; j < static_cast<int>(block_comment.GetBlock_Comment()[i].size()); j++) {
      os << block_comment.GetBlock_Comment()[i][j] << std::endl;
    }
  }
  return os;
}
//getters
std::vector<block_comment> Block_Comment::GetBlock_Comment() const {
  return block_comment_;
}
std::vector<std::pair<int, int>> Block_Comment::GetLines() const {
  return lines_;
}

int Block_Comment::GetBeginning(int n) const {
  return lines_[n].first;
}

int Block_Comment::GetEnd(int n) const {
  return lines_[n].second;
}

//setter
void Block_Comment::SetLines(int line_number1, int line_number2) {
  lines_.push_back(std::make_pair(line_number1, line_number2));
}

//función push back para añadir la línea al bloque adecuado
void Block_Comment::PushBack(std::string& line, int n) {
  block_comment_[n].push_back(line);
}

//función para mostrar las lineas de todos los bloques de comentarios
void Block_Comment::MostrarLineas() {
  for (int i{0}; i < static_cast<int>(lines_.size()); i++) {
    std::cout << lines_[i].first << " " << lines_[i].second << std::endl;
  }
}

//función para porder hacer el resize del vector
void Block_Comment::Resize(int n) {
  block_comment_.resize(n);
}