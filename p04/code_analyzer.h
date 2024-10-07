#ifndef CODE_ANALYZER_H
#define CODE_ANALYZER_H

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include "comment.h"
#include "block_comment.h"
#include "loops.h"
#include "variables.h"

void CodeAnalyzer(std::ifstream&, std::ofstream&, std::string&);


#endif