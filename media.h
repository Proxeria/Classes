#include <iostream>
#include <cstring>

using namespace std;

class media {
 public:
  media(char*, int);
  char* getTitle();
  int getYear();
  virtual void print();
 protected:
  char* title;
  int year;
};
