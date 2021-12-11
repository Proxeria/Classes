#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

media::media(char* newtitle, int newYear) {
  title = new char[80];
  strcpy(title, newtitle);
  year = newYear;
}

media::~media() {
  cout << "media destructor" << endl;
  delete(title);
}

char* media::getTitle() {
  return title;
}

int media::getYear() {
  return year;
}

void media::print() {
  cout << getTitle() << " " << getYear();
  
}

