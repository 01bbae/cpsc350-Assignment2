#include <iostream>
#include "PlayGame.h"

using namespace std;

class PlayMirror{
public:
  PlayMirror();
  PlayMirror(Grid grid);
  ~PlayMirror();

  void play();

  int neighbors;
  Grid game;

};
