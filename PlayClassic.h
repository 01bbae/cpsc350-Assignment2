#ifndef PLAYCLASSIC_H
#define PLAYCLASSIC_H
#include <iostream>
#include "Grid.h"

using namespace std;

class PlayClassic{
public:
  PlayClassic();
  PlayClassic(Grid grid);
  ~PlayClassic();

  void play();
  Grid getGrid();

private:
  int neighbors;
  Grid game;
};

#endif
