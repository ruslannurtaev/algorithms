#include "cell_and_node.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#ifndef SOLVER_H
#define SOLVER_H

class Solver {
public:
  int result(int N, std:: vector<cell> arr, int W);
  int limit(int N, std:: vector<cell> ar_cell, node x, int W);
};
int comparator(cell x, cell y);
#endif