// Importing necessary C++ libraries for reading input from the console
#include <iostream>
#include <sstream>

using namespace std;

// Main function is the entry point of the C++ application
int main() {
    // Declaring variables to store input values
    int h, a;

    // Reading a single line of input from the console
    string input;
    getline(cin, input);
    stringstream ss(input);

    // Parsing the first two integers from the input
    ss >> h >> a;

    // Initializing a variable 'num' to keep track of the number of steps
    int num = 0;

    // Using a while loop to simulate the given condition
    while (h > 0) {
        // Subtracting 'a' from 'h' in each iteration
        h -= a;

        // Incrementing the 'num' variable after each successful subtraction
        num++;
    }

    // Printing the final result 'num' to the console
    cout << num << endl;

    return 0;
}

// <END-OF-CODE>
