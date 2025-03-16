#include <iostream>
using namespace std;

int main() {
    int n, p = 97; // Initialize variables
    cin >> n; // Read the size of the array from the user
    char c[n]; // Initialize the character array of size n

    // Nested loops to assign characters to the array
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < n; j += 4) {
            c[j] = (char)p; // Assign character and increment ASCII value
        }
        p++; // Increment the ASCII value for the next character
    }

    // Print the character array to the console
    for (int i = 0; i < n; i++) {
        cout << c[i];
    }

    return 0;
}

// <END-OF-CODE>
