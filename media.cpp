#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

media::media() {
  description = new char[80];
  id = 0;
}

media::media(char* newdescription) {
  description = new char[80];
  strcpy(description, newdescription);
  id = 0;
}

char* media::getDescription() {
  return description;
}

int media::getID() {
  return id;
}
