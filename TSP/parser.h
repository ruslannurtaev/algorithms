#ifndef PARSER_H
#define PARSER_H

#include <cmath>
#include <fstream>
#include <iostream>

struct point {
  double x, y;
};

class Parser {
private:
  int N;
  point *pnt;
  double **graph;

public:
  void allocater();
  void deletion();
  int get_size() { return N; };
  point *get_points() { return pnt; };
  double **get_matrix() { return graph; };
  Parser() : N(0), pnt(NULL), graph(NULL){};
  ~Parser() { deletion(); };
  void parse_file(std::string f_name);
  void created_matrix();
};
double dist(point A, point B);

#endif // PARSER_H