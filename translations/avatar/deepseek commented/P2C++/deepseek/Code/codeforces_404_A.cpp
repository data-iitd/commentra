#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;  // Take the size of the square matrix as input
    vector<string> s(n);  // Initialize a vector to store the matrix elements

    // Take n inputs, each representing a row of the matrix, and append these to the vector s
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    bool flag = false;  // Initialize flag to false
    vector<char> d1;  // Initialize a vector to store the diagonal elements from top-left to bottom-right
    vector<char> d2;  // Initialize a vector to store the diagonal elements from top-right to bottom-left
    set<char> rem;  // Initialize a set to store the non-diagonal elements

    // Iterate through the matrix to populate d1, d2, and rem with the appropriate elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {  // Check if the element is on the diagonal from top-left to bottom-right
                d1.push_back(s[i][j]);
            }
            if (i == n - j - 1) {  // Check if the element is on the diagonal from top-right to bottom-left
                d2.push_back(s[i][j]);
            }
            if (i != j && i != n - j - 1) {  // Check if the element is not on the diagonals
                rem.insert(s[i][j]);
            }
        }
    }

    // Check the conditions and print 'NO' or 'YES' based on the conditions
    if (rem.size() != 1) {
        cout << "NO" << endl;  // Print 'NO' if the set of non-diagonal elements does not have a single unique element
    } else if (d1 != d2) {
        cout << "NO" << endl;  // Print 'NO' if the two diagonals are not equal
    } else if (set<char>(d1.begin(), d1.end()).size() != 1) {
        cout << "NO" << endl;  // Print 'NO' if the diagonal elements do not all have the same value
    } else if (set<char>(d1.begin(), d1.end()) == rem) {
        cout << "NO" << endl;  // Print 'NO' if the set of diagonal elements is equal to the set of non-diagonal elements
    } else {
        cout << "YES" << endl;  // Print 'YES' if all conditions are met
    }

