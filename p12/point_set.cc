#include "point_set.h"
#include <algorithm>
#include <fstream>

using namespace CyA;

point_set::point_set() : point_vector() {}

point_set::~point_set() {}

point_set::point_set(const vector<point> & points) : point_vector(points) {};

void point_set::write_hull(std::ostream & os) const {
  for (const point &p : hull_) {
    os << "(" << p.first << ",  " << p.second << ")" << std::endl;
  }
}

void point_set::write(std::ostream & os) const {
  for (const point &p : *this) {
    os << p.first << " " << p.second << std::endl;
  }
}

int point_set::find_side(const line & l, const point & p) const {
  double val = point_2_line(l, p);
  if (val > 0) {
    return side::RIGHT;
  } else if (val < 0) {
    return side::LEFT;
  } else {
    return side::CENTER;
  }
}

void point_set::x_bounds(point & min_x, point & max_x) const {
  min_x = *this->begin();
  max_x = min_x;
  for (const point &p : *this) {
    if (p.first < min_x.first) {
      min_x = p;
    } else if (p.first > max_x.first) {
      max_x = p;
    }
  }
}

void point_set::quickHull(void) {
  hull_.clear();

  CyA::point min_x_point; 
  CyA::point max_x_point;

  x_bounds(min_x_point, max_x_point);

  quickHull(CyA::line(min_x_point, max_x_point), side::LEFT);
  quickHull(CyA::line(min_x_point, max_x_point), side::RIGHT);

  // Remove duplicates
  std::sort(hull_.begin(), hull_.end());
  hull_.erase(std::unique(hull_.begin(), hull_.end()), hull_.end());
}


void point_set::quickHull(const CyA::line &l, int side) {
  CyA::point farthest;

  if (farthest_point(l, side, farthest)) {
    quickHull(CyA::line(l.first, farthest), -find_side(CyA::line(l.first, farthest), l.second));
    quickHull(CyA::line(farthest, l.second), -find_side(CyA::line(farthest, l.second), l.first));
  } else {
    hull_.push_back(l.first);
    hull_.push_back(l.second);
  }
}



bool point_set::farthest_point(const CyA::line &l, int side, CyA::point &farthest) const {
  farthest = CyA::point_vector::at(0);

  double max_dist = 0;

  bool found = false;

  for (const CyA::point &p : *this) {
    const double dist = distance(l, p);

    if (find_side(l, p) == side && dist > max_dist) {
      farthest = p;
      max_dist = dist;
      found = true;
    }
  }
  return found;
}

double point_set::point_2_line(const CyA::line &l, const CyA::point &p) const {
  const CyA::point &p1 = l.first;
  const CyA::point &p2 = l.second;

  return (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);
}

double point_set::distance(const CyA::line &l, const CyA::point &p) const {
  return fabs(point_2_line(l, p));
}


void point_set::write_hull_dot(const std::string& filename) const {
  std::ofstream dotfile(filename);

  if (!dotfile.is_open()) {
    std::cerr << "Error al abrir el archivo DOT: " << filename << std::endl;
    return;
  }

  dotfile << "graph convex_hull {\n";
  dotfile << "  node [fontsize=10];\n"; // Eliminamos shape=circle

  int i = 0;
  for (const point& p : hull_) {
    dotfile << "  " << i << " [pos=\"" << p.first << "," << p.second << "!\" shape=point];\n"; // Agregamos shape=point
    i++;
  }


  // Escribir las aristas (conexiones entre puntos)
  for (size_t i = 0; i < hull_.size() - 1; ++i) {
    dotfile << "  " << i << " -- " << i + 1 << ";\n";
  }
  dotfile << "  " << hull_.size() - 1 << " -- " << 0 << ";\n"; 

  dotfile << "}\n";
  dotfile.close();
}