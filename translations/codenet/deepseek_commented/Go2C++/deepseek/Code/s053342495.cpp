#include <iostream>
using namespace std;

int main() {
    // Declare a variable to store the day of Christmas
    int day;
    // Read an integer input from the user
    cin >> day;

    // Use a switch statement to determine the day of Christmas
    switch (day) {
        case 25:
            // If the day is Christmas (December 25), print "Christmas"
            cout << "Christmas" << endl;
            break;
        case 24:
            // If the day is Christmas Eve (December 24), print "Christmas Eve"
            cout << "Christmas Eve" << endl;
            break;
        case 23:
            // If the day is Christmas Eve Eve (December 23), print "Christmas Eve Eve"
            cout << "Christmas Eve Eve" << endl;
            break;
        case 22:
            // If the day is Christmas Eve Eve Eve (December 22), print "Christmas Eve Eve Eve"
            cout << "Christmas Eve Eve Eve" << endl;
            break;
    }

    return 0;
}
