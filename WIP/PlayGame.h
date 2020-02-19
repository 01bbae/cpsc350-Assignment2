#include <iostream>
#include "Grid.h"

using namespace std;

class PlayGame{
public:
  Grid getGeneration();
  virtual void play();

protected:
  Grid* grid;
};
