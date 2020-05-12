/*
Vitaliy Stepanov
CS300A Fall 2019
Professor Dr. Fatma Cemile Serce
*/

#include "LinkedList.h"
#include "Song.h"
using namespace std;

// RadioStation object that uses a generic LinkedList to store Song objects
class RadioStation{
    private:
        LinkedList<Song> *playlist = new LinkedList<Song>; // pointer to heap memory 
        int total = 0; // counter for total duration of all songs in playlist
        
    public:
        RadioStation(); 
        void addSong(Song&); // adds a song object to a linkedlist
        void removeSong(Song&); // removes song
        void playNext(); // displays current playing song and then moves to next song
        void listAll(); // list all songs in linkedlist 
        int totalDuration(); // returns total
};

// constructor
RadioStation::RadioStation() {
}

// adds song to radiostation
void RadioStation::addSong(Song& song){ 
    playlist->insertFirst(song); 
    total += song.getDuration(); // adds to duration of playlist
}
// removes song
void RadioStation::removeSong(Song& song){ 
    playlist->remove(song); 
    total = total - song.getDuration(); // subtracts from total duration playlist
}

// displays head data then deletes head 
void RadioStation::playNext(){     
    cout << "Playing: " << endl;
    cout << endl;
    playlist->front();
    playlist->nextSong();
    cout << endl;
}

// prints all song objects in linkedlist
void RadioStation::listAll() {
    playlist->printList();
}

// returns total playlist duration
int RadioStation::totalDuration() {
    cout << "Total Duration of Playlist: " << total << endl;
    cout << endl;
    return total;
}