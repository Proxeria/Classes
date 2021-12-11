#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

movie::movie(char* newTitle, int newYear, char* newDirector, char* newRating, char* newDuration) : media(newTitle, newYear) {
  rating = new char[80];
  strcpy(rating, newRating);
  director = new char[80];
  strcpy(director, newDirector);
  duration = new char[80];
  strcpy(duration, newDuration);
}

char* movie::getRating() {
  return rating;
}

char* movie::getDirect() {
  return director;
}

char* movie::getDuration() {
  return duration;
}

void movie::print() {
  media::print();
  cout << " ";
  cout << getDirect() << " " << getRating() << " " << getDuration();
}
