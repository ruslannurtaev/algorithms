#include "Solver.h"
#define c -1;

int Solver:: limit(int N, vector<cell> ar_cell, node x, int WEIGHT) {
  if (WEIGHT > x.wght) {
    int free_lim = 0, k = 0, w_curr = 0;
    k = x.lyr + 1;
    w_curr = x.wght;
    free_lim = x.free_pl;
    while ((k < N) && WEIGHT >= (w_curr + ar_cell[k].w)) {
      free_lim += ar_cell[k].v;
      w_curr += ar_cell[k].w;
      k++;
    }
    if (k < N)
      free_lim = free_lim + (WEIGHT - w_curr) * ar_cell[k].v / ar_cell[k].w;
    return free_lim;
  } 
  else return 0;
}

int comparator(cell x, cell y) {
  double tmp_x = 0, tmp_y = 0;
  tmp_x = (double)x.v / x.w;
  tmp_y = (double)y.v / y.w;
  if (tmp_x > tmp_y)
    return 1;
  else
    return 0;
}

int Solver:: result(int N, vector<cell> arr, int WEIGHT) {
  sort(arr.begin(), arr.end(), comparator);
  int max_place = 0;
  node x, y;
  x.free_pl = x.wght = 0;
  x.lyr = -1;
  queue<node> Q;
  Q.push(x);
  while (Q.empty() == 0) {
    x = Q.front();
    Q.pop();
    if (x.lyr == -1)
      y.lyr = 0;
    if (x.lyr == N - 1) continue;
    y.lyr = x.lyr + 1;
    y.wght = x.wght + arr[y.lyr].w;
    y.free_pl = x.free_pl + arr[y.lyr].v;
    if (y.free_pl > max_place && y.wght <= WEIGHT) max_place = y.free_pl;
    y.lim = limit(N, arr, y, WEIGHT);
    if (y.lim > max_place) Q.push(y);
    y.free_pl = x.free_pl;
    y.wght = x.wght;
    y.lim = limit(N, arr, y, WEIGHT);
    if (y.lim > max_place) Q.push(y);
  }
  return max_place;
}
