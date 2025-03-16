#include <iostream> // For input and output
#include <vector> // For using dynamic arrays (vectors)
#include <algorithm> // For using sort function
#include <limits> // For numeric limits

using namespace std;

int main() {
    // Read input integers a, b, c, and d
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Check if c is greater than b
    if (c > b) {
        // If yes, print 0 and exit
        cout << 0 << endl;
        return 0;
    }
    // Check if a is greater than d
    else if (a > d) {
        // If yes, print 0 and exit
        cout << 0 << endl;
        return 0;
    }
    // Check if a is less than c
    else if (a < c) {
        // If yes, calculate the difference between the smaller and larger of b and d
        int difference = min(b, d) - c;
        // Print the difference
        cout << difference << endl;
        return 0;
    }
    // If none of the above conditions are true, then a, b, c, and d are in sorted order
    else {
        // Create a vector of integers a, b, c, and d
        vector<int> l = {a, b, c, d};

        // Sort the vector in ascending order
        sort(l.begin(), l.end());

        // Calculate the difference between the second and third elements of the vector
        int difference = l[2] - l[1];

        // Print the difference
        cout << difference << endl;
    }

    return 0;
}

// <END-OF-CODE>
