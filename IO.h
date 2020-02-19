#include <iostream>
#include <fstream>
#include <ios>
#include "Grid.cpp"

using namespace std;

class IO{
public:
  IO();
  ~IO();
  string getFileName();
  string getPath();
  void setFileName(string filename);
  void setPath(string path);
  void print();
  void openInFile(string filename);
  void closeInFile();

private:
  string filename;
  string path;

  int height;
  int width;
  double density;
  Grid* g;
  char** grid;

  ifstream ifs;
  ofstream ofs;

};
