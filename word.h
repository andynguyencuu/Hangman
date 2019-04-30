#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Word {
  string dictionary, word, guessed, words[10001];
  int difficulty, change;

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
  void draw(int i, string guess) { // do this
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
  
  void chooseWord() {
    srand((unsigned)time(0));
    int lowest = 1, highest = 10001;
    int range = (highest - lowest) + 1;

    ifstream dict(dictionary);
    for (int i = 0; i < 10001; i++) {
      getline(dict, words[i]);
    }

    int random = lowest + int(range * rand() / (RAND_MAX + 1.0));
    switch (difficulty) {
    case 1:
      while (!(words[random].length() <= 5)) {
        random = lowest + int(range * rand() / (RAND_MAX + 1.0));
      }
      word = words[random];
      break;
    case 2:
      while (!((words[random].length() > 5) && (words[random].length() < 8))) {
        random = lowest + int(range * rand() / (RAND_MAX + 1.0));
      }
      word = words[random];
      break;
    case 3:
      while (!(words[random].length() > 8)) {
        random = lowest + int(range * rand() / (RAND_MAX + 1.0));
      }
      word = words[random];
      break;
    default:
      cout << "Not an option...\nEasy mode it is!";
      break;
    }
  }

  int update(string guess) {
    change = 0;
    if (guess == "!") {
      return 4;
    }
    if (guess.length() > 1 && guess != word) {
      return 2;
    }
    for (int i = 0; i < word.length(); i++) {
      if (word[i] == guess[0]) {
        guessed[i] = word[i];
        change = 1;
      }
    }
    if ((guessed == word) || (guess == word)) {
      return 3;
    }
    return change;
  }
};
