#include <iostream>
#include <fstream>

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
private:
  string filename;
  string path;
  ifstream ifs;
  ofstream ofs;

};
