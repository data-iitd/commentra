#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;  // Read the integer input `n`
    string s, t;
    cin >> s;  // Read the string `s` of length `n`
    cin >> t;  // Read the string `t` of length `n`

    // Check if the strings `s` and `t` are equal
    if (s == t) {
        cout << n << endl;  // If they are equal, print `n`
    } else {
        int cnt = 0;  // Initialize the counter `cnt` to 0
        // Compare elements of `s` and `t` starting from each index `i` of `s`
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                // If a mismatch is found, break out of the inner loop
                if (s[i + j] != t[j]) {
                    break;
                }
                // If the end of the inner list is reached without breaking, set `cnt`
                if (j == n - i - 1) {
                    cnt = n - i;
                }
            }
        }
        // Print `2 * n - cnt`
        cout << 2 * n - cnt << endl;
    }

    return 0;
}

// <END-OF-CODE>
