#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class Art {
  string filename;
  int height;
public:
  Art(string f = "", int h = 0) : filename(f), height(h) {}
    //will be abstract class!
};
