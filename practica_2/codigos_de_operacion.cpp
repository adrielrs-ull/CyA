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
// Archivo que contiene todas los codigos de operacion [1...5] que se nos piden en la práctica
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo
#include <iostream>
#include <fstream>
#include "codigos_de_operacion.h"
#include "alfabeto_clase.h"

//lleva a cabo el primer apartado de la práctica
void OpcionAlfabeto(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
  if (!archivo_entrada.is_open()) { 
    std::cout << "Error al abrir el archivo" << std::endl;
  }

  if (!archivo_salida.is_open()) {
    std::cout << "Error al abrir el archivo de salida" << std::endl;
  }

  //simplemente le pongo una cabecera al documento. En este caso como hemos "calculado" el alfabeto asociado pues lo pongo de título
  archivo_salida << "---ALFABETO ASOCIADO---" << std::endl;
  std::string palabra1;
  std::string palabra2; 

  //Leo la cadena (palabra1) y el alfabeto (palabra2) del archivo de entrada
  while (archivo_entrada >> palabra1 >> palabra2) {
    Alfabeto alfabeto;

    //si un simbolo de la primera cadena está en el alfabeto lo inserto en su alfabeto asociado
    for (int i{0}; i < static_cast<int>(palabra1.size()); i++) {
      for (int j{0}; j < static_cast<int>(palabra2.size()); j++) {
        if (palabra1[i] == palabra2[j]) {
          alfabeto.InsertarEnAlfabeto(palabra1[i]);
        }
      }
    }

    

    //finalmente escribo en el archivo
    alfabeto.MostrarAlfabeto(archivo_salida);
  }

  archivo_salida.close();
  archivo_entrada.close();
}

//esta función devuelve la longitud de cada cadena del archivo
void OpcionLongitud(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
  if (!archivo_entrada.is_open()) { 
    std::cout << "Error al abrir el archivo" << std::endl;
  }


  if (!archivo_salida.is_open()) {
    std::cout << "Error al abrir el archivo de salida" << std::endl;
  }
  //título del documento
  archivo_salida << "---LONGITUD DE LAS CADENAS---" << std::endl;
  std::string palabra1, palabra2;
  while (archivo_entrada >> palabra1 >> palabra2) {
    int longitud{static_cast<int>(palabra1.size())}; //le doy el valor del size de la cadena a la variable longitud
    
    //imprimo en el documento la longitud de cada cadena
    archivo_salida << "Longitud de " << palabra1 << ": " << longitud << std::endl;
  }

  archivo_salida.close();
  archivo_entrada.close();

}