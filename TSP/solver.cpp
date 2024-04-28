#include "solver.h"

void Solver::deletion() {
  N = 0;
  graph = NULL;
  delete[] pth;
}

void Solver::output_pth() {
  for (int i = 0; i <= N; i++)
    std::cout << pth[i] << "  "
              << "\n"
              << std::endl;
}

void Solver::init_data(int s, double **matrix) {
  this->deletion();
  N = s;
  graph = matrix;
  pth = new int[s + 1];
}

void Solver::solve() {
  for (int i = 0; i < N; i++)
    pth[i] = i;
  pth[N] = 0;
  for (int i = 0; i < N - 2; i++)
    for (int j = N; j >= i + 3; j--) {
      // std::cout << "i = " << i << ", j = " << j << '\n';
      this->relaxation(i, j);
      // this->PrithPath();
    }

  pth_size = 0;
  for (int i = 0; i < N; i++)
    pth_size += graph[pth[i]][pth[i + 1]];
}

void Solver::relaxation(int i, int j) {
  double curr_r, new_r, p, q;
  curr_r = graph[pth[i]][pth[i + 1]] + graph[pth[j]][pth[j - 1]];
  new_r = graph[pth[i]][pth[j - 1]] + graph[pth[j]][pth[i + 1]];
  if (new_r < curr_r) {
    p = i + 1;
    q = j - 1;
    while (p < q) {
      std::swap(pth[static_cast<size_t>(p)], pth[static_cast<size_t>(q)]);
      p++;
      q--;
    }
  }
}
