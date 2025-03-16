#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read the main string from user input
    string s;
    cin >> s;

    // Read the number of subsequent strings to process
    int n;
    cin >> n;

    // Initialize the answer variable to accumulate results
    int ans = 0;

    // Loop through each of the n strings provided by the user
    for (int i = 0; i < n; i++) {
        // Read the current string
        string x;
        cin >> x;

        // Initialize counters for characters matching the first and second characters of x
        int a = 0, b = 0;

        // Loop through each character in the main string s
        for (int j = 0; j < s.length(); j++) {
            // If the character matches the first character of x, increment counter a
            if (s[j] == x[0]) {
                a++;
            }
            // If the character matches the second character of x, increment counter b
            else if (s[j] == x[1]) {
                b++;
            }
            // If a character does not match either, add the minimum of a and b to ans
            else {
                ans += min(a, b);
                // Reset counters a and b for the next segment
                a = 0;
                b = 0;
            }
        }

        // After finishing the loop, add the minimum of a and b to ans for the last segment
        ans += min(a, b);
    }

    // Print the final accumulated answer
    cout << ans << endl;

    return 0;
}

