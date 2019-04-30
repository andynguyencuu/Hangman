#include<iostream>
#include<string>
#include<fstream>

#include"man.h"
#include"word.h"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
using namespace std;

void cls() { system(CLEAR); }
void pause();
int mainMenu(string path, int height, string &name, int &difficulty); // print the menu & options, prompt player to load or new game
void blankGame(/* add objects and vars)*/) {}
void saveGame(string name, int difficulty, int guesses, string word, string guessed);

int main() {
  //        _____ File attributes _____
  string dictionary = "dict.txt", path = "stages/", gallowF = "hang.txt", gallowEndF = "hung.txt"; //file locations
  int artHeight = 28;
  int poopoomagoo;

  //        ____ Player attributes ____
  string name = "", word = "", guessed = "";
  int difficulty, guesses = 0, lives = 9;

  // while (1) { //repeats until player quits
    int gameState = mainMenu(path, 25, name, difficulty);
    if (gameState == 3) return 0;
    if (gameState == 2) { // load game
      ifstream data(name+".txt");
      data >> difficulty >> guesses >> word >> guessed;
  }



  Hang gallow(path, artHeight, gallowF, gallowEndF, lives);
  Man man(path, artHeight, lives);
  Word w(dictionary, difficulty, word, guessed);
  Art *g = &gallow; //polymorphism! +5 points b
  Art *m = &man;



lives--;
string guess;
while (1) {
    cls();
    cout << w.getWord();
    for (int i = 0; i < artHeight; i++) {
      g->draw(i, guesses);
      m->draw(i, guesses);
      w.draw(i, guess);
      if (i == 1) cout << name;
      if (i == 24) cout << "    Lives left: " << lives - guesses;
      cout << endl;
    }
    if (guesses == lives) break; // so we can render the death
    cout << "Enter your guess (lowercase): ";
    cin >> guess;
    poopoomagoo=w.update(guess);
    if (poopoomagoo == 3) { // win condition
      ifstream win(path+"win.txt");
      string winArt[23];
      cls();
      for (int i = 0; i < 23; i++) {
        getline(win, winArt[i]);
        cout << winArt[i];
        if (i == 8) cout << " " << name << "!" << string(19 - name.length(), ' ') << "\\ \\";
        if (i == 22) cout << " " << w.getWord() << ".\n\n";
        cout << endl;
      }
      win.close();

      pause();
      break;
    }
    else if (poopoomagoo == 4) {
      saveGame(name, difficulty, guesses, w.getWord(), w.getGuessed());
    }
    else if(poopoomagoo!=1)
    {
      guesses++;
    }
  }


  if (guesses == lives) {
    cout << string(21, ' ')  << name << "'s neck gave out.\n\n";
    pause();
    cout << string(21, ' ') << "The word was " << w.getWord() << ".";
    pause();
  }
// }
  return 0;
}

int mainMenu(string path, int height, string &name, int &difficulty) {
  cls();
  if (CLEAR == "cls") { system("color cf"); }
  ifstream menu(path+"menu.txt");
  int choice;
  for (int i = 0; i < height; i++) {
    string buffer;
    getline(menu, buffer);
    cout << buffer;
    if (i != height - 1) cout << endl;
  }
  menu.close();
  cin >> choice;
  switch (choice) {
    case 1:
      cout << "\n              What's your name? : ";
      cin >> name;
      cout << "              Difficulty (1-3)? : ";
      cin >> difficulty;
      break;
    case 2:
      cout << "\n              What's your name? : ";
      cin >> name;
      break;
    case 3:
      break;
    default:
      cout << "\n              What's your name? : ";
      cin >> name;
      cout << "\n              Choose difficulty (1-3): ";
      cin >> difficulty;
      choice = 1;
      break; }

  cls();
  return choice;
}

void saveGame(string name, int difficulty, int guesses, string word, string guessed) {
  cls();
  ofstream data(name+".txt");
  data << difficulty << "\n" << guesses << "\n" << word << "\n" << guessed << "\n";
  data.close();
  cout << "\n\n\n" << string(15, ' ') << name << "'s game was saved!";
  pause();
  cls();
}

void pause() {
  //pause for 2 seconds, go back
  if (CLEAR == "cls") {
    system("timeout /t 2 /nobreak >nul");
  }
  else {
    system("ping -t 2 google.com >nul & sleep 2 >nul");
  }
}
