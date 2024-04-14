#ifndef solv_h
#define solv_h
#include <iostream>
#include <utility>

class SOLVER {
private:
  int **graph;
  int n, l, res;
  int *col;
  int *free_col;

public:
  ~SOLVER() { clear(); };
  SOLVER() : n(0), l(0), graph(), col(), free_col(), res(0){};
  SOLVER(int s, int v, int **MTX)
      : n(s), l(v), graph(MTX), col(new int[s]), free_col(new int[s]), res(0){};
  int get_num_V() { return n; };
  void clear();
  void max();
  void set(int s, int v, int **MTX);
  void sol();

  int *get_col() { return col; };
  int get_res() { return res; };
};

#endif