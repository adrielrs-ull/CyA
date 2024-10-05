// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 17/09/2024
// Contiene la funci´on CheckCorrectParameters
// Para comprobar que los elementos introducidos por la terminal son los correctos, además de brindar la opciónde ayuda y mostrar
// el método de empleo en caso de error
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include <cstring>
#include <string>
#include "check_correct_parameters.h"

bool CheckCorrectParameters(int argc, char* argv[], const int kLimit) {
  if (argc == kLimit) {
    
    return false;

  } else {
    //este if está porque si no salta un error por llamar a 
    std::cout << "ERROR" << std::endl;
    std::cout << "Modo de uso:" << std::endl;
    std::cout << "./p04_code_analyzer code.cc codescheme.txt" << std::endl;
    std::cout << "code.cc: código en C++ del cuál se anaizará su estructura" << std::endl;
    std::cout << "codesheme.txt: documento de salida que incluye la estructura del archivo .cc" << std::endl;
    
    return true;
  }
}