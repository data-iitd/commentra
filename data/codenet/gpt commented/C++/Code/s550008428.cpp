#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int s, x, d = 2; // Initialize variables: s for input, x for calculations, d for depth
    cin >> s; // Read an integer input from the user
    set<int> a; // Create a set to store unique values of s
    a.insert(s); // Insert the initial value of s into the set

    // Start an infinite loop to process the value of s
    while (1) {
        // Check if s is even
        if (s % 2 == 0) {
            x = s / 2; // If even, calculate the next value as half of s
            // Check if the new value x already exists in the set
            if (a.find(x) != a.end()) {
                cout << d << endl; // If it exists, print the depth and exit
                return 0;
            }
            a.insert(x); // Insert the new value x into the set
        } else {
            // If s is odd, calculate the next value using the formula 3*s + 1
            x = 3 * s + 1; 
            // Check if the new value x already exists in the set
            if (a.find(x) != a.end()) {
                cout << d << endl; // If it exists, print the depth and exit
                return 0;
            }
            a.insert(x); // Insert the new value x into the set
        }
        s = x; // Update s to the new value x for the next iteration
        d++; // Increment the depth counter
    }

    // This line will never be reached due to the infinite loop
    cout << d << endl; // Print the depth (not reached)

    return 0; // Return 0 to indicate successful completion of the program
}
