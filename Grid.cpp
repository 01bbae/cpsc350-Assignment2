#include "Grid.h"

Grid::Grid(){
  //creating a grid
  grid = new char* [height];
  for(int i=0;i<height;++i){
    grid[i]= new char* [width];
  }

  //initializing default values to null character
  for(int r=0;r<height;++r){
    for(int c=0;c<width;++c){
      grid[r][c]='\0';
    }
  }
}

Grid::Grid(char* grid, int height, int width){
  this->grid = grid;
  this->height = height;
  this->width = width;

}

Grid::Grid(int height, int width, double density){
  grid = new char[height];
  for(int i=0;i<height;++i){
    grid[i] = new char[width];
  }
  //fill with given density
  density*=100;
  for(int r=0;r<height;++r){
    for(int c=0;c<width;++c){
      grid[r][c]='\0';
    }
  }
}

void Grid::printGrid(){
  for(int r=0;r<height;++r){
    for(int c=0;c<width;++c){
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }
}
