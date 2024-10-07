#ifndef LOOPS_H
#define LOOPS_H

#include <iostream>
#include <string>
#include <vector>

class Loops {
 public:
  Loops() : counter_for_{0}, counter_while_{0} {}
  void AddLoop(const std::string&, int);
  std::vector<std::string> GetLoop() const;
  std::vector<int> GetLines() const;
  friend std::ostream& operator<<(std::ostream&, Loops&);
  bool Empty();
  void AddCounterFor();
  void AddCounterWhile();
  int GetCounterFor();
  int GetCounterWhile();
 private:
  std::vector<std::string> loops_;
  std::vector<int> lines_; 
  int counter_for_;
  int counter_while_;
};


#endif