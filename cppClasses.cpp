#include <iostream>
#include <vector>
#include "media.h"
#include <string.h>

using namespace std;

const int SIZE = 2;

void printArrayDescriptions(media**, int);
void printVectorDescriptions(vector<media*> &);

int main() {
  media* list[SIZE];
  vector<media*> vect;
  char* firstDescription = new char[80];
  strcpy(firstDescription, "First Room");
  list[0] = new media(firstDescription);
  char* secondDescription = new char[80];
  strcpy(secondDescription, "Second Room");
  list[1] = new media(secondDescription);
  printArrayDescriptions(list, SIZE);
  vect.push_back(list[0]);
  vect.push_back(list[1]);
  printVectorDescriptions(vect);
}

void printArrayDescriptions(media** newlist, int size) {
  for (int a = 0; a < size; a++) {
    cout << newlist[a]->getDescription() << endl;
    //cout << *newlist[a]->getDescriptions() << endl;
  }
}

void printVectorDescriptions(vector<media*> &newvect) {
  for (vector<media*>::iterator it = newvect.begin(); it != newvect.end(); it++) {
    cout << (*it)->getDescription() << endl;
    //cout << *(*it)->getDescription() << endl;
  }
}
