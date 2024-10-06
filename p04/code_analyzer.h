#ifndef CODE_ANALYZER_H
#define CODE_ANALYZER_H

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include "comment.h"
#include "block_comment.h"
void BlockComments(int& line_counter, int& beginning, int end, int& block_comments_counter, bool& in_description, bool& in_block, Block_Comment& description, Block_Comment& block_comments, std::string line, std::regex description_beginning);
void LineComments(const std::string& line, std::smatch& line_comments_found, int& line_comments_counter, int line_counter, Comment& line_comments);
void Code_Analyzer(std::ifstream&, std::ofstream&);


#endif