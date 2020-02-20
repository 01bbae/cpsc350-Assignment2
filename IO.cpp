#include "IO.h"
#include "PlayClassic.h"
#include "PlayDoughnut.h"
#include "PlayMirror.h"
#include "Grid.h"

IO::IO(){
  int input;
  int mode1;
  int output;
  cout << "1 to enter a map file" << endl;
  cout << "2 to create a random map" << endl;
  cin >> input;

  int width;
  int height;
  double density;

  PlayClassic classic;
  PlayDoughnut doughnut;
  PlayMirror mirror;

  if(input==1){
    cout << "Enter the map file name: " << endl;
    cin >> filename;
    openInFile(filename);
    cout << "Enter the map file path: " << endl;
    cin >> path;

    ifs >> height;
    ifs >> width;


    grid = new char*[height];
    for(int i = 0; i < height; ++i) {
      grid[i] = new char[width];
    }
    string buffer;
    while(ifs >> buffer){
      int i=0;
      for(int j=0;j<buffer.size();++j){
        grid[i][j] = buffer[i];
        ++i;
      }
    }
    g = new Grid(grid,height,width);
    print();

  }else if(input==2){
    cout << "Enter height of map: " << endl;
    cin >> height;
    cout << "Enter width of map: " << endl;
    cin >> width;
    cout << "Enter the initial density of the map (greater than 0 but less than 1): " << endl;
    cin >> density;
    g = new Grid(height, width, density);
    print();
  }

  cout << "What mode do you want to run in?" << endl;
  cout << "1 for Classic" << endl;
  cout << "2 for Mirror" << endl;
  cout << "3 for Doughnut" << endl;
  cin >> mode;

<<<<<<< HEAD
  cout << "How do you want each generation to be outputed?" << endl;
  cout << "1 for pause between generations" << endl;
  cout << "2 for continue on enter press" << endl;
  cout << "3 for output to a output file" << endl;
  cin >> output;

  if(output == 1){ // pause between generation
    // if(mode == 1){
    //   //play Classic mode
    while(/*condition*/){

    }
    // }else if(mode == 2){
    //   //play Mirror
    while(/*condition*/){

    }
    // }else if(mode == 3){
    //   //play Doughnut
    while(/*condition*/){

    }
    // }


  // if(mode == 1){
  //   //play Classic mode
  // }else if(mode == 2){
  //   //play Mirror
  // }else if(mode == 3){
  //   //play Doughnut
  // }

  //for pause iterate through or use sleep method?
}

IO::~IO(){
  //delete objects
}

//getter methods
string IO::getPath(){
  return path;
}
string IO::getFileName(){
  return filename;
}

//setter methods
void IO::setFileName(string filename){
  this->filename=filename;
}
void IO::setPath(string path){
  this->path=path;
}

void IO::print(){
  //implement
  g->printGrid();
}

void IO::openInFile(string filename){
  ifs.open(filename);
  if(!ifs.is_open()){
    cout << "failed to open" << endl;
    exit(EXIT_FAILURE);
    //add exit for error
  }
}

void IO::closeInFile(){
  if(ifs.is_open()){
    ifs.close();
  }
}

void openOutFile(string filename){
  ofs.open(filename);
}

void closeOutFile(){
  if(ofs.is_open()){
    ofs.close();
  }
}
