
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int flag = 0;
    vector<char> d1;  // Primary diagonal
    vector<char> d2;  // Secondary diagonal
    set<char> rem;  // Non-diagonal elements

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
            if (i!= j && i!= n - j - 1) {
                rem.insert(s[i][j]);
            }
        }
    }

    // Check conditions to determine the output
    // If the number of unique non-diagonal elements is not 1
    if (rem.size()!= 1) {
        cout << "NO" << endl;
    }
    // If the primary and secondary diagonals are not equal
    else if (d1!= d2) {
        cout << "NO" << endl;
    }
    // If the primary diagonal does not consist of the same element
    else if (set<char>(d1.begin(), d1.end()).size()!= 1) {
        cout << "NO" << endl;
    }
    // If the unique element in the primary diagonal is also in the non-diagonal set
    else if (set<char>(d1.begin(), d1.end()) == rem) {
        cout << "NO" << endl;
    }
    // If all conditions are satisfied, print 'YES'
    else {
        cout << "YES" << endl;
    }

    return 0;
}
