#include "man.h"
#include "word.h"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
using namespace std;

void cls() { system(CLEAR); }
void pause();
int mainMenu(string path, int height, string &name, int &difficulty);
void die(string name, string word, string path);
void win(string name, string word, string path);
void saveGame(string name, int difficulty, int guesses, string word,
              string guessed);

int main() {
  //        _____ File attributes _____
  string dictionary = "dict.txt", path = "stages/", gallowF = "hang.txt",
         gallowEndF = "hung.txt"; // file locations
  int artHeight = 28, poopoomagoo;

  while (1) {
    //        ____ Player attributes ____
    string name = "", word = "", guessed = "";
    int difficulty, guesses = 0, lives = 9;

    int gameState = mainMenu(path, 25, name, difficulty);
    if (gameState == 3)
      return 0;
    if (gameState == 2) { // load game
      ifstream data(name + ".txt");
      while(!data) {
        cls();
        cout << string(3, '\n');
        cout << string(16, ' ') << name << " doesn't have a saved game!\n";
        cout << string(16, ' ') << "Try again: ";
        cin >> name;
        data.open(name + ".txt");
      }
      data >> difficulty >> guesses >> word >> guessed;
      cls();
      cout << string(3, '\n') << string(16, ' ') << "Welcome back, " << name
           << "!\n";
      pause();
    }

    Art *g = new Hang(path, artHeight, gallowF, gallowEndF, lives);
    Art *m = new Man(path, artHeight, lives);
    Word *w = new Word(dictionary, difficulty, word, guessed);

    lives--;
    string guess;
    while (1) {
      cls();
      // cout << w->getWord();
      for (int i = 0; i < artHeight; i++) {
        g->draw(i, guesses);
        m->draw(i, guesses);
        w->draw(i, guess);
        if (i == 1)
          cout << name;
        if (i == 23 && poopoomagoo == 5)
          cout << "    " << guess << " already guessed!";
        if (i == 25)
          cout << "    Lives left: " << lives - guesses;
        if (i == 27)
          cout << "    ! to save and quit";
        cout << endl;
      }
      if (guesses == lives)
        break;
      cout << string(13, ' ') << "Enter your guess: ";
      cin >> guess;
      for (int i = 0; i < guess.length(); i++) {
        if (guess[i] > 64 && guess[i] < 91) { // if uppercase
          guess[i] = guess[i] + 32;           // lowercase
        }
      }
      poopoomagoo = w->update(guess);

      switch (poopoomagoo) {
      case 0:
      case 2:
        guesses++;
        break;
      case 3:
        win(name, w->getWord(), path);
        break;
      case 4:
        saveGame(name, difficulty, guesses, w->getWord(), w->getGuessed());
        break;
      }

      if (poopoomagoo == 3 || poopoomagoo == 4)
        break;
    }

    if (guesses == lives) {
      die(name, w->getWord(), path);
    }

    delete g;
    delete m;
    delete w;
  }
  return 0;
}

int mainMenu(string path, int height, string &name, int &difficulty) {
  cls();
  if (CLEAR == "cls") {
    system("color cf");
  }
  ifstream menu(path + "menu.txt");
  int choice;
  for (int i = 0; i < height; i++) {
    string buffer;
    getline(menu, buffer);
    cout << buffer;
    if (i != height - 1)
      cout << endl;
  }
  menu.close();
  cout << " ";
  cin >> choice;
  switch (choice) {
  case 1:
    cout << "\n                   What's your name? : ";
    cin >> name;
    cout << "     Difficulty (1, Easy - 3, Hard)? : ";
    cin >> difficulty;
    if (difficulty < 1 || difficulty > 3) {
      cout << "                Not an option you dink...\n              Easy "
              "mode it is!";
      name = "Dink";
      difficulty = 1;
      pause();
    }
    break;
  case 2:
    cout << "\n                What's your name? : ";
    cin >> name;
    break;
  case 3:
    break;
  default:
    cout << "\n                What's your name? : ";
    cin >> name;
    cout << "\n                Choose difficulty (1 (Easy) - 3 (Hard)): ";
    cin >> difficulty;
    if (difficulty < 1 || difficulty > 3) {
      cout << "                Not an option you dink...\n                Easy "
              "mode it is!";
      name = "Dink";
      difficulty = 1;
      pause();
      pause();
    }
    choice = 1;
    break;
  }

  cls();
  return choice;
}

void die(string name, string word, string path) {
  cout << endl << string(21, ' ') << name << "'s neck gave out.\n\n";
  pause();
  cout << string(21, ' ') << "The word was " << word << ".\n";
  pause();
  ifstream die(path + "die.txt");
  string dieArt[24];
  time_t now = time(0);
  char *tyme = ctime(&now);
  cls();
  for (int i = 0; i < 24; i++) {
    getline(die, dieArt[i]);
    cout << dieArt[i];
    if (i == 9) {
      cout << string(25 - name.length(), ' ');
      for (int i = 0; i < name.length(); i++) {
        if (name[i] > 96 && name[i] < 123) {
          name[i] = name[i] - 32;
        }
        cout << name[i] << " ";
      }
      cout << string(23 - name.length(), ' ') << "<";
    }
    if (i == 12) {
      for (int i = 4; i < 10; i++) {
        cout << tyme[i];
      }
      cout << ", 2019|";
    }
    if (i == 16) {
      cout << " " << word;
    }
    cout << endl;
  }
  die.close();
  pause(), pause();
  if (CLEAR == "cls") {
    cout << "\n   Press any key to return to main menu!";
    system("pause >nul");
  }
}

void win(string name, string word, string path) {
  ifstream win(path + "win.txt");
  string winArt[21];
  cls();
  for (int i = 0; i < 21; i++) {
    getline(win, winArt[i]);
    cout << winArt[i];
    if (i == 8)
      cout << " " << name << "!" << string(22 - name.length(), ' ') << "\\ \\";
    if (i == 17) {
      cout << string(15 - word.length(), ' ');
      for (int i = 0; i < word.length(); i++) {
        cout << word[i] << " ";
      }
      cout << string(15 - word.length(), ' ') << "_.' '._    | |";
    }
    cout << endl;
  }
  win.close();
  pause(), pause();
  if (CLEAR == "cls") {
    cout << "\n   Press any key to return to main menu!";
    system("pause >nul");
  }
}

void saveGame(string name, int difficulty, int guesses, string word,
              string guessed) {
  cls();
  ofstream data(name + ".txt");
  data << difficulty << "\n"
       << guesses << "\n"
       << word << "\n"
       << guessed << "\n";
  data.close();
  cout << "\n\n\n" << string(15, ' ') << name << "'s game was saved!";
  pause();
  cls();
}

void pause() {
  // pause for 2 seconds, go back
  if (CLEAR == "cls") {
    system("timeout /t 3 /nobreak >nul");
  } else {
    system("ping -t 3 google.com >nul & sleep 3 >nul");
  }
}
