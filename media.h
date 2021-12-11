#include <iostream>
#include <cstring>

using namespace std;

class media {
 public:
  media();
  media(char*);
  char* getTitle();
  int getYear();
 private:
  char* title;
  int year;
};
