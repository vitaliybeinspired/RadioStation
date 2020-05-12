/*
Vitaliy Stepanov
CS300A Fall 2019
Professor Dr. Fatma Cemile Serce
*/

#ifndef SONG_H_
#define SONG_H_
#include <iostream>
#include <string>
using namespace std;

// Song object that stores title, artist, and duration
class Song {
    private:
        string title, artist;
        int duration;
    public:
        Song(); // default constructor
        Song(string, string, int); // constructor
        
        void setTitle(string);
        void setArtist(string);
        void setDuration(int);
        string getTitle();
        string getArtist();
        int getDuration();

        // compares two song objects if artist or title is same
        bool operator==(const Song &rhs) const {
        return this->title == rhs.title || this->artist == rhs.artist;
        }

        bool operator!=(const Song &rhs) const {
        return !(*this == rhs); // address
        }

        // Prints artist, song, and duration of song objects feilds
        friend ostream& operator<<(ostream& os, const Song& song) {
        os<<"Artist: "<<song.artist<< endl <<"Song: "<<song.title<<endl << "Duration: " << song.duration << endl;
        return os;
        }
        
};

// default constructor
Song::Song() {
    title = "";
    artist = "";
    duration = 0;
}

// constructor to take in title, artist, and duration
Song::Song(string _title, string _artist, int _duration) {
    title = _title;
    artist = _artist;
    duration = _duration;
}

// set the title
void Song::setTitle(string _title) {
    title = _title;
}

// set the artist
void Song::setArtist(string _artist) {
    artist = _artist;
}

// set the duration
void Song::setDuration(int _duration) {
    duration = _duration;
}

// returns the title
string Song::getTitle() {
    return title;
}

//returns the artist
string Song::getArtist() {
    return artist;
}

// returns the duration
int Song::getDuration() {
    return duration;
}

#endif