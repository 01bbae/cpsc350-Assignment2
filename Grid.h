#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <cmath>

using namespace std;

class Grid{
public:
  Grid();
  Grid(char** grid, int height, int width);
  Grid(int height, int width, double density);
  Grid(int height, int width);
  ~Grid();

  //methods
  void printGrid();
  bool isEmpty();


  //vars
  int height;
  int width;
  double density;
  char** grid;

};

#endif
