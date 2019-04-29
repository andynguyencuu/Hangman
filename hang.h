#include<iostream>
#include<string>
#include<fstream>
#include"art.h"
using namespace std;

class Hang : public Art {
    string gallowFile, gallowEndFile, *hang, *hung;
    int lives;
    ifstream hangArt, hungArt;
  public:
    Hang(string p = "", int h = 0, string g = "", string gE = "", int l = 0)
      : Art(p, h), gallowFile(g), gallowEndFile(gE), lives(l) {
        hangArt.open(getPath()+gallowFile);
        hungArt.open(getPath()+gallowEndFile);
        hang = new string[getHeight()];
        hung = new string[getHeight()];
        for (int i = 0; i < getHeight(); i++) {
          getline(hangArt, hang[i]);
          getline(hungArt, hung[i]);
        }
      }
    void draw(int line, int stage) {
      if (stage < lives - 1) { cout << hang[line]; } // game not won
      else { cout << hung[line]; }
    }
    // needs destructor
};
