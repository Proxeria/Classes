#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

music::music(char* newTitle, int newYear, char* newPublisher, char* newDuration, char* newArtist) : media(newTitle, newYear) {
  duration = new char[80];
  strcpy(duration, newDuration);
  publisher = new char[80];
  strcpy(publisher, newPublisher);
  artist = new char[80];
  strcpy(artist, newArtist);
}

music::~music() {
  delete(publisher);
  delete(duration);
  delete(artist);
  cout << "music deconstructor" << endl;
}

char* music::getDuration() {
  return duration;
}

char* music::getPublish() {
  return publisher;
}

char* music::getArtist() {
  return artist;
}

void music::print() {
  media::print();
  cout << " ";
  cout << getPublish() << " " << getDuration() << " " << getArtist();
}
