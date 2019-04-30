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
void saveGame(/* get important variables and stuff from objects*/);

int main() {
  //        _____ File attributes _____
  string dictionary = "dict.txt", path = "stages/", gallowF = "hang.txt", gallowEndF = "hung.txt"; //file locations
  int artHeight = 28;
  int poopoomagoo;

  //        ____ Player attributes ____
  string name = "";
  int difficulty, guesses = 0, lives = 9;

  while (1) { //repeats until player quits
    int gameState = mainMenu(path, 24, name, difficulty);
    if (gameState == 3) break;
    if (gameState == 2) { // load game
      // ifstream data(name+".txt");
      // initialize holder variables
      // data >> holder variables;

  }



  Hang gallow(path, artHeight, gallowF, gallowEndF, lives);
  Man man(path, artHeight, lives);
  Word w(dictionary, difficulty);
  Art *g = &gallow; //polymorphism! +5 points b
  Art *m = &man;



system("pause");
  lives--;
  guesses = 0;
string guess;
while (1) {
    cls();
    for (int i = 0; i < artHeight; i++) { // put objs in array and simplify it to 1 call
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
    if (poopoomagoo == 3) {
      cout << "you won!";
      break;
    }
    else if(poopoomagoo!=1)
    {
      guesses++;
    }
  }


  if (guesses == lives) {
    cout << string(21, ' ')  << name << "'s neck gave out.\n";
    pause(); pause();
  }
}
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
void saveGame(/* get important variables and stuff from objects*/) {
  cls();
  //ofstream data(name+".txt");
  //data << variable << \n
  //save the stuff
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
