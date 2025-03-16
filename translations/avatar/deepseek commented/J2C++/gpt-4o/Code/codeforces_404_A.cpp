#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n; // Reading the size of the matrix
    vector<vector<char>> arr(n, vector<char>(n)); // Initializing the 2D character array
    vector<string> str(n); // Initializing the string array to store input strings

    // Reading n strings and storing them in the str array
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    // Populating the 2D character array from the strings
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = str[i][j];
        }
    }

    // Comparing the first two characters to determine a and b
    char a = arr[0][0];
    char b = arr[0][1];

    // If the characters are the same, print "NO" and exit
    if (a == b) {
        cout << "NO" << endl;
    } else {
        bool res = true; // Initialize result as true

        // Iterating through the matrix to validate the pattern
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) { // Check diagonal elements
                    if (arr[i][j] != a) { // If diagonal element is not a, set res to false
                        res = false;
                        break;
                    }
                } else { // Check off-diagonal elements
                    if (arr[i][j] != b) { // If off-diagonal element is not b, set res to false
                        res = false;
                        break;
                    }
                }
            }
        }

        // Printing the result
        if (res) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

// <END-OF-CODE>
