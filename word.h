#pragma once
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Word {
  string dictionary, word, guessed, words[10001];
  int difficulty, change;
  vector<string> history;

public:
  Word(string d = "", int df = 1, string w = "", string g = "")
      : dictionary(d), difficulty(df), word(w), guessed(g) {
    if (word == "") {
      chooseWord();
      guessed = string(word.length(), '_');
    }
  }
  string getWord() { return word; }
  string getGuessed() { return guessed; }

  void draw(int i, string guess) {
    int pus = word.find(guess);
    if (i == 21) {
      cout << string(26, ' ');
      for (int i = 0; i < word.length(); i++) {
        cout << guessed[i] << " ";
      }
    }
    if ((i == 22) && (change == 1)) {
      cout << string(26, ' ');
      for (int i = 0; i < word.length(); i++) {
        if (word[i] == guess[0]) {
          cout << "^ ";
        } else {
          cout << "  ";
        }
      }
    }
  }

  void ran(int& num) { num = 1 + int(10001 * rand() / (RAND_MAX + 1.0));}

  void chooseWord() {
    srand((unsigned)time(0));
    int random;
    ifstream dict(dictionary);
    for (int i = 0; i < 10001; i++) {
      getline(dict, words[i]);
    }

    ran(random);
    switch (difficulty) {
    case 1:
      while (!(words[random].length() <= 5)) {
        ran(random);
      }
      word = words[random];
      break;
    case 2:
      while (!((words[random].length() > 5) && (words[random].length() < 8))) {
        ran(random);
      }
      word = words[random];
      break;
    case 3:
      while (!(words[random].length() > 8)) {
        ran(random);
      }
      word = words[random];
      break;
    }
  }

  int update(string guess) {
    change = 0; //incorrect guess
    if (guess == "!") {
      return 4; //save
    }
    if ((find(history.begin(), history.end(), guess) != history.end())) {
      return 5; //already guessed
    }
    history.push_back(guess);
    if (guess.length() > 1 && guess != word) {
      return 2; //incorrect word guess
    }
    for (int i = 0; i < word.length(); i++) {
      if (word[i] == guess[0]) {
        guessed[i] = word[i];
        change = 1; //correct guess
      }
    }
    if ((guessed == word) || (guess == word)) {
      return 3; //correct word guess or word completed
    }
    return change;
  }
  int getChange() { return change; }
  ~Word() {}
};
