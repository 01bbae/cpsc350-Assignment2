#include <iostream>
#include "PlayGame.h"

using namespace std;

class PlayClassic{
public:
  PlayClassic();
  PlayClassic(Grid grid);
  ~PlayClassic();

  void play();
}
