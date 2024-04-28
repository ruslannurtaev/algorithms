#include "cell_and_node.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef PARSER_H
#define PARSER_H

class Parser {
private:
  vector<cell> P;
  char *FILE;
  int sup_m, MAX_W;

public:
  int get_N();
  std::vector<cell> get_P();
  int get_WEIGHT();
  void parse_file(std::string filename);
  Parser(char *name_file) {
    FILE = name_file; 
  }
};

#endif