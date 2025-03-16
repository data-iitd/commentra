#include <iostream> // Including iostream for input and output
#include <sstream>  // Including sstream for string stream operations

using namespace std;

int main() {
    string input; // Declaring a string to hold the input
    getline(cin, input); // Reading a line of input

    istringstream iss(input); // Creating a string stream from the input
    int h, a; // Declaring variables for height and amount to subtract
    iss >> h >> a; // Extracting the integers from the string stream

    int num = 0; // Initializing a counter to keep track of the number of subtractions

    // Implementing a loop to subtract 'a' from 'h' until 'h' is less than or equal to 0
    while (h > 0) {
        h -= a; // Subtracting 'a' from 'h'
        num++; // Incrementing the counter
    }

    cout << num << endl; // Printing the result, which is the number of subtractions
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
