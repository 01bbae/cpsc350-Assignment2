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
    openInFile(filename);
    cout << "Enter the map file path: " << endl;
    cin >> path;

    ifs >> height;
    ifs >> width;

    char** grid;
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
  }else{
    cout << "no option entered" << endl;
    exit(EXIT_FAILURE);
  }
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

void IO::openOutFile(string filename){
  ofs.open(filename);
}

void IO::closeOutFile(){
  if(ofs.is_open()){
    ofs.close();
  }
}

void IO::playGame(){
  int mode;
  int output;
  cout << "What mode do you want to run in?" << endl;
  cout << "1 for Classic" << endl;
  cout << "2 for Mirror" << endl;
  cout << "3 for Doughnut" << endl;
  cin >> mode;


  cout << "How do you want each generation to be outputed?" << endl;
  cout << "1 for pause between generations" << endl;
  cout << "2 for continue on enter press" << endl;
  cout << "3 for output to a output file" << endl;
  cin >> output;

  if(mode == 1){
    PlayClassic* classic = new PlayClassic(*g);
    if(output == 1){
      //pause
      while(!(classic->getGrid()).isEmpty()){
        cout << "reached loop" << endl;
        classic->play();
        (classic->getGrid()).printGrid();
        for(int i=0;i<10000;++i){
          //pausing
        }
      }
    }else if(output == 2){
      //continue on enter
      while(!(classic->getGrid()).isEmpty()){
        classic->play();
        cin.ignore();
        (classic->getGrid()).printGrid();
      }
    }else if(output == 3){
      //output to ofs
      openOutFile("test.txt");
    }


  }else if(mode == 2){
    PlayMirror* mirror = new PlayMirror(*g);


    if(output == 1){
      //pause
      while(!(mirror->getGrid()).isEmpty()){
        mirror->play();
        (mirror->getGrid()).printGrid();
        for(int i=0;i<10000;++i){
          //pausing
        }
      }


    }else if(output == 2){
      //continue on enter
      while(!(mirror->getGrid()).isEmpty()){
        mirror->play();
        cin.ignore();
        (mirror->getGrid()).printGrid();
      }


    }else if(output == 3){
      //output to ofs
      openOutFile("test.txt");
    }





  }else if(mode == 3){
    PlayDoughnut* doughnut = new PlayDoughnut(*g);


    if(output == 1){
      //pause
      while(!(doughnut->getGrid()).isEmpty()){
        doughnut->play();
        for(int i=0;i<10000;++i){
          //pausing
        }
        (doughnut->getGrid()).printGrid();
      }


    }else if(output == 2){
      //continue on enter
      while(!(doughnut->getGrid()).isEmpty()){
        doughnut->play();
        cin.ignore();
        (doughnut->getGrid()).printGrid();
      }

    }else if(output == 3){
      //output to ofs
      openOutFile("test.txt");
    }
  }
}
