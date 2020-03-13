#include "Grid.h"

Grid::Grid(){
  //creating a grid
  grid = new char*[height];
  for(int i=0;i<height;++i){
    grid[i]= new char[width];
  }

  //initializing default values to null character
  for(int r=0;r<height;++r){
    for(int c=0;c<width;++c){
      grid[r][c]='\0';
    }
  }
}

Grid::Grid(char** grid, int height, int width){
  this->grid = grid;
  this->height = height;
  this->width = width;

}

Grid::Grid(int height, int width, double density){
  this->height=height;
  this->width=width;
  grid = new char*[height];
  for(int i=0;i<height;++i){
    grid[i] = new char[width];
  }

  //Initializing an unpopulated grid
  for(int r=0;r<height;++r){
    for(int c=0;c<width;++c){
      grid[r][c]='-';
    }
  }

  //fill with given density
  //floors the density if density is not a whole number
  density = floor(density*(height*width));

  while(density>0){
    for(int r=0;r<height;++r){
      for(int c=0;c<width;++c){
        if(density>0 && grid[r][c]=='-'){
          if(rand()%3==1){
            grid[r][c]='X';
            density--;
          }else{
            grid[r][c]='-';
          }
        }
      }
    }
  }


}

Grid::Grid(int height, int width){
  this->height=height;
  this->width=width;
  grid = new char*[height];
  for(int i=0;i<height;++i){
    grid[i] = new char[width];
  }

  //Initalizing an unpopulated array
  for(int r=0;r<height;++r){
    for(int c=0;c<width;++c){
      grid[r][c]='-';
    }
  }

}

Grid::~Grid(){
  //delete grid;

}

void Grid::printGrid(){
  //print generation number
  //cout << "gen: " << 0 << endl;

  //print grid
  for(int r=0;r<height;++r){
    for(int c=0;c<width;++c){
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }
}

bool Grid::isEmpty(){
  int count = 0;
  for(int r=0;r<height;++r){
    for(int c=0;c<width;++c){
      if(grid[r][c]=='-'){
        ++count;
      }
    }
  }
  if(count==(height*width)){
    return true;
  }
  return false;
}
