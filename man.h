#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"hang.h"
using namespace std;

class Man : public Art {
    char clives;
    string **man;
    int lives;
    ifstream manArt;
  public:
    Man(string p = "", int h = 0, int s = 0)
      : Art(p, h), lives(s) {
        man = new string*[lives]; // level 1, lives
        for (int i = 0; i < lives; i++) {
          man[i] = new string[getHeight()]; // level 2, lines of each man
        }

        for (int i = 0; i < lives; i++) {
          clives = '0' + i; // cast lives as a char
          manArt.open(getPath()+"man"+clives+".txt");
          for (int j = 0; j < getHeight(); j++) {
            getline(manArt, man[i][j]);
          }
          manArt.close();
        }
    }
    void draw(int line, int stage) {
      cout << man[stage][line];
    }
    ~Man() {
      for (int i = 0; i < lives; i++) {
        delete [] man[i];
      }
      delete [] man;
    }
};
