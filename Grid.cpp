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

  // for(int r=0;r<height;++r){
  //   for(int c=0;c<width;++c){
  //     if(rand()%100<=density*100){ //fix
  //       grid[r][c]='X';
  //       density--;
  //     }else{
  //       grid[r][c]='-';
  //     }
  //   }
  // }

}

Grid::Grid(int height, int width){
  this->height=height;
  this->width=width;
  grid = new char*[height];
  for(int i=0;i<height;++i){
    grid[i] = new char[width];
  }

  for(int r=0;r<height;++r){
    for(int c=0;c<width;++c){
      grid[r][c]='-';
    }
  }

}

void Grid::printGrid(){
  //print generation number
  cout << "gen: " << 0 << endl;

  //print grid
  for(int r=0;r<height;++r){
    for(int c=0;c<width;++c){
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }
}
