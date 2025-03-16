#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    // Read the number of rows/columns for the square matrix
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input

    // Initialize a vector to store the input strings
    vector<string> s(n);

    // Read n strings from input and store them in the vector s
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }

    // Initialize vectors to store diagonal elements
    vector<char> d1;  // Primary diagonal
    vector<char> d2;  // Secondary diagonal

    // Initialize a set to store non-diagonal elements
    set<char> rem;

    // Iterate through the matrix to populate the diagonals and non-diagonal elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If it's a primary diagonal element
            if (i == j) {
                d1.push_back(s[i][j]);
            }
            // If it's a secondary diagonal element
            if (i == n - j - 1) {
                d2.push_back(s[i][j]);
            }
            // If it's a non-diagonal element
            if (i != j && i != n - j - 1) {
                rem.insert(s[i][j]);
            }
        }
    }

    // Check conditions to determine the output
    // If the number of unique non-diagonal elements is not 1
    if (rem.size() != 1) {
        cout << "NO" << endl;
    }
    // If the primary and secondary diagonals are not equal
    else if (d1 != d2) {
        cout << "NO" << endl;
    }
    // If the primary diagonal does not consist of the same element
    else if (set<char>(d1.begin(), d1.end()).size() != 1) {
        cout << "NO" << endl;
    }
    // If the unique element in the primary diagonal is also in the non-diagonal set
    else if (rem.count(d1[0]) > 0) {
        cout << "NO" << endl;
    }
    // If all conditions are satisfied, print 'YES'
    else {
        cout << "YES" << endl;
    }

    return 0;
}

// <END-OF-CODE>
