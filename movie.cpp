#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

movie::movie(char* newTitle, int newYear, char* newPublisher, char* newRating) : media(newTitle, newYear) {
  rating = new char[80];
  strcpy(rating, newRating);
  publisher = new char[80];
  strcpy(publisher, newPublisher);
}

char* movie::getRating() {
  return rating;
}

char* movie::getPublish() {
  return publisher;
}

void movie::print() {
  media::print();
  cout << " ";
  cout << getPublish() << " " << getRating();
}
