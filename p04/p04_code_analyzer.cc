/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Oct 5 2024
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief Main del programa
  * @bug There are no known bugs
  * 
  */

#include <iostream>
#include "check_correct_parameters.h"
#include "comment.h"
#include "block_comment.h"
#include "code_analyzer.h"

int main(int argc, char* argv[]) {
  if (!CheckCorrectParameters(argc, argv, 3)) {
    std::string nombre_archivo_entrada{argv[1]};
    std::ifstream archivo_entrada{argv[1]};
    std::ofstream archivo_salida{argv[2]};
    CodeAnalyzer(archivo_entrada, archivo_salida, nombre_archivo_entrada);
  }
  return 0;
}