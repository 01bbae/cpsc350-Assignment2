#ifndef PLAYDOUGHNUT_H
#define PLAYDOUGHNUT_H
#include <iostream>
#include "Grid.h"

using namespace std;

class PlayDoughnut{
public:
  PlayDoughnut();
  PlayDoughnut(Grid* grid);
  ~PlayDoughnut();

  void play();
  Grid* getGrid();

private:
  int neighbors;
  Grid* game;
};

#endif
