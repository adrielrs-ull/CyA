// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 17/09/2024
// Función que comprueba si los simbolos de una cadena pasada se encuentran en su alfabeto
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include <fstream>
#include "simbolos_en_alfabeto.h"

bool SimbolosEnAlfabeto(const Cadena& cadena, const Cadena& alfabeto, std::ostream& salida) {
  Cadena cadena_vacia("&");
  //Si la cadena es distina de la cadena vacía
  if (cadena != cadena_vacia) {
    
    //itero dentro de la cadena símbolo por símbolo
    for (int i{0}; i < static_cast<int>(cadena.GetCadena().size()); i++) {
      bool found_symbol{false};
      //itero dentro del alfabeto símbolo por símbolo para ver si el símbolo de la cadena está, si no está hago un break y salgo gracias a la variable bool
      for (int j{0}; j < static_cast<int>(alfabeto.GetCadena().size()); j++) {
        
        //si encuentro el símbolo pongo la variable bool en true
        if (cadena.GetCadena()[i] == alfabeto.GetCadena()[j]) {
          found_symbol = true;
          break;
        }
      }

      //si no lo he encontrado entra en el if y devuelve false
      if (!found_symbol) {
        salida << "El símbolo '" << cadena.GetCadena()[i] << "' de la cadena '" << cadena.GetCadena() << "' no se encuentra en el alfabeto pasado." << std::endl; 
        return false;
      }
    }
  }


  //si todos los símbolos han sido encontrados devuelve true o si la cadena es la cadena vacia
  return true;
}