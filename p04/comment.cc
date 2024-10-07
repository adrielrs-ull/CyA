/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Oct 5 2024
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief Definición de la clase Comment
  * @bug There are no known bugs
  * 
  */

 #include "comment.h"

//getters
std::vector<std::string> Comment::GetComment() const {
  return comments_;
}

std::vector<int> Comment::GetLines() const {
  return lines_;
}

//setters
void Comment::AddComment(const std::string& comment, int line) {
  comments_.push_back(comment);
  lines_.push_back(line);
}

//la función me ayuda a hacer un resize a los atributos
void Comment::Resize(int n) {
  comments_.resize(n);
  lines_.resize(n);
}
//sobrecarga del operador para imprimir
std::ostream& operator<<(std::ostream& os, Comment& comment) {
  for (int i{0}; i < static_cast<int>(comment.GetComment().size()); i++) {
    os << "[Linea " << comment.GetLines()[i] << "] " << comment.GetComment()[i] << std::endl;
  }
  return os;
}

//devuelve si el vector de los comentarios está vacío
bool Comment::Empty() {
  return comments_.empty();
}