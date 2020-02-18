#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
  int input;
  cout << "1 to enter a map file" << endl;
  cout << "2 to create a random map" << endl;
  cin >> input;


  ifstream ifs;
  ofstream ofs;
  int width;
  int height;
  double density;


  if(input==1){
    string mapfile;
    string path;
    cout << "Enter the map file name: " << endl;
    cin >> mapfile;
    cout << "Enter the map file path: " << endl;
    cin >> path;
    ifs=(path::ios);
    if(!ifs.is_open()){
      cout << "failed to open" << endl;
    }
    ifs >> height;
    ifs >> width;
    string buffer;
    while(ifs >> buffer){
      for(int i=0;i<buffer.size();++i){
        //buffer[i] something something
      }
    }
  }else if(input==2){
    cout << "Enter height of map: " << endl;
    cin >> height;
    cout << "Enter width of map: "
    cin >> width;
    cout << "Enter the initial density of the map (greater than 0 but less than 1): " << endl;
    cin >> density;
    
  }
}
