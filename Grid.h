#include <iostream>
#include <cmath>

using namespace std;

class Grid{
public:
  Grid();
  Grid(char** grid, int height, int width);
  Grid(int height, int width, double density);
  ~Grid();

  //methods
  void printGrid();
  //void printGeneration(); //nessasary?


  //vars
  int height;
  int width;
  double density;
  char** grid;

};
