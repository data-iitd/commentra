#include <iostream>
using namespace std;

// Define long long type for large integers
typedef long long ll;

// Declare variables
ll n, k, ans = 0, L, ans2 = 0;
string s;

int main(void) {
    // Read the number of characters (n) and the maximum number of operations (k)
    cin >> n >> k;
    
    // Read the string of characters
    cin >> s;

    // Initialize L with the first character of the string
    L = s[0];
    ll cnt = 0; // Initialize a counter for consecutive characters

    // Iterate through the string starting from the second character
    for (int i = 1; i < n; i++) {
        // If the current character is the same as the last character
        if (L == s[i]) {
            cnt++; // Increment the counter
        } else {
            // If the character changes, update L and add the count to ans
            L = s[i];
            ans += cnt; // Add the count of consecutive characters to ans
            ans2++; // Increment the number of distinct character groups
            cnt = 0; // Reset the counter for the new character
        }
    }

    // After the loop, add the count of the last group of characters to ans
    ans += cnt;
    ans2++; // Increment for the last group

    // Output the final result: total operations plus the minimum of 2*k or (number of groups - 1)
    cout << ans + min(2 * k, ans2 - 1) << endl;

    return 0; // End of the program
}
