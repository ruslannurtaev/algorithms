#include "solver.h"

void SOLVER::max() {
  for (int i = 0; i < n; i++)
    if (col[i] > res)
      res = col[i];
  res++;
}

void SOLVER::set(int s, int v, int **MTX) {
  this -> clear();
  n = s;
  l = v;
  graph = MTX;
  if (l <= 0 || n <= 0)
    return;
  col = new int[n];
  free_col = new int[n];
  std::fill_n(col, n, -1);
  std::fill_n(free_col, n, 1);
}

void SOLVER::clear() {
  n = 0;
  l = 0;
  graph = NULL;
  delete[] col;
  col = NULL;
  delete[] free_col;
  free_col = NULL;
}

void SOLVER::sol() {
  int cnt;
  if (col == NULL || n <= 0 || l <= 0 || graph == NULL)
    return;
  col[0] = 0;
  for (int v = 0; v < n; v++) {
    std::fill_n(free_col, n, 1);

    for (int i = 0; i < n; i++)
      if (col[i] != -1 && graph[v][i] == 1)
        free_col[col[i]] = 0;

    for (cnt = 0; cnt < n; cnt++)
      if (free_col[cnt] == 1)
        break;
    col[v] = cnt;
  }
}