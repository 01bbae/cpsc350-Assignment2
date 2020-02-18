#include <iostream>

using namespace std;
class Grid{
public:
  Grid();
  Grid(int height, int width, int density);
  ~Grid();

  //methods
  void printGrid();



  //vars
  // char* rows;
  // char* cols;
  int rows;
  int cols;

};
