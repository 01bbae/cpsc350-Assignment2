#include "IO.h"

IO::IO(){
  int input;
  cout << "1 to enter a map file" << endl;
  cout << "2 to create a random map" << endl;
  cin >> input;

  int width;
  int height;
  double density;


  if(input==1){
    cout << "Enter the map file name: " << endl;
    cin >> filename;
    cout << "Enter the map file path: " << endl;
    cin >> path;
    // ifs=(path::ios); //I don't remember why I did this
    openInFile(filename);
    ifs >> height;
    ifs >> width;


    //I have no idea if this works or not
    grid = new char*[height];
    for(int i = 0; i < height; ++i) {
      grid[i] = new char[width];
    }
    string buffer;
    while(ifs >> buffer){
      int i=0;
      for(int j=0;j<buffer.size();++j){
        grid[i][j] = buffer[i];
        ++i;      }
    }
  }else if(input==2){
    cout << "Enter height of map: " << endl;
    cin >> height;
    cout << "Enter width of map: "
    cin >> width;
    cout << "Enter the initial density of the map (greater than 0 but less than 1): " << endl;
    cin >> density;
    Grid g = new Grid(height, width, density);
    
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
    this.filename=filename;
  }
  void IO::setPath(string path){
    this.path=path;
  }

  void IO::print(){
    //implement
  }

  void IO::openInFile(string filename){
    ifs.open(filename);
    if(!ifs.is_open()){
      cout << "failed to open" << endl;
      //add exit for error
    }
  }

  void IO::closeInFile(){
    if(!ifs.is_open()){
      ifs.close();
    }
  }

  // void IO::openOutFile(string outfilename){
  //   ofs::
  // }



}
