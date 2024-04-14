#include "parser.h"
#include "solver.h"
#include <iostream>
#include <utility>
#include <vector>

int main() {
  PARSER P;
  SOLVER S;
  std::string str;
  std::cin >> str;
  P.pars_file(str);
  P.MTX();
  int n, l;
  n = P.get_num_V();
  l = P.get_num_E();
  int **g = P.get_MTX();
  auto p = P.get_E();
  S.set(n, l, g);
  S.sol();
  S.max();
  int *col = S.get_col();
  int ans = S.get_res();
  std::cout << ans;
  return 0;
}
