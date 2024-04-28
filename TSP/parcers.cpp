#include "parser.h"

void Parser::allocater() {
  pnt = new point[N];
  graph = new double *[N];
  for (int i = 0; i < N; i++)
    graph[i] = new double[N];
}

void Parser::deletion() {
  N = 0;
  for (int i = 0; i < N; i++)
    delete[] graph[i];
  delete[] graph;
  delete[] pnt;
}

double dist(point a, point b) {
  double dist_x, dist_y;
  dist_x = a.x - b.x;
  dist_y = a.y - b.y;
  return sqrt(pow(dist_x, 2) + pow(dist_y, 2));
}

void Parser::created_matrix() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      graph[i][j] = dist(pnt[i], pnt[j]);
  return;
}

void Parser::parse_file(std::string f_name) {
  this->deletion();
  std::ifstream file(f_name);
  file >> N;
  this->allocater();
  for (int i = 0; i < N; i++)
    file >> pnt[i].x >> pnt[i].y;
  file.close();
}
