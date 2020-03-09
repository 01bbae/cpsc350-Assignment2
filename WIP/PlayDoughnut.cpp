#include "PlayDoughnut.h"

PlayDoughnut::PlayDoughnut(){
  //default constructor
}

PlayDoughnut::PlayDoughnut(Grid g){
  grid = g;

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      neighbors = 0;

        //Cells in top row
        if(i = 0){

          //Top left corner
          if(j = 0){

            //Checking for neighbor in cell below
            if(grid[i+1][j] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the right
            if(grid[i][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in bottom right diagonal cell
            if(grid[i+1][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell in top right corner, which counts as a neighbor
            if(grid[0][width - 1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell below the top right corner, which counts as a neighbor
            if(grid[i+1][width - 1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell in bottom right corner which is a neighbor
            if(grid[height - 1][width-1] = 'X'){
              neighbors += 1;
            }

            //Checking for cell in bottom left corner which is a neighbor
            if(grid[height - 1][0] = 'X'){
              neighbors += 1;
            }

            //Checking cel to the right of the bottom left corner which is a neighbor
            if(grid[height - 1][1] = 'X'){
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

          }else if(j = width - 1){
            //Top right corner

            //Checking for neighbor in cell below
            if(grid[i+1][j] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the left
            if(grid[i][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the bottom left diagonal cell
            if(grid[i+1][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking if cell in top left corner is occupied, which is a neighbor
            if(grid[0][0] = 'X'){
              neigbors += 1;
            }

            //Checking if cell below the top left corner is occupied, which is a neighbor
            if(grid[1][0] = 'X'){
              neighbors += 1;
            }

            //Checking if the bottom left corner cell is occupied, which is a neighbor
            if(grid[height - 1][0] = 'X'){
              neighbors += 1;
            }

            //Checking if bottom right corner cell is occupied, which is a neighbor
            if(grid[height - 1][width - 1] = 'X'){
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
            //Top row other than corners

            //Checking cell to the left
            if(grid[i][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the right
            if(grid[i][j+1] = 'X'){
              neighbors += 1;
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

            //Checking for neighbor in cell above
            if(grid[i-1][j] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the right
            if(grid[i][j+1] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in upper right diagonal cell
            if(grid[i-1][j+1] = 'X'){
              neighbors += 1;
            }

            //Corner cell can have at most three neighbors
            if(neighbors <= 1){
              nextgen[i][j] = '-';
            }else if(neighbors = 2){
              if(grid[i][j] = '-'){
                nextgen[i][j] = '-';
              }else{
                nextgen[i][j] = 'X';
              }
            }else{
              nextgen[i][j] = 'X';
            }
          }else if(j = width - 1){
            //Checking for neighbor in cell above
            if(grid[i-1][j] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in cell to the left
            if(grid[i][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking for neighbor in upper left diagonal cell
            if(grid[i-1][j-1] = 'X'){
              neighbors += 1;
            }

            //Corner cell can have at most three neighbors
            if(neighbors <= 1){
              nextgen[i][j] = '-';
            }else if(neighbors = 2){
              if(grid[i][j] = '-'){
                nextgen[i][j] = '-';
              }else{
                nextgen[i][j] = 'X';
              }
            }else{
              nextgen[i][j] = 'X';
            }
          }else{
            //Bottom row other than corners

            //Checking cell to the left
            if(grid[i][j-1] = 'X'){
              neighbors += 1;
            }

            //Checking cell to the right
            if(grid[i][j+1] = 'X'){
              neighbors += 1;
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

          //Checking cell above
          if(grid[i-1][j] = 'X'){
            neighbors += 1;
          }

          //Checking cell below
          if(grid[i+1][j] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the right upper diagonal
          if(grid[i-1][j+1] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the right lower diagonal
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
        }else if(j = width - 1 && 0 < i < height){
          //Cells on right edge (corners already accounted for in top and bottom row situations)

          //Checking cell to the left
          if(grid[i][j-1] = 'X'){
            neighbors += 1;
          }

          //Checking cell above
          if(grid[i-1][j] = 'X'){
            neighbors += 1;
          }

          //Checking cell below
          if(grid[i+1][j] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the left upper diagonal
          if(grid[i-1][j-1] = 'X'){
            neighbors += 1;
          }

          //Checking cell to the left lower diagonal
          if(grid[i+1][j-1] = 'X'){
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

void PlayDoughnut::play(){

}
