#include <iostream>

using namespace std;

// Define the main function
int main() {
    // Declare two integer variables S and W
    int S, W;

    // Get the input as two integers
    cin >> S >> W;

    // Check if the condition S <= W is true or false and print the corresponding message
    if (S <= W) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
