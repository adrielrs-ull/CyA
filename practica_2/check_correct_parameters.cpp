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
#include "operator_overloading.h"

bool CheckCorrectParameters(int argc, char* argv[], const int kLimit, const int kLimit2) {
  if (argc == kLimit || argc == kLimit2) {
    
    return false;

  } else {
    //este if está porque si no salta un error por llamar a 
  
    
    if (argc != 2) {
      //como no se da ningún caso imprimo el modo de empleo
      std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opecode" << std::endl;
      std::cout << "Pruebe './p02_strings --help' para más información." << std::endl;
    } else {
      std::string cadena1{argv[1]};
      
      //compruebo si el número de elementos en la terminal es dos y si este es "--help" para imprimir la ayuda
      if (cadena1 == "--help") { //std::strcmp devuelve 0 si son iguales, negativo si la primera es menor y positivo si la primera es mayor
        std::cout << "Este programa pide pasar por terminal dos ficehros:" << std::endl;
        std::cout << " -1º fichero de entrada que contiene las cadenas y sus respectivos alfabetos." << std::endl;
        std::cout << " -2º fichero de salida donde se escribirán las diferentes salidas según el código de operación." << std::endl;
        std::cout << std::endl;
        std::cout << "---CÓDIGOS DE OPERACIÓN---" << std::endl;
        std::cout << " -[1] Longitud: escribir en el fichero de salida la longitud de cada cadena de entrada." << std::endl;
        std::cout << " -[2] Alfabeto: escribir en el fichero de salida el alfabeto asociado a cada una de las cadenas de entrada." << std::endl;
        std::cout << " -[3] Inversa: escribir en ek fichero de salida la inversa de cada cadena de entrada." << std::endl;
        std::cout << " -[4] Prefijos: escribir en el fichero de salida el conjunto de cadenas que son prefijos de la cadena de entrada correspondiente." << std::endl;
        std::cout << " -[5] Sufijos: escribir en el fichero de salida el conunto de cadenas que son sufijos de cada cadena de entrada correspondiente." << std::endl;
        std::cout << std::endl;
        std::cout << "Por favor, introduzca los números correspondientes para cada código de operación." << std::endl;
      } else {
        //como no se da ningún caso imprimo el modo de empleo
        std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opecode" << std::endl;
        std::cout << "Pruebe './p02_strings --help' para más información." << std::endl;
      }
    }



    return true;
  }
}