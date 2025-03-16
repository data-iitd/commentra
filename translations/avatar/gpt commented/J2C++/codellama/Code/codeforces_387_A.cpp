#include <iostream> // Including iostream for input/output operations
#include <string> // Including string for working with strings
#include <sstream> // Including sstream for string stream operations

using namespace std; // Using standard namespace

int main() { // Main function
    string s, t; // Declaring two strings for input
    getline(cin, s); // Reading two time inputs in "HH:MM" format and splitting them into hours and minutes
    getline(cin, t);
    stringstream ss(s), st(t); // Creating string stream objects from the input strings
    int xh, xm, yh, ym; // Declaring four integers for the first and second time
    ss >> xh >> xm; // Extracting the hours and minutes from the first time
    st >> yh >> ym; // Extracting the hours and minutes from the second time
    LocalTime x = LocalTime.of(xh, xm); // Creating LocalTime objects from the input strings for the first and second time
    LocalTime y = LocalTime.of(yh, ym);
    cout << x.minusHours(y.getHour()).minusMinutes(y.getMinute()) << endl; // Calculating the difference between the two times and printing the result
    return 0; // Returning 0 to indicate successful execution
}

