#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Take the input string 's' and an integer 'n' from the user
    string s;
    cin >> s;
    int n;
    cin >> n;

    // Initialize the answer variable 'ans' to 0
    int ans = 0;

    // Iterate through the given range 'n' times
    for (int i = 0; i < n; i++) {
        // Take the next string 'x' as input
        string x;
        cin >> x;

        // Initialize variables 'a' and 'b' to 0
        int a = 0, b = 0;

        // Iterate through each character 'j' in the string 's'
        for (char j : s) {
            // If the character 'j' matches the first character of the string 'x', increment 'a'
            if (j == x[0]) {
                a++;
            }
            // If the character 'j' matches the second character of the string 'x', increment 'b'
            else if (j == x[1]) {
                b++;
            }
            // If the current character 'j' does not match any character in the string 'x',
            // add the minimum of 'a' and 'b' to the answer variable 'ans' and reset 'a' and 'b' to 0
            else {
                ans += min(a, b);
                a = 0;
                b = 0;
            }
        }

        // Add the minimum of 'a' and 'b' to the answer variable 'ans' after the inner loop completes
        ans += min(a, b);
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
