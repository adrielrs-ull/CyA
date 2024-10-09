/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Oct 5 2024
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief Función que analiza el código desglosada en varias funciones para una mejor presentación
  * @bug There are no known bugs
  * 
  */

#include "code_analyzer.h"

//función que busca los bloques de comentarios
void BlockComments(int& line_counter, int& beginning, int end, int& block_comments_counter, bool& in_description, bool& in_block, BlockComment& description, BlockComment& block_comments, std::string line, std::regex description_beginning) {
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

//función que bisca los comentarios en linea
void LineComments(const std::string& line, std::smatch& line_comments_found, int line_counter, Comment& line_comments) {
  //busco en la linea leida si se encuentra el patrón y el vector smatch guarda la coincidencia
  if (std::regex_search(line, line_comments_found, std::regex("^\\s*//.*"))) {
    std::string line_aux = line_comments_found.str();
    //como pueden haber comentarios precedidos por x cantidad de espacios los quito
    if (std::regex_search(line_aux, std::regex("^\\s*"))) {
      line_aux = std::regex_replace(line_aux, std::regex("^\\s*"), "");
    }
    //finalmente guardo la coincidencia y el número de la linea de esta
    line_comments.AddComment(line_aux, line_counter);
  }
}

//función que busca los bucles
void LoopsFinder(std::string& line, std::smatch& loop_found, Loops& loops, int& line_counter) {
  if (std::regex_search(line, std::regex("\\s*while\\s*\\([^\\)]*\\)"))) {
    std::regex_search(line, loop_found, std::regex("while"));
    std::string loop_aux = loop_found.str();
    loops.AddLoop(loop_aux, line_counter);
    loops.AddCounterWhile();
  } else if (std::regex_search(line, std::regex("\\s*for\\s*\\([^\\)]*\\)"))) {
    std::regex_search(line, loop_found, std::regex("for"));
    std::string loop_aux = loop_found.str();
    loops.AddLoop(loop_aux, line_counter);
    loops.AddCounterFor();
  }
}

//función que busca si hay main
void IsThereMain(const std::string& line, bool& is_there_main) {
  if (std::regex_search(line, std::regex("int main()"))) {
    is_there_main = true;
  }
}

//función que busca las variables
void VariablesFinder(std::string& line, int line_counter, Variables& variables) {
  //el primer if es para si es un int o un double
  if (std::regex_search(line, std::regex("^\\s*int (?!main).*;$"))) {
    //creo el tipo
    std::string int_type{"int"};
    //ahora creo la cadena sin el tipo
    std::string variable_without_type = std::regex_replace(line, std::regex("^\\s*int\\s*"), "");
    //le quito el ';' para una mejor presentación
    variable_without_type = std::regex_replace(variable_without_type, std::regex(";"), "");
    //añado la linea e incremento el contador de los int
    variables.AddLine(int_type, variable_without_type, line_counter);
    variables.AddInt();
  } else if (std::regex_search(line, std::regex("\\s*double .*;$"))) {
    //creo el tipo
    std::string double_type{"double"};
    //creo la cadena sin el tipo y el punto y coma
    std::string variable_without_type = std::regex_replace(line, std::regex("^\\s*double\\s*"), "");
    variable_without_type = std::regex_replace(variable_without_type, std::regex(";"), "");
    //añado la cadena y aumento el contador de double
    variables.AddLine(double_type, variable_without_type, line_counter);
    variables.AddDouble();
  }
}

//función para escribir en el archivo de salida el resultado
void WriteResult(std::ofstream& archivo_salida, std::string& nombre_archivo_entrada,  BlockComment& description, BlockComment& block_comments, Comment& comments, Loops& loops, bool is_there_main, Variables& variables, Case& switch_cases) {
  archivo_salida << "PROGRAM: " << nombre_archivo_entrada << std::endl;
  if (!description.Empty()) {
    archivo_salida << "DESCRIPTION:" << std::endl;
    for(int i{0}; i < static_cast<int>(description.GetBlockComment().size()); i++) {
    for (int j{0}; j < static_cast<int>(description.GetBlockComment()[i].size()); j++) {
      archivo_salida << description.GetBlockComment()[i][j] << std::endl;
    }
  }
  }
  if (!variables.Empty()) {
    archivo_salida << std::endl;
    archivo_salida << "VARIABLES:" << std::endl;
    archivo_salida << variables;
  }

  if (!loops.Empty()) {
    archivo_salida << std::endl;
    archivo_salida << "STATEMENTS:" << std::endl;
    archivo_salida << loops; 
  }
  
  if(!switch_cases.Empty()) {
    archivo_salida << switch_cases;
  }
  archivo_salida << std::endl;
  archivo_salida << "MAIN:" << std::endl;
  if (is_there_main) {
    archivo_salida << "True" << std::endl;
  } else {
    archivo_salida << "False" << std::endl;
  }

  if (!comments.Empty()) {
    archivo_salida << std::endl;
    archivo_salida << "COMMENTS:" << std::endl;
    if (!description.Empty()) {
      archivo_salida << "[Linea " << description.GetBeginning(0) << "-" << description.GetEnd(0) << "] DESCRIPTION" << std::endl;
    }
    if (!block_comments.Empty()) {
      archivo_salida << block_comments << std::endl;
    }
    archivo_salida << comments;
  }
}

//función principal
void CodeAnalyzer(std::ifstream& archivo_entrada, std::ofstream& archivo_salida, std::string& nombre_archivo_entrada) {
  //Compruebo si el archivo se puede abrir
  if (archivo_entrada.is_open()) {
    //variables para los bloques de comentarios
    std::regex description_beginning(("/\\*\\*"));
    BlockComment description;
    BlockComment block_comments;
    bool in_description{false};
    bool in_block{false};
    int beginning{0};
    int end{0};
    int block_comments_counter{0};
    //variables para los comentarios de línea
    std::smatch line_comments_found;
    Comment line_comments;
    //variables para los bucles
    Loops loops;
    std::smatch loop_found;
    //variables para leer las líneas y el contador de la línea
    std::string line;
    int line_counter{0};
    //variables para buscar el main
    bool is_there_main{false};
    //variables para la búsqueda de variables
    Variables variables;
    //variables para el case.
    Case switch_cases;
    while (std::getline(archivo_entrada, line)) {
      line_counter++;
      //miro los bloques de comentarios
      BlockComments(line_counter, beginning, end, block_comments_counter, in_description, in_block, description, block_comments, line, description_beginning);
      //miro las lineas de comentarios
      LineComments(line, line_comments_found, line_counter, line_comments);
      if (!in_block) {
        //miro si hay main
        IsThereMain(line, is_there_main);
        //miro las lineas que tengan bucles
        LoopsFinder(line, loop_found, loops, line_counter);
        //miro las líneas que tengan la declaración de alguna variable
        VariablesFinder(line, line_counter, variables);
        if (std::regex_search(line, std::regex("\\s*case .*:$"))) {
          line = std::regex_replace(line, std::regex("\\s*case "), "");
          line = std::regex_replace(line, std::regex(":$"), "");
          switch_cases.AddLine(line, line_counter);
        }
      }
    }
    //escribo el resultado
    WriteResult(archivo_salida, nombre_archivo_entrada,  description, block_comments, line_comments, loops, is_there_main, variables, switch_cases);
  } else {
    std::cout << "Problema al abrir el archivo de entrada" << std::endl;
  }
  archivo_entrada.close();
  archivo_salida.close();
} 