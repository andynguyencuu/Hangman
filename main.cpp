#include<iostream>
#include<string>
#include<fstream>
#include"art.h"
#include"hang.h"
#include"man.h"
#include"word.h"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
using namespace std;

void cls() { system(CLEAR); }


int main() {

  string dictionary = "dict.txt";
  ifstream hangt("stages/hang.txt");
  ifstream hungt("stages/hung.txt");
  char guesses = '0';

  string hang[28] = {""};
  string hung[28] = {""};
  for (int i = 0; i < 28; i++) {
    getline(hangt, hang[i]);
    getline(hungt, hung[i]);
  }

  while (1) {
    cls();
    string path = "stages/man";
    string currman= path+guesses+".txt";
    ifstream mant(currman);
    string man[28] = {""};

    int line = 0;
    string tmp;

    for (int i = 0; i < 28; i++) {
      getline(mant, man[i]);
    }

    if(guesses != '9') {
      while (line < 28) {
        cout << hang[line];
        cout << man[line];
        cout << endl;
        line++;
      }
    }
    else {
      line = 0;
      while (line < 28) {
        cout << hung[line];
        cout << man[line];
        cout << endl;
        line++;
      }
      break;
    }
    cout << "\n\n\n\n";
    system("pause");
    guesses++;
  }





  return 0;
}
