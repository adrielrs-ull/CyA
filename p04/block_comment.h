#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <iostream>
#include <string>
#include <vector>
typedef std::vector<std::string> block_comment;

class BlockComment {
 public:
  BlockComment();
  friend std::ostream& operator<<(std::ostream&, BlockComment&);
  std::vector<block_comment> GetBlockComment() const;
  std::vector<std::pair<int, int>> GetLines() const;
  int GetBeginning(int n) const;
  int GetEnd(int n) const;
  void SetLines(int,int);
  void PushBack(std::string&, int);
  void MostrarLineas();
  void Resize(int);
  bool Empty();

 private:
  std::vector<block_comment> block_comment_;
  std::vector<std::pair<int, int>> lines_;
};

#endif