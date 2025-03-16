#include <iostream>
using namespace std;

int main() {
    // Declare a variable named day of type int
    int day;

    // Read an integer value from the standard input using cin
    cin >> day;

    // Use a switch statement to determine the name of the day based on the given day number
    switch (day) {
        case 25:
            // If the day is 25, print "Christmas"
            cout << "Christmas" << endl;
            break;
        case 24:
            // If the day is 24, print "Christmas Eve"
            cout << "Christmas Eve" << endl;
            break;
        case 23:
            // If the day is 23, print "Christmas Eve Eve"
            cout << "Christmas Eve Eve" << endl;
            break;
        case 22:
            // If the day is 22, print "Christmas Eve Eve Eve"
            cout << "Christmas Eve Eve Eve" << endl;
            break;
    }

    return 0;
}
