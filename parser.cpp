#include "parser.h"

void PARSER::clear() {
  if (graph == NULL)
    return;
  for (int i = 0; i < n; i++)
    if (graph[i] != NULL)
      delete[] graph[i];
  n = 0;
  l = 0;
}

void PARSER::alloc() {
  if (n <= 0 || l <= 0)
    return;
  graph = new int *[n];
  for (int i = 0; i < n; i++) {
    graph[i] = new int[n];
    std::fill_n(graph[i], n, 0);
  }
}

void PARSER::MTX() {
  if (n <= 0 || l <= 0 || graph == NULL)
    return;
  for (int i = 0; i < l; i++) {
    graph[p[i].first][p[i].second] = 1;
    graph[p[i].second][p[i].first] = 1;
  }
  return;
}

void PARSER::pars_file(std::string file) {
  this -> clear();
  std::ifstream f(file);
  int r, b;
  f >> n;
  f >> l;
  this -> alloc();
  p.reserve(l);
  for (int i = 0; i < l; i++) {
    f >> r >> b;
    p.emplace_back(std::make_pair(r, b));
  }
  f.close();
}
