#include <iostream>
using namespace std;

// Define the main function that takes no arguments and returns nothing
void main() {

    // Declare two integer variables S and W
    int S, W;

    // Get the input as a list of two integers, S and W, using the cin function
    cin >> S >> W;

    // Check if the condition S <= W is true or false and print the corresponding message
    if (S <= W) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }
}

// End-of-code
