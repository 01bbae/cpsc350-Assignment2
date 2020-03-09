#include "PlayMirror.h"

PlayMirror::PlayMirror(){
  //default constructor
}


//We could make this method a lot shorter by creating another method that makes the next generation grid and checks the neighbor cases, and call that wherever i have the checks in place for creating the next grid generation
PlayMirror::PlayMirror(Grid g){
  grid = g;


  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      neighbors = 0;

        //Cells in top row
        if(i = 0){

          //Top left corner
          if(j = 0){

            //Checking for neighbor in cell below, which would have a reflected neighbor
            if(grid[i+1][j] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in cell to the right, which would have a reflected neighbor
            if(grid[i][j+1] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in bottom right diagonal cell
            if(grid[i+1][j+1] = 'X'){
              neighbors += 1;
            }

            //If corner is occupied, it creates 3 neighbors due to the mirror mode
            if(grid[i][j] = 'X'){
              neighbors += 3;
            }

            //Determining next generation
            if(neighbors <= 1){
              nextgen[i][j] = '-';
            }else if(neighbors = 2){
              if(grid[i][j] = '-'){
                nextgen[i][j] = '-';
              }else{
                nextgen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              nextgen[i][j] = 'X';
            }else{
              nextgen[i][j] = '-';
            }
          }else if(j = width - 1){
            //Top right corner

            //Checking for neighbor in cell below, which would have a reflected neighbor
            if(grid[i+1][j] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in cell to the left, which would have a reflected neighbor
            if(grid[i][j-1] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in bottom left diagonal cell
            if(grid[i+1][j-1] = 'X'){
              neighbors += 1;
            }

            //If corner is occupied, it creates 3 neighbors due to the mirror mode
            if(grid[i][j] = 'X'){
              neighbors += 3;
            }

            //Determining next generation
            if(neighbors <= 1){
              nextgen[i][j] = '-';
            }else if(neighbors = 2){
              if(grid[i][j] = '-'){
                nextgen[i][j] = '-';
              }else{
                nextgen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              nextgen[i][j] = 'X';
            }else{
              nextgen[i][j] = '-';
            }
          }else{
            //Top row other than corners

            //Checking cell to the left, will create a neighbor to the upper left diagonal
            if(grid[i][j-1] = 'X'){
              neighbors += 2;
            }

            //Checking cell to the right, will create a neighbor to the upper right diagonal
            if(grid[i][j+1] = 'X'){
              neighbors += 2;
            }

            //Checking cell to the bottom
            if(grid[i+1][j] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the bottom left diagonal
            if(grid[i+1][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the bottom right diagonal
            if(grid[i+1][j+1] = 'X'){
              neighbors += 1;
            }

            //If the cell is occupied, it creates a neighbor above
            if(grid[i][j] = 'X'){
              neigbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              nextgen[i][j] = '-';
            }else if(neighbors = 2){
              if(grid[i][j] = '-'){
                nextgen[i][j] = '-';
              }else{
                nextgen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              nextgen[i][j] = 'X';
            }else{
              nextgen[i][j] = '-';
            }
          }

        }else if(i = height - 1){
          //Cells in bottom row

          //Bottom left corner
          if(j = 0 ){

            //Checking for neighbor in cell above, will have a reflected neighbor
            if(grid[i-1][j] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in cell to the right, will have a reflected neighbor
            if(grid[i][j+1] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in upper right diagonal cell
            if(grid[i-1][j+1] = 'X'){
              neighbors += 1;
            }

            //If corner is occupied, it creates 3 neighbors due to the mirror mode
            if(grid[i][j] = 'X'){
              neighbors += 3;
            }

            //Determining next generation
            if(neighbors <= 1){
              nextgen[i][j] = '-';
            }else if(neighbors = 2){
              if(grid[i][j] = '-'){
                nextgen[i][j] = '-';
              }else{
                nextgen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              nextgen[i][j] = 'X';
            }else{
              nextgen[i][j] = '-';
            }
          }else if(j = width - 1){
            //Bottom right corner

            //Checking for neighbor in cell above, which will have a reflected neighbor
            if(grid[i-1][j] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in cell to the left, which will have a reflected neighbor
            if(grid[i][j-1] = 'X'){
              neighbors += 2;
            }

            //Checking for neighbor in upper left diagonal cell
            if(grid[i-1][j-1] = 'X'){
              neighbors += 1;
            }

            //If corner is occupied, it creates 3 neighbors due to the mirror mode
            if(grid[i][j] = 'X'){
              neighbors += 3;
            }

            //Determining next generation
            if(neighbors <= 1){
              nextgen[i][j] = '-';
            }else if(neighbors = 2){
              if(grid[i][j] = '-'){
                nextgen[i][j] = '-';
              }else{
                nextgen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              nextgen[i][j] = 'X';
            }else{
              nextgen[i][j] = '-';
            }
          }else{
            //Bottom row other than corners

            //Checking cell to the left, will create a neighbor to the bottom left diagonal
            if(grid[i][j-1] = 'X'){
              neighbors += 2;
            }

            //Checking cell to the right, will create a neighbor to the lower right diagonal
            if(grid[i][j+1] = 'X'){
              neighbors += 2;
            }

            //Checking cell to the top
            if(grid[i-1][j] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the upper left diagonal
            if(grid[i-1][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the upper right diagonal
            if(grid[i-1][j+1] = 'X'){
              neighbors += 1;
            }

            //If cell is occupied, it reflects over the bottom axis to create a neighbor
            if(grid[i][j] = 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              nextgen[i][j] = '-';
            }else if(neighbors = 2){
              if(grid[i][j] = '-'){
                nextgen[i][j] = '-';
              }else{
                nextgen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              nextgen[i][j] = 'X';
            }else{
              nextgen[i][j] = '-';
            }
          }
        }else if(j = 0 && 0 < i < height){
          //Cells on left edge (corners already accounted for in top and bottom row situations)

          //Checking cell to the right
          if(grid[i][j+1] = 'X'){
            neighbors += 1;
          }

          //Checking cell above, creates a neighbor to the upper left diagonal of target cell
          if(grid[i-1][j] = 'X'){
            neighbors += 2;
          }

          //Checking cell below, creates a neighbor to the lower left diagonal of target cell
          if(grid[i+1][j] = 'X'){
            neighbors += 2;
          }

          //Checking cell to the right upper diagonal
          if(grid[i-1][j+1] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the right lower diagonal
          if(grid[i+1][j+1] = 'X'){
            neighbors += 1;
          }

          //If target cell is occupied, a neighbor is created reflected over the left axis
          if(grid[i][j] = 'X'){
            neighbors += 1;
          }

          //Determing next generation
          if(neighbors <= 1){
            nextgen[i][j] = '-';
          }else if(neighbors = 2){
            if(grid[i][j] = '-'){
              nextgen[i][j] = '-';
            }else{
              nextgen[i][j] = 'X';
            }
          }else if(neighbors = 3){
            nextgen[i][j] = 'X';
          }else{
            nextgen[i][j] = '-';
          }
        }else if(j = width - 1 && 0 < i < height){
          //Cells on right edge (corners already accounted for in top and bottom row situations)

          //Checking cell to the left
          if(grid[i][j-1] = 'X'){
            neighbors += 1;
          }

          //Checking cell above, will create a neighbor to the upper right diagonal of target cell
          if(grid[i-1][j] = 'X'){
            neighbors += 2;
          }

          //Checking cell below, will create a neighbor to the lower right diagonal of target cell
          if(grid[i+1][j] = 'X'){
            neighbors += 2;
          }

          //Checking cell to the left upper diagonal
          if(grid[i-1][j-1] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the left lower diagonal
          if(grid[i+1][j-1] = 'X'){
            neighbors += 1;
          }

          //If target cell is occupied, it has a neighbor reflected over the right edge
          if(grid[i][j] = 'X'){
            neighbors += 1;
          }

          //Determing next generation
          if(neighbors <= 1){
            nextgen[i][j] = '-';
          }else if(neighbors = 2){
            if(grid[i][j] = '-'){
              nextgen[i][j] = '-';
            }else{
              nextgen[i][j] = 'X';
            }
          }else if(neighbors = 3){
            nextgen[i][j] = 'X';
          }else{
            nextgen[i][j] = '-';
          }
        }else{
          //All interior Cells

            //Cell above
            if(grid[i-1][j] = 'X'){
              neighbors += 1;
            }

            //Cell below
            if(grid[i+1][j] = 'X'){
              neighbors += 1;
            }

            //Cell right
            if(grid[i][j+1] = 'X'){
              neighbors += 1;
            }

            //Cell left
            if(grid[i][j-1] = 'X'){
              neighbors += 1;
            }

            //Cell upper left diagonal
            if(grid[i-1][j-1] = 'X'){
              neighbors += 1;
            }

            //Cell upper right diagonal
            if(grid[i-1][j+1] = 'X'){
              neighbors += 1;
            }

            //Cell lower left diagonal
            if(grid[i+1][j-1] = 'X'){
              neighbors += 1;
            }

            //Cell lower right diagonal
            if(grid[i+1][j+1] = 'X'){
              neighbors += 1;
            }

            //Determing next generation
            if(neighbors <= 1){
              nextgen[i][j] = '-';
            }else if(neighbors = 2){
              if(grid[i][j] = '-'){
                nextgen[i][j] = '-';
              }else{
                nextgen[i][j] = 'X';
              }
            }else if(neighbors = 3){
              nextgen[i][j] = 'X';
            }else{
              nextgen[i][j] = '-';
            }
        }
    }
  }
}

void PlayMirror::NextGeneration(){
  
}

void PlayMirror::play(){

}
