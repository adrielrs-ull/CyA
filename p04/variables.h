#ifndef VARIABLES_H
#define VARIABLES_H
#include <iostream>
#include <vector>
#include <string>

class Variables {
 public:
  Variables() : int_counter_{0}, double_counter_{0} {}
  std::vector<std::pair<std::string, std::string>> GetVariables() const;
  int GetIntCounter() const ;
  int GetDoubleCounter() const;
  std::vector<int> GetLines() const;
  void AddLine(const std::string&, const std::string&, int);
  void AddInt();
  void AddDouble();
  bool Empty();
  friend std::ostream& operator<<(std::ostream&, Variables&);
 private:
  int int_counter_;
  int double_counter_;
  std::vector<std::pair<std::string, std::string>> variables_;
  std::vector<int> lines_;
};

#endif