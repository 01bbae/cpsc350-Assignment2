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
