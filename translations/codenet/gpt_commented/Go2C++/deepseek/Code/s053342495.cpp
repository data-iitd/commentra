#include <iostream>
using namespace std;

int main() {
    // Declare a variable to hold the day of the month
    int day;
    
    // Read an integer input from the user representing the day
    cin >> day;

    // Use a switch statement to determine the holiday based on the day
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
