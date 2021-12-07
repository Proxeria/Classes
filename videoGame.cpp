#include <iostream>
#include <cstring>
//video games

using namespace std;

class videoGame {
public:
  videoGame();
  videoGame(char*);
  char* getDescription();
  int getID();
private:
  char* description;
  int id:
};
