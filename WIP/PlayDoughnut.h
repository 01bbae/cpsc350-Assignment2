#include <iostream>
#include "PlayGame.h"

using namespace std;

class PlayDoughnut{
public:
  PlayDoughnut();
  PlayDoughnut(Grid grid);
  ~PlayDoughnut();

  void play();

  int neighbors;
};
