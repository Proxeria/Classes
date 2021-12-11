#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

media::media() {
  title = new char[80];
  year = 0;
}

media::media(char* newtitle) {
  title = new char[80];
  strcpy(title, newtitle);
  year = 0;
}

char* media::getTitle() {
  return title;
}

int media::getYear() {
  return year;
}
