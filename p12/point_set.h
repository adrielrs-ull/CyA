#pragma once

#include <iostream>
#include <vector>
#include <cmath>

namespace CyA {
  typedef std::pair<double,double> point;
  typedef std::pair<point, point> line;
  typedef std::vector<point> point_vector;
 
  enum side{LEFT = -1, CENTER, RIGHT};
 
  class point_set : public point_vector {
   public:
    point_set();
    point_set(const vector<point> &points);
    ~point_set(void);
    
    void quickHull(void);

    int GetMaxValueR() const {return max_valor_recursividad_;}

    void write_hull(std::ostream &os) const;
    void write(std::ostream &os) const;
    void write_hull_dot(const std::string& filename) const;
 
    inline const point_vector& get_hull(void) const { return hull_; }
    inline const point_vector& get_points(void) const { return *this; }

    friend  std::istream& operator>>(std::istream& is, point_set& ps) {
      int numPuntos;
      is >> numPuntos; // Leer el número de puntos
      
      std::vector<point> points;
      double x, y;
      for (int i = 0; i < numPuntos; ++i) { // Leer la cantidad especificada de puntos
        if (!(is >> x >> y)) { // Manejo de errores de lectura
          std::cerr << "Error al leer el punto " << i + 1 << std::endl;
          break; 
        }
        points.push_back({x, y});
      }
      ps = point_set(points);
      return is;
    }
    
   private:
    point_vector hull_;
    void quickHull(const line &l, int side);
    
    int max_valor_recursividad_{0};

    double distance(const line &l, const point &p) const;
    int find_side(const line &l, const point &p) const;
    void x_bounds(point &min_x, point &max_x) const;
    double point_2_line(const line &l, const point &p) const;
    bool farthest_point(const line &l, int side, point &farthest) const;
  };
}