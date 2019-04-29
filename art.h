#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class Art {
  protected:
    string path;
    int height;
  public:
    Art(string p = "", int h = 0) : path(p), height(h) {}
    string getPath() { return path; }
    int getHeight() { return height; }
    virtual void draw(int line, int state) = 0;
};
