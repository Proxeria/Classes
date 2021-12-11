#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class vidGame : public media {
 public:
  vidGame(char* title, int year, char* publisher, char* rating);
  virtual ~vidGame();
  char* getPublish();
  char* getRating();
  virtual void print();
 protected:
  char* publisher;
  char* rating;
};
