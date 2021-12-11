#include <iostream>
#include <cstring>

using namespace std;

class media {
 public:
  media(char*, int);
  char* getTitle();
  int getYear();
 private:
  char* title;
  int year;
};
