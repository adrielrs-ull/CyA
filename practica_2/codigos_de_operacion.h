#ifndef CODIGOS_OPERACION_H
#define CODIGOS_OPERACION_H

#include <fstream>
#include "clase_alfabeto.h"

void OpcionAlfabeto(std::ifstream&, std::ofstream&);
void OpcionLongitud(std::ifstream&, std::ofstream&);
void OpcionInversa(std::ifstream&, std::ofstream&);
void OpcionPrefijos(std::ifstream&, std::ofstream&);
void OpcionSufijos(std::ifstream&, std::ofstream&);


#endif 

