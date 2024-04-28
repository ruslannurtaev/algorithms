#include "Parser.h"
#include "Solver.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout << "Enter file name" << endl;
  char FILE[15];
  cin >> FILE;
  Parser prs(FILE);
  prs.parse_file(FILE);
  vector<cell> p = prs.get_P();
  int l = p.size();
  int max_weight = prs.get_WEIGHT();
  Solver slv;
  cout << slv.result(l, p, max_weight);
  return 0;
}