#include "Parser.h"

int Parser::get_WEIGHT() { 
  return MAX_W; 
}
vector<cell> Parser:: get_P() {
  return P; 
}
int Parser::get_N() {
  return sup_m; 
}

void Parser::parse_file(string name_file) {
  ifstream file_curr(name_file);
  if (file_curr.is_open() != 0) {
    file_curr >> sup_m >> MAX_W;
    for (int i = 0; i < sup_m; i++) {
      cell place;
      file_curr >> place.v >> place.w;
      P.push_back(place);
    }
  } 
  else std::cout << "Incorrect data" << std::endl;
  file_curr.close();
  
  return;
}
