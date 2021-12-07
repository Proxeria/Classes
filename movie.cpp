#include<iostream>
#include<cstring>
//movies

using namespace std;

class movie {
public:
  movie();
  movie(char*);
  char* getDescription();
  int getID();
private:
  char* description;
  int id;
};
