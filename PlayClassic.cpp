#include "PlayClassic.h"

PlayClassic::PlayClassic(){
  //default constructor
}

PlayClassic::PlayClassic(Grid* g){
  game = g;
  nextGen = new Grid(g->height,g->width);

}

PlayClassic::~PlayClassic(){
  delete game;
  delete nextGen;
}

void PlayClassic::play(){
  for(int i = 0; i < game->height; i++){
    for(int j = 0; j < game->width; j++){
      neighbors = 0;

        //Cells in top row
        if(i == 0){

          //Top left corner
          if(j == 0){

            //Checking for neighbor in cell below
            if(game->grid[i+1][j] == 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the right
            if(game->grid[i][j+1] == 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in bottom right diagonal cell
            if(game->grid[i+1][j+1] == 'X'){
              neighbors += 1;
            }
            //Corner cell can have at most three neighbors
            if(neighbors <= 1){
              nextGen->grid[i][j] = '-';
            }else if(neighbors == 2){
              if(game->grid[i][j] == '-'){
                nextGen->grid[i][j] = '-';
              }else{
                nextGen->grid[i][j] = 'X';
              }
            }else{
              nextGen->grid[i][j] = 'X';
            }
          }else if(j == game->width - 1){
            //Top right corner

            //Checking for neighbor in cell below
            if(game->grid[i+1][j] == 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the left
            if(game->grid[i][j-1] == 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in bottom left diagonal cell
            if(game->grid[i+1][j-1] == 'X'){
              neighbors += 1;
            }

            //Corner cell can have at most three neighbors
            //Determining next generation
            if(neighbors <= 1){
              nextGen->grid[i][j] = '-';
            }else if(neighbors == 2){
              if(game->grid[i][j] == '-'){
                nextGen->grid[i][j] = '-';
              }else{
                nextGen->grid[i][j] = 'X';
              }
            }else{
              nextGen->grid[i][j] = 'X';
            }
          }else{
            //Top row other than corners

            //Checking cell to the left
            if(game->grid[i][j-1] == 'X'){
              neighbors += 1;
            }

            //Checking cell to the right
            if(game->grid[i][j+1] == 'X'){
              neighbors += 1;
            }

            //Checking cell to the bottom
            if(game->grid[i+1][j] == 'X'){
              neighbors += 1;
            }

            //Checking cell to the bottom left diagonal
            if(game->grid[i+1][j-1] == 'X'){
              neighbors += 1;
            }

            //Checking cell to the bottom right diagonal
            if(game->grid[i+1][j+1] == 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              nextGen->grid[i][j] = '-';
            }else if(neighbors == 2){
              if(game->grid[i][j] == '-'){
                nextGen->grid[i][j] = '-';
              }else{
                nextGen->grid[i][j] = 'X';
              }
            }else if(neighbors == 3){
              nextGen->grid[i][j] = 'X';
            }else{
              nextGen->grid[i][j] = '-';
            }
          }

        }else if(i == game->height - 1){
          //Cells in bottom row

          //Bottom left corner
          if(j == 0 ){

            //Checking for neighbor in cell above
            if(game->grid[i-1][j] == 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the right
            if(game->grid[i][j+1] == 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in upper right diagonal cell
            if(game->grid[i-1][j+1] == 'X'){
              neighbors += 1;
            }

            //Corner cell can have at most three neighbors
            if(neighbors <= 1){
              nextGen->grid[i][j] = '-';
            }else if(neighbors == 2){
              if(game->grid[i][j] == '-'){
                nextGen->grid[i][j] = '-';
              }else{
                nextGen->grid[i][j] = 'X';
              }
            }else{
              nextGen->grid[i][j] = 'X';
            }
          }else if(j == game->width - 1){
            //Checking for neighbor in cell above
            if(game->grid[i-1][j] == 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the left
            if(game->grid[i][j-1] == 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in upper left diagonal cell
            if(game->grid[i-1][j-1] == 'X'){
              neighbors += 1;
            }

            //Corner cell can have at most three neighbors
            if(neighbors <= 1){
              nextGen->grid[i][j] = '-';
            }else if(neighbors == 2){
              if(game->grid[i][j] == '-'){
                nextGen->grid[i][j] = '-';
              }else{
                nextGen->grid[i][j] = 'X';
              }
            }else{
              nextGen->grid[i][j] = 'X';
            }
          }else{
            //Bottom row other than corners

            //Checking cell to the left
            if(game->grid[i][j-1] == 'X'){
              neighbors += 1;
            }

            //Checking cell to the right
            if(game->grid[i][j+1] == 'X'){
              neighbors += 1;
            }

            //Checking cell to the top
            if(game->grid[i-1][j] == 'X'){
              neighbors += 1;
            }

            //Checking cell to the upper left diagonal
            if(game->grid[i-1][j-1] == 'X'){
              neighbors += 1;
            }

            //Checking cell to the upper right diagonal
            if(game->grid[i-1][j+1] == 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              nextGen->grid[i][j] = '-';
            }else if(neighbors == 2){
              if(game->grid[i][j] == '-'){
                nextGen->grid[i][j] = '-';
              }else{
                nextGen->grid[i][j] = 'X';
              }
            }else if(neighbors == 3){
              nextGen->grid[i][j] = 'X';
            }else{
              nextGen->grid[i][j] = '-';
            }
          }
        }else if(j == 0 && 0 < i < game->height){
          //Cells on left edge (corners already accounted for in top and bottom row situations)

          //Checking cell to the right
          if(game->grid[i][j+1] == 'X'){
            neighbors += 1;
          }

          //Checking cell above
          if(game->grid[i-1][j] == 'X'){
            neighbors += 1;
          }

          //Checking cell below
          if(game->grid[i+1][j] == 'X'){
            neighbors += 1;
          }

          //Checking cell to the right upper diagonal
          if(game->grid[i-1][j+1] == 'X'){
            neighbors += 1;
          }

          //Checking cell to the right lower diagonal
          if(game->grid[i+1][j+1] == 'X'){
            neighbors += 1;
          }

          //Determing next generation
          if(neighbors <= 1){
            nextGen->grid[i][j] = '-';
          }else if(neighbors == 2){
            if(game->grid[i][j] == '-'){
              nextGen->grid[i][j] = '-';
            }else{
              nextGen->grid[i][j] = 'X';
            }
          }else if(neighbors == 3){
            nextGen->grid[i][j] = 'X';
          }else{
            nextGen->grid[i][j] = '-';
          }
        }else if(j == game->width - 1 && 0 < i < game->height){
          //Cells on right edge (corners already accounted for in top and bottom row situations)

          //Checking cell to the left
          if(game->grid[i][j-1] == 'X'){
            neighbors += 1;
          }

          //Checking cell above
          if(game->grid[i-1][j] == 'X'){
            neighbors += 1;
          }

          //Checking cell below
          if(game->grid[i+1][j] == 'X'){
            neighbors += 1;
          }

          //Checking cell to the left upper diagonal
          if(game->grid[i-1][j-1] == 'X'){
            neighbors += 1;
          }

          //Checking cell to the left lower diagonal
          if(game->grid[i+1][j-1] == 'X'){
            neighbors += 1;
          }

          //Determing next generation
          if(neighbors <= 1){
            nextGen->grid[i][j] = '-';
          }else if(neighbors == 2){
            if(game->grid[i][j] == '-'){
              nextGen->grid[i][j] = '-';
            }else{
              nextGen->grid[i][j] = 'X';
            }
          }else if(neighbors == 3){
            nextGen->grid[i][j] = 'X';
          }else{
            nextGen->grid[i][j] = '-';
          }
        }else{
          //All interior Cells

            //Cell above
            if(game->grid[i-1][j] == 'X'){
              neighbors += 1;
            }

            //Cell below
            if(game->grid[i+1][j] == 'X'){
              neighbors += 1;
            }

            //Cell right
            if(game->grid[i][j+1] == 'X'){
              neighbors += 1;
            }

            //Cell left
            if(game->grid[i][j-1] == 'X'){
              neighbors += 1;
            }

            //Cell upper left diagonal
            if(game->grid[i-1][j-1] == 'X'){
              neighbors += 1;
            }

            //Cell upper right diagonal
            if(game->grid[i-1][j+1] == 'X'){
              neighbors += 1;
            }

            //Cell lower left diagonal
            if(game->grid[i+1][j-1] == 'X'){
              neighbors += 1;
            }

            //Cell lower right diagonal
            if(game->grid[i+1][j+1] == 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              nextGen->grid[i][j] = '-';
            }else if(neighbors == 2){
              if(game->grid[i][j] == '-'){
                nextGen->grid[i][j] = '-';
              }else{
                nextGen->grid[i][j] = 'X';
              }
            }else if(neighbors == 3){
              nextGen->grid[i][j] = 'X';
            }else{
              nextGen->grid[i][j] = '-';
            }
        }
    }
  }
  *game = *nextGen;
}

Grid PlayClassic::getGrid(){
  return *game;
}
