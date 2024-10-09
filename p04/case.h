#ifndef CASE_H
#define CASE_H
#include <iostream>
#include <vector>
#include <string>

class Case {
 public:
  std::vector<std::string> GetCase() const;
  std::vector<int> GetLines() const;
  void AddLine(const std::string&, int);
  bool Empty();
  friend std::ostream& operator<<(std::ostream&, Case&);
 private:
  std::vector<std::string> case_;
  std::vector<int> lines_;
};

#endif