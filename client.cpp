/*
Vitaliy Stepanov
CS300A Fall 2019
Professor Dr. Fatma Cemile Serce

Interactive console output that a user can manipulate a radiostation 
*/

#include "RadioStation.h"
#include "Song.h"
#include <iostream>
#include <string>
using namespace std;

// prompt menu to choose options
char getChoice() {
    cout << "Choose Option: " << endl;
    cout << "(a) Add song" << endl;
    cout << "(b) Remove song" << endl;
    cout << "(c) Play next song" << endl;
    cout << "(d) List all songs in playlist" << endl;
    cout << "(e) Total time of playlist " << endl;
    cout << "(q) Quit" << endl;
    char result;
    cin >> result; // stores user choice
    cout << endl;
    return result;
}

// creates a new song by asking the user for artist, title and duration
Song getSong() {
    cout << "Enter artist: ";
    string artist;
    cin.ignore();
    getline(cin, artist);  // gets user artist input

    cout << "Enter title: ";
    string title;
    cin.ignore();
    getline(cin, title); // gets user title input
    
    cout << "Enter duration (seconds only) : ";
    int duration;
    cin >> duration; // gets user int input
    
    Song newSong(title, artist, duration); // creates a song object 
    cout << endl;
    cout << "Song added!" << endl;
    cout << endl;
    return newSong;
}

// creates a song with user inputs to search in linkedlist if it exists to delete it
Song getRemoveSong() {    
    cout << "Enter artist or title to remove: " ;
    string remove;
    cin >> remove;

    Song newSong;
    newSong.setTitle(remove);
    newSong.setArtist(remove);

    cout << endl;
    cout << "Song Removed!" << endl;
    cout << endl;
    return newSong;
}


int main(){
    cout << "Welcome to Seattle's #1 Radio Station!" << endl;
    cout << endl;
    
    RadioStation *radio = new RadioStation();
    char choice = getChoice();

    while (choice != 'q') {
        if (choice == 'a') { // adds song
            Song add = getSong();
            radio->addSong(add);
        } else if (choice == 'b') { // removes song
            Song remove = getRemoveSong();
            radio->removeSong(remove); 
         } else if (choice == 'c') { // displays current song then moves to next song
            radio->playNext();
         } else if (choice == 'd') { // list all radiostation songs
             radio->listAll();
         } else if (choice == 'e') { // list total duration of all songs
             radio->totalDuration();
         }
         choice = getChoice();
    }
    cout << "Thank you for using the Radio Station. Goodbye!";
    return 0;
}
