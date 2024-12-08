#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "point_set.h"

int main(int argc, char* argv[]) {
  // Procesamiento de argumentos de línea de comandos
  bool generarDOT = false;
  std::string nombreArchivoDOT;
  for (int i = 1; i < argc; ++i) {
    if (std::string(argv[i]) == "-d") {
      generarDOT = true;
      if (i + 1 < argc) {
        nombreArchivoDOT = argv[i + 1];
        ++i;
      } else {
        std::cerr << "Error: Falta el nombre del archivo DOT después de -d" 
                  << std::endl;
        return 1;
      }
    }
  }

  // Lectura de puntos desde la entrada estándar
  CyA::point_vector puntos;
  std::cin >> puntos;

  // Creación del conjunto de puntos y cálculo del EMST
  point_set ps(puntos);
  ps.EMST();

  // Escritura de información a la salida estándar
  ps.write(std::cout);
  ps.write_tree(std::cout);

  // Generación del archivo DOT si se especificó la opción -d
if (generarDOT) {
  std::ofstream archivoDOT(nombreArchivoDOT);
  if (archivoDOT.is_open()) {
    archivoDOT << "graph {" << std::endl;

    //  Escribir nodos con posiciones
    int i = 0; 
    for (const CyA::point &p : ps.get_points()) {
      archivoDOT << "  " << i << " [pos = \"" << p.first << "," << p.second << "!\"];" << std::endl;
      ++i;
    }

    // Escribir aristas 
    for (const CyA::arc &a : ps.get_tree()) {
      const CyA::point& p1 = a.first;
      const CyA::point& p2 = a.second;

      // Encontrar los índices de los puntos
      int indice_p1 = std::distance(ps.get_points().begin(), std::find(ps.get_points().begin(), ps.get_points().end(), p1));
      int indice_p2 = std::distance(ps.get_points().begin(), std::find(ps.get_points().begin(), ps.get_points().end(), p2));

      archivoDOT << "  " << indice_p1 << " -- " << indice_p2 << ";" << std::endl;
    }

    archivoDOT << "}" << std::endl;
    archivoDOT.close();
    std::cout << "Archivo DOT generado: " << nombreArchivoDOT << std::endl;
  } else {
    std::cerr << "Error: No se pudo crear el archivo DOT: " 
              << nombreArchivoDOT << std::endl;
    return 1;
  }
}

  return 0;
}