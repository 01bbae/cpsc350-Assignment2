#include "PlayMirror.h"

PlayMirror::PlayMirror(){
  //default constructor
}

PlayMirror::PlayMirror(Grid g){
  grid = g;
}

void PlayMirror::play(){
  for(int i = 0; i < game.height; i++){
    for(int j = 0; j < game.width; j++){
      neighbors = 0;

        //Cells in top row
        if(i == 0){

          //Top left corner
          if(j == 0){

            //Checking for neighbor in cell below, which would have a reflected neighbor
            if(game.grid[i+1][j] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in cell to the right, which would have a reflected neighbor
            if(game.grid[i][j+1] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in bottom right diagonal cell
            if(game.grid[i+1][j+1] = 'X'){
              neighbors += 1;
            }

            //If corner is occupied, it creates 3 neighbors due to the mirror mode
            if(game.grid[i][j] = 'X'){
              neighbors += 3;
            }

            //Determining next generation
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

            //Checking for neighbor in cell below, which would have a reflected neighbor
            if(game.grid[i+1][j] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in cell to the left, which would have a reflected neighbor
            if(game.grid[i][j-1] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in bottom left diagonal cell
            if(game.grid[i+1][j-1] = 'X'){
              neighbors += 1;
            }

            //If corner is occupied, it creates 3 neighbors due to the mirror mode
            if(game.grid[i][j] = 'X'){
              neighbors += 3;
            }

            //Determining next generation
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

            //Checking cell to the left, will create a neighbor to the upper left diagonal
            if(game.grid[i][j-1] = 'X'){
              neighbors += 2;
            }

            //Checking cell to the right, will create a neighbor to the upper right diagonal
            if(game.grid[i][j+1] = 'X'){
              neighbors += 2;
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

            //If the cell is occupied, it creates a neighbor above
            if(game.grid[i][j] = 'X'){
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

            //Checking for neighbor in cell above, will have a reflected neighbor
            if(game.grid[i-1][j] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in cell to the right, will have a reflected neighbor
            if(game.grid[i][j+1] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in upper right diagonal cell
            if(game.grid[i-1][j+1] = 'X'){
              neighbors += 1;
            }

            //If corner is occupied, it creates 3 neighbors due to the mirror mode
            if(game.grid[i][j] = 'X'){
              neighbors += 3;
            }

            //Determining next generation
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

            //Checking for neighbor in cell above, which will have a reflected neighbor
            if(game.grid[i-1][j] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in cell to the left, which will have a reflected neighbor
            if(game.grid[i][j-1] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in upper left diagonal cell
            if(game.grid[i-1][j-1] = 'X'){
              neighbors += 1;
            }

            //If corner is occupied, it creates 3 neighbors due to the mirror mode
            if(game.grid[i][j] = 'X'){
              neighbors += 3;
            }

            //Determining next generation
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

            //Checking cell to the left, will create a neighbor to the bottom left diagonal
            if(game.grid[i][j-1] = 'X'){
              neighbors += 2;
            }

            //Checking cell to the right, will create a neighbor to the lower right diagonal
            if(game.grid[i][j+1] = 'X'){
              neighbors += 2;
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

            //If cell is occupied, it reflects over the bottom axis to create a neighbor
            if(game.grid[i][j] = 'X'){
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

          //Checking cell above, creates a neighbor to the upper left diagonal of target cell
          if(game.grid[i-1][j] = 'X'){
            neighbors += 2;
          }

          //Checking cell below, creates a neighbor to the lower left diagonal of target cell
          if(game.grid[i+1][j] = 'X'){
            neighbors += 2;
          }

          //Checking cell to the right upper diagonal
          if(game.grid[i-1][j+1] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the right lower diagonal
          if(game.grid[i+1][j+1] = 'X'){
            neighbors += 1;
          }

          //If target cell is occupied, a neighbor is created reflected over the left axis
          if(game.grid[i][j] = 'X'){
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

          //Checking cell above, will create a neighbor to the upper right diagonal of target cell
          if(game.grid[i-1][j] = 'X'){
            neighbors += 2;
          }

          //Checking cell below, will create a neighbor to the lower right diagonal of target cell
          if(game.grid[i+1][j] = 'X'){
            neighbors += 2;
          }

          //Checking cell to the left upper diagonal
          if(game.grid[i-1][j-1] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the left lower diagonal
          if(game.grid[i+1][j-1] = 'X'){
            neighbors += 1;
          }

          //If target cell is occupied, it has a neighbor reflected over the right edge
          if(game.grid[i][j] = 'X'){
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
