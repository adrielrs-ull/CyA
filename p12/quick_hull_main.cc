#include <iostream>
#include "point_set.h"

using namespace CyA;

int main() {
  point_set ps;
    // Leer los puntos desde la entrada estándar
  std::cin >> ps;

    // Calcular el Convex Hull
  ps.quickHull();

  ps.write_hull(std::cout);
    // Escribir el Convex Hull en formato DOT
  ps.write_hull_dot("convex_hull.dot");

  return 0;
}
