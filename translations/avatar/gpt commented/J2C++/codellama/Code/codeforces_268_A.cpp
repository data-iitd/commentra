#include <iostream>
using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    int n; // Declaring a variable to store the number of elements (n)
    cin >> n; // Reading the number of elements (n) from the user

    // Initializing a variable to store the result of matching elements
    int result = 0;

    // Creating two arrays to hold the input values
    int h[n]; // Array to store the first set of integers
    int g[n]; // Array to store the second set of integers

    // Reading n integers into the first array (h)
    for (int i = 0; i < n; i++) {
        cin >> h[i]; // Storing input in array h
    }

    // Reading n integers into the second array (g)
    for (int i = 0; i < n; i++) {
        cin >> g[i]; // Storing input in array g
    }

    // Comparing each element of array h with each element of array g
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If a match is found, increment the result counter
            if (h[i] == g[j]) {
                result++; // Incrementing the count of matches
            }
        }
    }

    // Outputting the total number of matches found
    cout << result << endl;

    return 0;
}

