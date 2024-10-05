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

 Comment::Comment() {
  comments_ = comments_;
 }

void Comment::AddComment(std::string& comment) {
  comments_.push_back(comment);
}