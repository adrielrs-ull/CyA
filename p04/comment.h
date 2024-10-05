#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>
#include <vector>
#include <string>

class Comment {
 public:
  //Constructor por defeceto
  Comment();
  void AddComment(std::string&);
 private:
  std::vector<std::string> comments_;
};

#endif