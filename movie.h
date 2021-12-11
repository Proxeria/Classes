#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class movie : public media {
 public:
  movie(char* title, int year, char* director, char* rating, char* duration);
  char* getDirect();
  char* getRating();
  char* getDuration();
  virtual void print();
 protected:
  char* director;
  char* rating;
  char* duration;
};
