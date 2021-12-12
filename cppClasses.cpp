#include <iostream>
#include <vector>
#include "media.h"
#include <string.h>
#include "vidGame.h"
#include "music.h"
#include "movie.h"

using namespace std;

const int SIZE = 77;

void printArrayTitles(media**, int);
void printVectorTitles(vector<media*> &);

int test() {
  media* list[SIZE];
  vector<media*> vect;
  for (int i = 0; i < SIZE; i++) {
    list[i] = NULL;
  }
  char* firstTitle = new char[80];
  strcpy(firstTitle, "First Title");
  list[0] = new media(firstTitle, 2001);
  char* secondTitle = new char[80];
  strcpy(secondTitle, "Second Title");
  list[1] = new media(secondTitle, 1998);
  list[2] = new vidGame((char*)"Third Title", 12232, (char*)"Bungie", (char*)"M");
  list[3] = new music((char*)"Fourth Title", 23123, (char*)"Bungo", (char*)"7:27", (char*)"Beck");
  list[4] = new movie((char*)"Fifth Title", 8712634, (char*)"bungus", (char*)"R", (char*)"2:72");
  printArrayTitles(list, SIZE);
  vect.push_back(list[0]);
  vect.push_back(list[1]);
  vect.push_back(list[2]);
  vect.push_back(list[3]);
  vect.push_back(list[4]);
  printVectorTitles(vect);
  for (int i = 0; i < SIZE; i++) {
    if (list[i] == NULL) {
      break;
    }
    else {
      delete(list[i]); 
    }
  }
  return 0;
}

void printArrayTitles(media** newlist, int size) {
  for (int a = 0; a < size; a++) {
    if (newlist[a] == NULL) {
      return;
    }
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

music* getMusic() {
  char input[50];
  char tempTitle[50];
  int tempYear;
  char tempPublish[50];
  char tempDur[50];
  char tempArt[50];
  //change to cstring stuff
  cout << "Song title: ";
  cin.getline(tempTitle, 50, '\n');
  cout << "Year produced: ";
  cin.getline(input, 50, '\n');
  tempYear = atoi(input);
  cout << "Music publisher: ";
  cin.getline(tempPublish, 50, '\n');
  cout << "Song duration (in seconds): ";
  cin.getline(tempDur, 50, '\n');
  cout << "Music artist: ";
  cin.getline(tempArt, 50, '\n');

  return new music(tempTitle, tempYear, tempPublish, tempDur, tempArt);
}

vidGame* getGame() {
  char input[50];
  char tempTitle[50];
  int tempYear;
  char tempPublish[50];
  char tempRating[50];
  cout << "Game title: ";
  cin.getline(tempTitle, 50, '\n');
  cout << "Year released: ";
  cin.getline(input, 50, '\n');
  tempYear = atoi(input);
  cout << "Game publisher: ";
  cin.getline(tempPublish, 50, '\n');
  cout << "Game rating: ";
  cin.getline(tempRating, 50, '\n');

  return new vidGame(tempTitle, tempYear, tempPublish, tempRating);
}

movie* getMovie() {
  char input[50];
  char tempTitle[50];
  int tempYear;
  char tempDirect[50];
  char tempRating[50];
  char tempDur[50];
  cout << "Movie title: ";
  cin.getline(tempTitle, 50, '\n');
  cout << "Year released: ";
  cin.getline(input, 50, '\n');
  tempYear = atoi(input);
  cout << "Director: ";
  cin.getline(tempDirect, 50, '\n');
  cout << "Movie rating: ";
  cin.getline(tempRating, 50, '\n');
  cout << "Movie duration (in seconds): ";
  cin.getline(tempDur, 50, '\n');

  return new movie(tempTitle, tempYear, tempDirect, tempRating, tempDur);
}

int main() {
  test();
  
  char input[50];

  vector<media*> vectMedia;
  
  while (true) {
    //initialize empty media vector
    //print possible cmds
    cout << "COMMANDS: "<< endl << "ADD: Create a new entry to the media list"
         << endl << "PRINT: Prints all current entries in the media list"
         << endl << "DELETE: Deletes speciied media from the list"
         << endl << "QUIT: Exits the program" << endl;
    cin.getline(input, 50, '\n');
    //if ADD, add new media
    if (strcmp(input,"ADD") == 0 || strcmp(input,"add") == 0) {
      char tempIn[50];
      //make user choose media type to add
      cout << "What type of media would you linke to add? (Music, Game, or Movie): " << endl;
      if (strcmp(tempIn,"Music") == 0 || strcmp(tempIn,"music") == 0) {
	vectMedia.push_back(getMusic());
	cout << "Music added!" << endl;
      }
      else if (strcmp(tempIn,"Game") == 0 || strcmp(tempIn,"game") == 0) {
	vectMedia.push_back(getGame());
	cout << "Game added!" << endl;
      }
      if (strcmp(tempIn,"Movie") == 0 || strcmp(tempIn,"movie") == 0) {
	vectMedia.push_back(getMovie());
	cout << "Movie added!" << endl;
      }
    }
    //if PRINT, print all currently stored medias
    else if (strcmp(input,"PRINT") == 0 || strcmp(input,"print") == 0) {
      printVectorTitles(vectMedia);
    }
    //if DELETE, delete media from list
    else if (strcmp(input,"DELETE") == 0 || strcmp(input,"delete") == 0) {
      int delYear;
      cout << "Enter the year of the media you would like to remove from the list: " << endl;
      cin.getline(input, 50, '\n');
      delYear = atoi (input);
      vector<media*>::iterator it;
      for (it = vectMedia.begin(); it != vectMedia.end(); it++) {
	if (delYear == (*it)->getYear()) {
	  delete((*it));
	  vectMedia.erase(it);
	}
      }
    }
    //if QUIT, exit program
    else if (strcmp(input,"QUIT") == 0 || strcmp(input,"quit") == 0) {
      break;
    }
    //else, cmd not recognized
    else if (strcmp(input,"QUIT") != 0 && strcmp(input,"quit") != 0 && strcmp(input,"DELETE") != 0 && strcmp(input,"delete") != 0 &&
	     strcmp(input,"PRINT") != 0 && strcmp(input,"print") != 0 && strcmp(input,"ADD") != 0 && strcmp(input,"add") != 0) {
      cout << "Command not recognized" << endl;
    }
  }
}
