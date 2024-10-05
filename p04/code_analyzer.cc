/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Oct 5 2024
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief Función que analiza el código
  * @bug There are no known bugs
  * 
  */

#include "code_analyzer.h"

void BlockComments(int line_counter, int beginning, int end, int& block_comments_counter, bool& in_description, bool& in_block, Block_Comment& description, Block_Comment& block_comments, std::string line, std::regex description_beginning) {
      //si estamos en la primera línea y vemos uel coienzo de un bloque de código leemos y almacenamos la descripcion
      if (line_counter == 1 && std::regex_search(line, description_beginning)) {
        beginning = line_counter;
        //añado la línea y paso un 0 puesto que solo voy a almacenar un bloque porque solo hay una descripción
        description.PushBack(line, 0);
        //estamos dentro del bloque
        in_description = true;
      } else if (in_description) {
        //dentro del bloque sigo añadiendo las lineas
        description.PushBack(line, 0);
        //Cuando encuentre el final guardo la linea, salgo del bloque
        if (std::regex_search(line, std::regex("\\*/"))) {
          end = line_counter;
          in_description = false;
          description.SetLines(beginning, end);
        }
      } 
      
      //encuentro un nuevo bloque y cuento cuántos de ellos hay
      if (line_counter != 1 && std::regex_search(line, std::regex("/\\*\\*"))) {
        block_comments_counter++;
        //hago un resize porque si no me da un segmantation fault
        block_comments.Resize(block_comments_counter);
        beginning = line_counter;
        block_comments.PushBack(line, block_comments_counter - 1);
        //estamos dentro del bloque
        in_block = true;
      } else if (in_block) {
        //dentro añadimos el resto de lineas
        block_comments.PushBack(line, block_comments_counter - 1);
        //cuando llegamos al final salimos del bloque y guardamos las lineas
        if (std::regex_search(line, std::regex("\\*/"))) {
          end = line_counter;
          in_block = false;
          block_comments.SetLines(beginning, end);
        }
      }      
}


void Code_Analyzer(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
  //Compruebo si el archivo se puede abrir
  if (archivo_entrada.is_open()) {
    //variables para los bloques de comentarios
    std::regex description_beginning(("/\\*\\*"));
    Block_Comment description;
    Block_Comment block_comments;
    bool in_description{false};
    bool in_block{false};
    int beginning{0};
    int end{0};
    int block_comments_counter{0};
    //variables para leer las líneas y el contador de la línea
    std::string line;
    int line_counter{0};



    //leo línea por línea para luego ir buscando en ella las cosas
    while (std::getline(archivo_entrada, line)) {
      line_counter++;
      //miro los bloques de comentarios
      BlockComments(line_counter, beginning, end, block_comments_counter, in_description, in_block, description, block_comments, line, description_beginning);

    }
    archivo_salida << description << block_comments;

  } else {
    std::cout << "Problema al abrir el archivo de entrada" << std::endl;
  }
}