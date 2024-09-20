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
// Archivo para la función que comprubea la pertura de los archivos, tanto el de entrada como el de salida
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <fstream>
#include <iostream>
#include "comprobador_apertura_archivo.h"

void AperturaArchivos(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
      //Condicional para comprobar que los archivos se abre correctamente
    if (!archivo_entrada.is_open() || !archivo_salida.is_open()) {
      std::cout << "Error en la apertura de los archivos" << std::endl;
    }
}