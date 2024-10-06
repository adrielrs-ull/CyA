#ifndef LOOPS_H
#define LOOPS_H

#include <iostream>
#include <string>
#include <vector>

class Loops {
 public:
  void AddLoop(const std::string&, int);
  std::vector<std::string> GetLoop() const;
  std::vector<int> GetLines() const;
  friend std::ostream& operator<<(std::ostream&, Loops&);
  bool Empty();
 private:
  std::vector<std::string> loops_;
  std::vector<int> lines_;  
};


#endif