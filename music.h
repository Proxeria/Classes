#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class music : public media {
 public:
  music(char* title, int year, char* publisher, char* duration, char* artist);
  virtual ~music();
  char* getPublish();
  char* getDuration();
  char* getArtist();
  virtual void print();
 protected:
  char* publisher;
  char* duration;
  char* artist;
};
