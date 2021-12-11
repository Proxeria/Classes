#include <iostream>
#include <cstring>
#include "vidGame.h"

using namespace std;

vidGame::vidGame(char* newTitle, int newYear, char* newPublisher, char* newRating) : media(newTitle, newYear) {
  rating = new char[80];
  strcpy(rating, newRating);
  publisher = new char[80];
  strcpy(publisher, newPublisher);
}

char* vidGame::getRating() {
  return rating;
}

char* vidGame::getPublish() {
  return publisher;
}

void vidGame::print() {
  media::print();
  cout << " ";
  cout << getPublish() << " " << getRating();
}
