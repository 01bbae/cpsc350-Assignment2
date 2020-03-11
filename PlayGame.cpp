#include "PlayGame.h"

PlayGame::PlayGame(){
  //default constructor
}

PlayGame::PlayGame(int status, Grid g, ){
  // 1 for pause
  // 2 enter to continue
  // 3 for output to a file
}
Grid PlayGame::getGeneration(){
  return grid;
}

bool PlayGame::checkEndConditions(){

  gameOver = false;
  deadCells = 0;

    if(!gameOver){
      for(int i = 0; i < game.height; i++){
        for(int j = 0; j < game.width; j++){

          if(game.grid[i][j] == '-'){
            deadCells += 1;
          }


          }
        }

        if(deadCells == game.height * game.width){
          gameOver = true;
      }
    }

    return gameOver;
}

void PlayGame::play(int gamemode, Grid g){
  if(gamemode = 1){
    //PlayClassic
    PlayClassic* p = new PlayClassic(g);

  }else if(gamemode = 2){
    //PlayDoughnut
    PlayDoughnut* p = new PlayDoughnut(g);
  }else if(gamemode = 3){
    //PlayMirror
    PlayMirror* p = new PlayMirror(g);
  }
}
