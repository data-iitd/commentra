// Importing required headers
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to read a single line from stdin
string read() {
    string input;
    getline(cin, input); // Read a line from stdin
    return input; // Return the read line
}

// Main function
int main() {
    // Reading the first integer 'a' from stdin
    int a = stoi(read()); // Converting the read string to integer 'a'

    // Reading the second integer 'b' from stdin
    int b = stoi(read()); // Converting the read string to integer 'b'

    // Calculating the sum of 'a' and 'b'
    int ret = a + b;

    // Checking if the sum is less than the difference of 'a' and 'b'
    if (ret < (a - b)) {
        // If true, then update the value of 'ret'
        ret = a - b;
    }

    // Checking if the sum is less than the product of 'a' and 'b'
    if (ret < (a * b)) {
        // If true, then update the value of 'ret'
        ret = a * b;
    }

    // Printing the final value of 'ret'
    cout << ret << endl;

    // End of the code
    return 0;
}

// <END-OF-CODE>
