#include <iostream>
#include "Grid.h"

using namespace std;

class PlayGame{
public:
  Grid getGeneration();
  virtual void play();
  void checkEndConditions();

  bool gameOver;
  int deadCells;

protected:
  Grid* grid;
};
