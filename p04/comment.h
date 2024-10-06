#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>
#include <vector>
#include <string>
class Comment {
 public:
  //Constructor por defeceto
  Comment();
  void AddComment(const std::string&, int);
  std::vector<std::string> GetComment() const;
  std::vector<int> GetLines() const;
  void Resize(int);
  friend std::ostream& operator<<(std::ostream&, Comment&);
 private:
  std::vector<std::string> comments_;
  std::vector<int> lines_;
};

#endif