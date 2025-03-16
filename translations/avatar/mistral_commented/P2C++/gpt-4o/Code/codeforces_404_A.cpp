#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    // Take the number of rows as input
    int n;
    cin >> n;

    // Initialize a vector of vectors to store the rows
    vector<vector<string>> s(n);

    // Read each row and append it to the vector 's'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    // Initialize flags and empty sets and vectors
    set<string> rem;
    vector<string> d1, d2;

    // Iterate through each element in the vector 's'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If the current indices are the same, append the element to 'd1'
            if (i == j) {
                d1.push_back(s[i][j]);
            }
            // If the current indices are reverse of each other, append the element to 'd2'
            if (i == n - j - 1) {
                d2.push_back(s[i][j]);
            }
            // If the current indices are not the same and not reverse, add the element to 'rem' set
            if (i != j && i != n - j - 1) {
                rem.insert(s[i][j]);
            }
        }
    }

    // Check if the size of 'rem' set is not equal to 1
    if (rem.size() != 1) {
        // If the condition is true, print 'NO' and exit
        cout << "NO" << endl;
        return 0;
    }
    // Check if 'd1' and 'd2' vectors are equal
    else if (d1 != d2) {
        // If the condition is true, print 'NO' and exit
        cout << "NO" << endl;
        return 0;
    }
    // Check if all elements in 'd1' are the same
    else if (set<string>(d1.begin(), d1.end()).size() != 1) {
        // If the condition is true, print 'NO' and exit
        cout << "NO" << endl;
        return 0;
    }
    // Check if all elements in 'd1' are present in 'rem' set
    else if (rem.find(d1[0]) == rem.end()) {
        // If the condition is true, print 'NO' and exit
        cout << "NO" << endl;
        return 0;
    }
    // If all the above conditions are false, print 'YES'
    else {
        cout << "YES" << endl;
    }

    return 0;
}

// <END-OF-CODE>
