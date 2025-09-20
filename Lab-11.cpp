#include <iostream>
#include <string>
using namespace std;

// Struct to represent a single volunteer's survey entry
// Each volunteer has a name, a number of songs, and a dynamic array to hold song titles
struct Volunteer {
    string name;        // Name of the volunteer
    int songCount;      // How many songs they listened to that day
    string* songs;      // Pointer to a dynamic array of song titles
};

int main () {
    int numVolunteers;

    // Ask the user how many volunteers are filling out the survey
    cout << "Enter number of volunteers: ";
    cin >> numVolunteers;
    cin.ignore();       // Clears leftover newline so getline() works properly later

    // Create a dynamic array of volunteers
    // We don't know the nummber in advance, so we allocate memory at runtime
    Volunteer* survey = new Volunteer[numVolunteers];

    // Loop through each volunteer to collect their survey info

    // Ask for volunteer's name

    // Ask how many songs they listened to today

    // Allocate memory for their list of songs

    // Loop through and get each song title
    
}