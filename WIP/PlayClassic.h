#include <iostream>
#include "PlayGame.h"
#include "Grid.h"

using namespace std;

class PlayClassic{
public:
  PlayClassic();
  PlayClassic(Grid grid);
  ~PlayClassic();

  void play();

  int neighbors;
}
