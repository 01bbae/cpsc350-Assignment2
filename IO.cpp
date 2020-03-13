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

    char** grid = new char*[height];
    for(int i = 0; i < height; ++i) {
      grid[i] = new char[width];
    }
    string buffer;
    int i=0;
    while(ifs >> buffer){
      for(int j=0;j<buffer.size();++j){
        grid[i][j] = buffer[j];
      }
      ++i;
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
  delete grid;
  delete g;

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
  int generation = 0;
  int mode;
  int output;
  int max;
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
  if(output == 3){
    cout << "Enter maximum number of generations" <<endl;
    cin >> max;
  }

  if(mode == 1){
    PlayClassic* classic = new PlayClassic(g);
    if(output == 1){
      //pause
      while((!(classic->getGrid()).isEmpty())){
        classic->play();
        cout << "generation: " << generation <<endl;
        (classic->getGrid()).printGrid();
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<"<< endl;
        generation++;
        this_thread::sleep_for (chrono::seconds(1));
      }
    }else if(output == 2){
      //continue on enter
      while(!(classic->getGrid()).isEmpty()){
        classic->play();
        cin.get();
        cout << "generation: " << generation <<endl;
        (classic->getGrid()).printGrid();
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<"<< endl;
        generation++;
      }
    }else if(output == 3){
      //output to ofs
      openOutFile("output.txt");
      if(!ofs.is_open()){
        cout << "ofstream not open" << endl;
        exit(EXIT_FAILURE);
      }
      while(generation<=max){
        ofs << "generation: " << generation << endl;
        for(int i = 0; i<classic->getGrid().height;++i){
          for(int j = 0; j<classic->getGrid().width;++j){
            ofs << *((*((classic->getGrid()).grid+i))+j) << " ";
          }
          ofs << endl;
        }
        ofs <<  "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        generation++;
        classic->play();
      }
    }else{
      cout << "output method undefined or not an option" << endl;
      exit(EXIT_FAILURE);
    }
    delete classic;

  }else if(mode == 2){
    PlayMirror* mirror = new PlayMirror(g);
    if(output == 1){
      //pause
      while(!(mirror->getGrid()).isEmpty()){
        mirror->play();
        cout << "generation: " << generation <<endl;
        (mirror->getGrid()).printGrid();
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<"<< endl;
        generation++;
        this_thread::sleep_for (chrono::seconds(3));
      }
    }else if(output == 2){
      //continue on enter
      while(!(mirror->getGrid()).isEmpty()){
        mirror->play();
        cin.get();
        cout << "generation: " << generation <<endl;
        (mirror->getGrid()).printGrid();
      }
    }else if(output == 3){
      //output to ofs
      openOutFile("output.txt");
      while(generation<=max){
        if(!ofs.is_open()){
          cout << "ofstream not open" << endl;
          exit(EXIT_FAILURE);
        }
        ofs << "generation: " << generation << endl;
        for(int i = 0; i<mirror->getGrid().height;++i){
          for(int j = 0; j<mirror->getGrid().width;++j){
            ofs << *((*((mirror->getGrid()).grid+i))+j) << " ";
          }
          ofs << endl;
        }
        ofs <<  "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        generation++;
        mirror->play();
      }
      delete mirror;
    }
  }else if(mode == 3){
    PlayDoughnut* doughnut = new PlayDoughnut(g);
    cout << "doughnut" << endl;
    if(output == 1){
      //pause
      while(!(doughnut->getGrid()).isEmpty()){
        doughnut->play();
        cout << "generation: " << generation <<endl;
        (doughnut->getGrid()).printGrid();
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<"<< endl;
        generation++;
        this_thread::sleep_for (chrono::seconds(3));
      }
    }else if(output == 2){
      //continue on enter
      while(!(doughnut->getGrid()).isEmpty()){
        doughnut->play();
        cin.get();
        cout << "generation: " << generation <<endl;
        (doughnut->getGrid()).printGrid();
      }
    }else if(output == 3){
      //output to ofs
      openOutFile("output.txt");
      ofs << "mirror mode" << endl;
      while(generation<=max){
        if(!ofs.is_open()){
          cout << "ofstream not open" << endl;
          exit(EXIT_FAILURE);
        }
        ofs << "generation: " << generation << endl;
        for(int i = 0; i<doughnut->getGrid().height;++i){
          for(int j = 0; j<doughnut->getGrid().width;++j){
            ofs << *((*((doughnut->getGrid()).grid+i))+j) << " ";
          }
          ofs << endl;
        }
        ofs <<  "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        generation++;
        doughnut->play();
      }
    }else{
      cout << "output method undefined or not an option" << endl;
      exit(EXIT_FAILURE);
    }
    delete doughnut;
  }else{
    cout << "non existent option" << endl;
    exit(EXIT_FAILURE);
  }
}
