#include<string>
#include<iostream>
#include<vector>
using namespace std; //fuck

class Word {
  string dictionary, word;
  int difficulty, attempts;
  vector<int> guesses;
public:
  Word(string d = "", int df = 1, int a = 0, string w = "", vector<int> g = {})
    : dictionary(d), difficulty(df), attempts(a), word(w), guesses(g) {}
  void draw() { // do this

    cout << string(26, ' ') << "_ _ _ f _ _";
  }
};
