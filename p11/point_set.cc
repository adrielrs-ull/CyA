#include "point_set.h"
#include "sub_tree.h"
#include <algorithm>

point_set::point_set(const CyA::point_vector &points) : CyA::point_vector(points) {}

void point_set::find_incident_subtrees(const forest& st, const CyA::arc &a, int &i, int &j) const {
  i = -1;
  j = -1;

  for (size_t k = 0; k < st.size(); ++k) {
    if (st[k].contains(a.first)) {
      i = k;
    }
    if (st[k].contains(a.second)) {
      j = k;
    }
    if (i != -1 && j != -1) {
      break;
    }
  }
} 

void point_set::merge_subtrees(forest& st, const CyA::weigthed_arc &a, int i, int j) const {
  st[i].merge(st[j], a);  // Fusiona el subárbol j en el subárbol i usando el arco a
  st.erase(st.begin() + j); // Elimina el subárbol j del bosque
}

double point_set::compute_cost(void) const {
  double cost = 0.0;
  for (const CyA::arc &a : emst_) {
    cost += euclidean_distance(a);
  }
  return cost;
}

double point_set::euclidean_distance(const CyA::arc& a) const {
  double x1 = a.first.first;
  double y1 = a.first.second;
  double x2 = a.second.first;
  double y2 = a.second.second;
  return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); 
}

void point_set::EMST() {
  CyA::arc_vector av;
  compute_arc_vector(av);

  forest st;
  for (const CyA::point& p : *this) {
    EMST::sub_tree s;
    s.add_point(p);
    st.push_back(s);
  }

  for (const CyA::weigthed_arc& a : av) {
    int i, j;
    find_incident_subtrees(st, a.second, i, j);

    if (i != j) {
      merge_subtrees(st, a, i, j);
    } else {
      ++denied_unions_;
    }
  }

  emst_ = st[0].get_arcs();
}

void point_set::compute_arc_vector(CyA::arc_vector &av) const {
  av.clear(); 
  const int n = size();

  for (int i = 0; i < n - 1; ++i) {
    const CyA::point &p_i = (*this)[i];
    for (int j = i + 1; j < n; ++j) {
      const CyA::point &p_j = (*this)[j];
      const double dist = euclidean_distance(std::make_pair(p_i, p_j));
      if (dist > umbral_) {
        av.push_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
      }
      
    }
  }
  std::sort(av.begin(), av.end()); 
}

void point_set::write_tree(std::ostream &os) const {
  // Escribimos el número de arcos en el árbol
  os << emst_.size() << std::endl;

  // Iteramos sobre los arcos del árbol (EMST)
  for (const CyA::arc &a : emst_) {
    // Obtenemos los puntos del arco
    const CyA::point& p1 = a.first;
    const CyA::point& p2 = a.second;

    // Escribimos los puntos del arco
    os << "(" << p1.first << ", " << p1.second << ") - ";
    os << "(" << p2.first << ", " << p2.second << ")" << std::endl; 
  }
}

void point_set::write(std::ostream &os) const {
  // Escribimos el número de puntos en el conjunto
  os << "Número de puntos: " << size() << std::endl; 

  // Escribimos el coste total del EMST
  os << "Coste del EMST: " << compute_cost() << std::endl; 

  // Puedes añadir aquí información adicional que desees mostrar
}

int point_set::MaxIncidentArcs() {
  int max_incident_arcs{0};
  for (CyA::point p : get_points()) {
    int edges_arc{0};
    for (CyA::arc& arc : emst_) {
      if (p == arc.first || p == arc.second) {
        ++edges_arc;
      }
    }
    if (edges_arc > max_incident_arcs) {
      max_incident_arcs = edges_arc;
    }
  }  
  return max_incident_arcs;
}


