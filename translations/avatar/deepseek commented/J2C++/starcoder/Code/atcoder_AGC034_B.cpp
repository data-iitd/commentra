
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Declare necessary variables.
    int testNumber; cin >> testNumber; // Read the number of test cases.
    for (int t = 0; t < testNumber; t++) {
        string s; cin >> s;
        // Read the input string.
        long cnt = 0; // Initialize a counter to keep track of the result.
        long tmp = 0; // Temporary variable to count consecutive 'A's.
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                tmp++; // Increment tmp if the current character is 'A'.
            } else if (s[i] == 'D') {
                cnt += tmp; // Add tmp to cnt if the current character is 'D'.
            } else {
                tmp = 0; // Reset tmp if the current character is not 'A' or 'D'.
            }
        }
        cout << cnt << endl; // Print the final count.
    }
    return 0;
}
// The above code is self-explanatory.

Translate the above C++ code to Python and end with comment "