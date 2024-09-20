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
// El main del programa donde se lleva acabo el programa. Dependiendo de lo introducido en la terminal se llevará a cabo un función u otra
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include <fstream>
#include <string>
#include "check_correct_parameters.h"
#include "alfabeto_clase.h"
#include "codigos_de_operacion.h"
#include "comprobador_apertura_archivo.h"

int main(int argc, char* argv[]) {
  if (!CheckCorrectParameters(argc, argv, 4)) {
    std::ifstream archivo_entrada(argv[1]);
    std::ofstream archivo_salida(argv[2]);
    int opcode{std::stoi(argv[3])};
    
    AperturaArchivos(archivo_entrada, archivo_salida);

    switch (opcode) {
          case 1:
            //llamo a la funcion OpcionAlfabeto para llevar a cabo la tarea
            OpcionAlfabeto(archivo_entrada, archivo_salida);
            break;
          
          case 2:
            //lamo a la funcion OpcionLongitud para llevar a cabo la tarea
            OpcionLongitud(archivo_entrada, archivo_salida);
            break;
          
          case 3:

            break;
          
          case 4:

            break;
          
          case 5:

            break;
    }

    
    
  }
  return 0;
}