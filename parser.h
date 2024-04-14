#ifndef pars_h
#define pars_h

#include <fstream>
#include <utility>
#include <vector>

class PARSER {
private:
  std::vector<std::pair<int, int>> p;
  int n, l;
  int **graph;

public:
  ~PARSER() { clear(); };
  PARSER() : n(0), p(), graph(){};
  void clear();
  void MTX();
  void pars_file(std::string file);
  std::vector<std::pair<int, int>> &get_E() { return p; };
  int **get_MTX() { return graph; };
  int get_num_V() { return n; };
  void alloc();
  int get_num_E() { return l; };
};
#endif