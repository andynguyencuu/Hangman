#include<string>
#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
#include<cstdlib>
using namespace std; //fuck

class Word {
  string dictionary, word, words[10001];
  int difficulty, attempts;
  vector<int> guesses;
public:
  Word(string d = "", int df = 1, int a = 0, string w = "", vector<int> g = {})
    : dictionary(d), difficulty(df), attempts(a), word(w), guesses(g) {}
  void draw() { // do this

    cout << string(26, ' ') << "_ _ _ f _ _";
  }
  void chooseWord() {
    srand((unsigned)time(0));
    int lowest=1, highest=10001;
    int range=(highest-lowest)+1;

    ifstream dict(dictionary);
    for (int i = 0; i < 10001; i++) {
      getline(dict, words[i]);
    }

    int random = lowest+int(range*rand()/(RAND_MAX + 1.0));
    switch(difficulty)
    {
      case 1:
        while(!(words[random].length()<=5))
        {
          random = lowest+int(range*rand()/(RAND_MAX + 1.0));
        }
    }
    }

};
