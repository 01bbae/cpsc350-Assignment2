#include <iostream>

using namespace std;
class Grid{
public:
  Grid();
  Grid(char ar[][],int height, int width);
  Grid(int height, int width, int density);
  ~Grid();

  //methods
  void printGrid();
  void printGeneration();


  //vars
  int height;
  int width;
  char* rows;
  char* cols;

};
