// Importing necessary C++ libraries
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

// Main function starts here
int main() {
    // Reading the first integer input
    int x;
    cin >> x;

    // Initializing count variable to 0
    int count = 0;

    // Initializing temporary variable tmp with the value of x
    int tmp = x;

    // Setting x to 0
    x = 0;

    // Starting a while loop that runs until x is equal to 360
    while (x != 360) {
        // Adding the value of tmp to x
        x += tmp;

        // If x is greater than 360, then subtract 360 from it
        if (x > 360) {
            x -= 360;
        }

        // Incrementing the count variable
        count++;
    }

    // Printing the value of count to the console
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
