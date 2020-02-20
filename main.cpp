#include <iostream>
#include "IO.h"

using namespace std;

int main(int argc, char** argv){
  // Grid* g = new Grid(5,6,.14);
  // g->printGrid();

  IO* io = new IO();
  io->playGame();

  return 0;
}
