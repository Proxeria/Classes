#include <iostream>
#include <vector>
//#include "media.h"
#include <string.h>
#include "vidGame.h"

using namespace std;

const int SIZE = 2;

void printArrayTitles(media**, int);
void printVectorTitles(vector<media*> &);

int main() {
  media* list[SIZE];
  vector<media*> vect;
  char* firstTitle = new char[80];
  strcpy(firstTitle, "First Title");
  list[0] = new media(firstTitle, 2001);
  char* secondTitle = new char[80];
  strcpy(secondTitle, "Second Title");
  list[1] = new media(secondTitle, 1998);
  list[2] = new vidGame((char*)"Third Title", 12232, (char*)"Bungie", (char*)"M");
  printArrayTitles(list, SIZE);
  vect.push_back(list[0]);
  vect.push_back(list[1]);
  vect.push_back(list[2]);
  printVectorTitles(vect);
}

void printArrayTitles(media** newlist, int size) {
  for (int a = 0; a < size; a++) {
    // cout << newlist[a]->getTitle() << " " << newlist[a]->getYear() << endl;
    newlist[a]->print();
    cout << endl;
    //cout << *newlist[a]->getTitles() << endl;
  }
}

void printVectorTitles(vector<media*> &newvect) {
  for (vector<media*>::iterator it = newvect.begin(); it != newvect.end(); it++) {
    // cout << (*it)->getTitle() << " " << (*it)->getYear() << endl;
    (*it)->print();
    cout << endl;
    //cout << *(*it)->getTitle() << endl;
  }
}
