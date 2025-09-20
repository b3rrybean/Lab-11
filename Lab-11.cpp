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
    // We don't know the number in advance, so we allocate memory at runtime
    Volunteer* survey = new Volunteer[numVolunteers];

    // Loop through each volunteer to collect their survey info
    for (int i = 0; i < numVolunteers; i++) {
        cout << "\nVolunteer #" << (i + 1) << endl;

        // Ask for volunteer's name
        cout << "Enter name: ";
        getline(cin, survey[i].name);

        // Ask how many songs they listened to today
        cout << "How many songs did " << survey[i].name << " listen to today? ";
        cin >> survey[i].songCount;
        cin.ignore();

        // Allocate memory for their list of songs
        survey[i].songs = new string[survey[i].songCount];

        // Loop through and get each song title
        for (int j = 0; j < survey[i].songCount; j++) {
            cout << "Enter song #" << (j + 1) << ": ";
            getline(cin, survey[i].songs[j]);
        }
    }


    // Display all results
    cout << "\n===== SURVEY RESULTS =====" << endl;

    // Go back through each volunteer and print what they entered
    for (int i = 0; i < numVolunteers; i++) {
        cout << "Volunteer: " << survey[i].name << endl;
        cout << "Songs listened today (" << survey[i].songCount <<"): ";

        // If they listened to no songs, print "None"
        if (survey[i].songCount == 0) {
            cout << "None" << endl;
        } else {
            cout << endl;

            // Otherwise, print their song list
            for (int j = 0; j < survey[i].songCount; j++) {
                cout << "  - " << survey[i].songs[j] << endl;
            }
        }
        cout << endl;
    }


    // Free memory
    for (int i = 0; i < numVolunteers; i++) {
        delete[] survey[i].songs;
    }
    delete[] survey;

    return 0;
}
