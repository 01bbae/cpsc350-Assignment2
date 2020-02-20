#ifndef PLAYMIRROR_H
#define PLAYMIRROR_H
#include <iostream>
#include "Grid.h"

using namespace std;

class PlayMirror{
public:
  PlayMirror();
  PlayMirror(Grid* grid);
  ~PlayMirror();

  void play();
  Grid* getGrid();

private:
  int neighbors;
  Grid* game;

};

#endif
