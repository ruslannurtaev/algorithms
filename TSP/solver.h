#ifndef SOLVER_H
#define SOLVER_H

#include <cstddef>
#include <iostream>
#include <utility>

struct Edge {
  int from, to;
};

class Solver {
private:
  int N;
  double** graph;
  int *pth;
  double pth_size;
  void relaxation(int i, int j);
  void output_pth();

public:
  Solver() : N(0), graph(NULL), pth(NULL){};
  Solver(int s, double **matrix) : N(s), graph(matrix) {
    pth = new int[N + 1];
  };
void deletion();
void init_data(int s, double** matrix);
  ~Solver() { deletion(); };
  void solve();
  int get_size() { return N; };
  int *get_path() { return pth; };
  double get_pth_size() { return pth_size; };
};

#endif // SOLVER_H