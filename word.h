#include<string>
#include<iostream>
#include<vector>
using namespace std; //fuck

class Word {
  string dictionary, word;
  int difficulty, attempts;
  vector<int> guesses;
public:
  Word(string d = "", string w = "", int df = 1, int a = 0, vector<int> g = {})
    : dictionary(d), word(w), difficulty(df), attempts(a), guesses(g) {}

};
