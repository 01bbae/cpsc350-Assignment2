#include "PlayDoughnut.h"


PlayDoughnut::PlayDoughnut(){
  //default constructor
}

PlayDoughnut::PlayDoughnut(Grid g){
  game = g;
}

void PlayDoughnut::play(){

  for(int i = 0; i < game.height; i++){
    for(int j = 0; j < game.width; j++){
      neighbors = 0;

        //Cells in top row
        if(i = 0){

          //Top left corner
          if(j = 0){

            //Checking for neighbor in cell below
            if(game.grid[i+1][j] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the right
            if(game.grid[i][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in bottom right diagonal cell
            if(game.grid[i+1][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell in top right corner, which counts as a neighbor
            if(game.grid[0][game.width - 1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell below the top right corner, which counts as a neighbor
            if(game.grid[i+1][game.width - 1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell in bottom right corner which is a neighbor
            if(game.grid[game.height - 1][game.width-1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell in bottom left corner which is a neighbor
            if(game.grid[game.height - 1][0] = 'X'){
              neighbors += 1;
            }

            //Checking cel to the right of the bottom left corner which is a neighbor
            if(game.grid[game.height - 1][1] = 'X'){
              neighbors += 1;
            }


            //Determing next generation
            if(neighbors <= 1){
              game.nextGen[i][j] = '-';
            }else if(neighbors = 2){
              if(game.grid[i][j] = '-'){
                game.nextGen[i][j] = '-';
              }else{
                game.nextGen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              game.nextGen[i][j] = 'X';
            }else{
              game.nextGen[i][j] = '-';
            }

          }else if(j = game.width - 1){
            //Top right corner

            //Checking for neighbor in cell below
            if(game.grid[i+1][j] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the left
            if(game.grid[i][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the bottom left diagonal cell
            if(game.grid[i+1][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking if cell in top left corner is occupied, which is a neighbor
            if(game.grid[0][0] = 'X'){
              neighbors += 1;
            }

            //Checking if cell below the top left corner is occupied, which is a neighbor
            if(game.grid[1][0] = 'X'){
              neighbors += 1;
            }

            //Checking if the bottom left corner cell is occupied, which is a neighbor
            if(game.grid[game.height - 1][0] = 'X'){
              neighbors += 1;
            }

            //Checking if bottom right corner cell is occupied, which is a neighbor
            if(game.grid[game.height - 1][j] = 'X'){
              neighbors += 1;
            }

            //Checking if the cell to the left of the bottom right corner is occupied, which is a neighbor
            if(game.grid[game.height - 1][j - 1] = 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              game.nextGen[i][j] = '-';
            }else if(neighbors = 2){
              if(game.grid[i][j] = '-'){
                game.nextGen[i][j] = '-';
              }else{
                game.nextGen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              game.nextGen[i][j] = 'X';
            }else{
              game.nextGen[i][j] = '-';
            }
          }else{
            //Top row other than corners

            //Checking cell to the left
            if(game.grid[i][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the right
            if(game.grid[i][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the bottom
            if(game.grid[i+1][j] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the bottom left diagonal
            if(game.grid[i+1][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the bottom right diagonal
            if(game.grid[i+1][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking cells on bottom edge which are neighbors
            if(game.grid[game.height - 1][j] = 'X'){
              neighbors += 1;
            }

            if(game.grid[game.height - 1][j-1] = 'X'){
              neighbors += 1;
            }

            if(game.grid[game.height - 1][j+1] = 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              game.nextGen[i][j] = '-';
            }else if(neighbors = 2){
              if(game.grid[i][j] = '-'){
                game.nextGen[i][j] = '-';
              }else{
                game.nextGen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              game.nextGen[i][j] = 'X';
            }else{
              game.nextGen[i][j] = '-';
            }
          }

        }else if(i = game.height - 1){
          //Cells in bottom row

          //Bottom left corner
          if(j = 0 ){

            //Checking for neighbor in cell above
            if(game.grid[i-1][j] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the right
            if(game.grid[i][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in upper right diagonal cell of target cell
            if(game.grid[i-1][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking cell in bottom right corner, which is a neighbor
            if(game.grid[i][game.width - 1] = 'X'){
              neighbors += 1;
            }

            //Checking cell above the bottom right corner, which is a neighbor
            if(game.grid[i - 1][game.width - 1] = 'X'){
              neighbors += 1;
            }

            //Checking cell in top right corner, which is a neighbor
            if(game.grid[0][game.width - 1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell in top left corner, which is a neighbor
            if(game.grid[0][0] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in the cell to the right of the top left corner, which is a neighbor
            if(game.grid[0][1] = 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              game.nextGen[i][j] = '-';
            }else if(neighbors = 2){
              if(game.grid[i][j] = '-'){
                game.nextGen[i][j] = '-';
              }else{
                game.nextGen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              game.nextGen[i][j] = 'X';
            }else{
              game.nextGen[i][j] = '-';
            }
          }else if(j = game.width - 1){
            //Bottom right corner

            //Checking for neighbor in cell above
            if(game.grid[i-1][j] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the left
            if(game.grid[i][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in upper left diagonal cell of target cell
            if(game.grid[i-1][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell in top right corner, which is a neighbor
            if(game.grid[0][j] = 'X'){
              neighbors += 1;
            }

            //Checking for to the left of the top right corner, which is a neighbor
            if(game.grid[0][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell in top left corner, which is a neighbor
            if(game.grid[0][0] = 'X'){
              neighbors += 1;
            }

            //Checking for cell in bottom left corner, which is a neighbor
            if(game.grid[j][0] = 'X'){
              neighbors += 1;
            }

            //Checking for cell directly above the bottom left corner, which is a neighbors
            if(game.grid[i - 1][0] = 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              game.nextGen[i][j] = '-';
            }else if(neighbors = 2){
              if(game.grid[i][j] = '-'){
                game.nextGen[i][j] = '-';
              }else{
                game.nextGen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              game.nextGen[i][j] = 'X';
            }else{
              game.nextGen[i][j] = '-';
            }
          }else{
            //Bottom row other than corners

            //Checking cell to the left
            if(game.grid[i][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the right
            if(game.grid[i][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the top
            if(game.grid[i-1][j] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the upper left diagonal
            if(game.grid[i-1][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the upper right diagonal
            if(game.grid[i-1][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking cells on top edge which are neighbors
            if(game.grid[0][j] = 'X'){
              neighbors += 1;
            }

            if(game.grid[0][j-1] = 'X'){
              neighbors += 1;
            }

            if(game.grid[0][j+1] = 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              game.nextGen[i][j] = '-';
            }else if(neighbors = 2){
              if(game.grid[i][j] = '-'){
                game.nextGen[i][j] = '-';
              }else{
                game.nextGen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              game.nextGen[i][j] = 'X';
            }else{
              game.nextGen[i][j] = '-';
            }
          }
        }else if(j = 0 && 0 < i < game.height){
          //Cells on left edge (corners already accounted for in top and bottom row situations)

          //Checking cell to the right
          if(game.grid[i][j+1] = 'X'){
            neighbors += 1;
          }

          //Checking cell above
          if(game.grid[i-1][j] = 'X'){
            neighbors += 1;
          }

          //Checking cell below
          if(game.grid[i+1][j] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the right upper diagonal
          if(game.grid[i-1][j+1] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the right lower diagonal
          if(game.grid[i+1][j+1] = 'X'){
            neighbors += 1;
          }

          //Checking cells on the right edge, which are neighbors
          if(game.grid[i][game.width - 1] = 'X'){
            neighbors += 1;
          }

          if(game.grid[i-1][game.width - 1] = 'X'){
            neighbors += 1;
          }

          if(game.grid[i+1][game.width - 1] = 'X'){
            neighbors += 1;
          }

          //Determing next generation
          if(neighbors <= 1){
            game.nextGen[i][j] = '-';
          }else if(neighbors = 2){
            if(game.grid[i][j] = '-'){
              game.nextGen[i][j] = '-';
            }else{
              game.nextGen[i][j] = 'X';
            }
          }else if(neighbors = 3){
            game.nextGen[i][j] = 'X';
          }else{
            game.nextGen[i][j] = '-';
          }
        }else if(j = game.width - 1 && 0 < i < game.height){
          //Cells on right edge (corners already accounted for in top and bottom row situations)

          //Checking cell to the left
          if(game.grid[i][j-1] = 'X'){
            neighbors += 1;
          }

          //Checking cell above
          if(game.grid[i-1][j] = 'X'){
            neighbors += 1;
          }

          //Checking cell below
          if(game.grid[i+1][j] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the left upper diagonal
          if(game.grid[i-1][j-1] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the left lower diagonal
          if(game.grid[i+1][j-1] = 'X'){
            neighbors += 1;
          }

          //Checking cells on left edge, which are neighbors
          if(game.grid[0][j] = 'X'){
            neighbors += 1;
          }

          if(game.grid[0][j-1] = 'X'){
            neighbors += 1;
          }

          if(game.grid[0][j+1] = 'X'){
            neighbors += 1;
          }

          //Determing next generation
          if(neighbors <= 1){
            game.nextGen[i][j] = '-';
          }else if(neighbors = 2){
            if(game.grid[i][j] = '-'){
              game.nextGen[i][j] = '-';
            }else{
              game.nextGen[i][j] = 'X';
            }
          }else if(neighbors = 3){
            game.nextGen[i][j] = 'X';
          }else{
            game.nextGen[i][j] = '-';
          }
        }else{
          //All interior Cells

            //Cell above
            if(game.grid[i-1][j] = 'X'){
              neighbors += 1;
            }

            //Cell below
            if(game.grid[i+1][j] = 'X'){
              neighbors += 1;
            }

            //Cell right
            if(game.grid[i][j+1] = 'X'){
              neighbors += 1;
            }

            //Cell left
            if(game.grid[i][j-1] = 'X'){
              neighbors += 1;
            }

            //Cell upper left diagonal
            if(game.grid[i-1][j-1] = 'X'){
              neighbors += 1;
            }

            //Cell upper right diagonal
            if(game.grid[i-1][j+1] = 'X'){
              neighbors += 1;
            }

            //Cell lower left diagonal
            if(game.grid[i+1][j-1] = 'X'){
              neighbors += 1;
            }

            //Cell lower right diagonal
            if(game.grid[i+1][j+1] = 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              game.nextGen[i][j] = '-';
            }else if(neighbors = 2){
              if(game.grid[i][j] = '-'){
                game.nextGen[i][j] = '-';
              }else{
                game.nextGen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              game.nextGen[i][j] = 'X';
            }else{
              game.nextGen[i][j] = '-';
            }
        }
    }
  }
}

Grid PlayDoughnut::getGrid(){
  return game;
}
