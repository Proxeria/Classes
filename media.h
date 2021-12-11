#include <iostream>
#include <cstring>

using namespace std;

class media {
 public:
  media();
  media(char*);
  char* getDescription();
  int getID();
 private:
  char* description;
  int id;
};
