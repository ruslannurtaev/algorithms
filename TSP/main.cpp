#include "parser.h"
#include "solver.h"
#include <iostream>

int main() {
  double **M;
  int *path;
  int N;
  double pth_size;
  std::string str;
  std::cin >> str;
  Solver The_solver;
  Parser The_parser;
  The_parser.parse_file(str);
  The_parser.created_matrix();
  M = The_parser.get_matrix();
  N = The_parser.get_size();
  The_solver.init_data(N, M);
  The_solver.solve();
  pth_size = The_solver.get_pth_size();
  path = The_solver.get_path();
  std::cout << pth_size << '\n';
  for (int i = 0; i < N; i++)
    std::cout << path[i] << ' ';
  std::cout << path[0];
  std::cout << '\n';
  return 0;
}