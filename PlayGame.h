#include <iostream>
#include "Grid.h"

using namespace std;

class PlayGame{
public:
  Grid getGeneration();
  virtual void play();
  bool checkEndConditions();

  bool gameOver;
  int deadCells;
  Grid game;

protected:
  Grid* grid;
};
