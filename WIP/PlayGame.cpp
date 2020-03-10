#include "PlayGame.h"

Grid PlayGame::getGeneration(){
  return grid;
}

bool PlayGame::checkDeadSimulationrminal(){

  gameOver = false;
  deadCells = 0;

    if(!gameOver){
      for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){

          if(grid[i][j] == '-'){
            deadCells += 1;
          }


          }
        }

        if(deadCells == height * width){
          gameOver = true;
      }
    }

    return gameOver;
}
