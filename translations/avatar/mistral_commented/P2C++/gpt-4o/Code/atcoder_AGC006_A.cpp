#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Take an integer 'n' as input
    int n;
    cin >> n;

    // Take two strings 's' and 't' of length 'n' as input
    string s, t;
    cin >> s >> t;

    // Check if both strings 's' and 't' are equal or not
    if (s == t) {
        // If they are equal, print the value of 'n'
        cout << n << endl;
    } else {
        // Initialize a counter 'cnt' to store the length of the longest common substring
        int cnt = 0;

        // Iterate through all possible substrings of 's' starting from the first character
        for (int i = 0; i < n; i++) {
            // Iterate through all possible substrings of 't' starting from the first character
            for (int j = 0; j < n - i; j++) {
                // Check if the substring of 's' starting from index 'i+j' is equal to the substring of 't' starting from index 'j'
                if (s[i + j] != t[j]) {
                    // If they are not equal, break the inner loop and move to the next substring of 's'
                    break;
                }

                // If they are equal and we have reached the end of the substring of 's', update the value of 'cnt'
                if (j == n - i - 1) {
                    cnt = n - i;
                }
            }
        }

        // If 's' and 't' have no common substring, 'cnt' will be 0. In that case, print 2*n
        cout << 2 * n - cnt << endl;
    }

    return 0;
}

// <END-OF-CODE>
