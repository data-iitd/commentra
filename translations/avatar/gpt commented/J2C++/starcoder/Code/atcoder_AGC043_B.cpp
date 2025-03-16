#include <bits/stdc++.h>
using namespace std;

// Method to calculate a specific value based on the input string and character
int cal(string s, char c) {
    int n = s.length(); // Get the length of the string
    int m = n - 1; // Calculate the last index of the string
    int ans = 0; // Initialize the answer variable
    
    // Iterate through each character in the string
    for (int i = 0; i < n; i++) {
        // Check if the current character matches 'c' and if the bitwise AND of m and i equals i
        if (s[i] == c && (m & i) == i) {
            ans ^= 1; // Toggle the answer using XOR operation
        }
    }
    return ans; // Return the final calculated answer
}

// Main logic to solve the problem
void solve() {
    int n = sc.nextInt(); // Read the integer input for the length of the string
    string s = sc.next(); // Read the string input
    string ans = ""; // Initialize a string to build the new string
    
    // Build a new string based on the absolute differences between adjacent characters
    for (int i = 1; i < n; i++) {
        ans += to_string(abs(s[i] - s[i - 1])); // Append the absolute difference
    }
    
    // Special case when the length of the string is 2
    if (n == 2) {
        out << ans[0]; // Print the first character of the new string
        return; // Exit the method
    }
    
    // Check if the new string contains the character '1'
    if (ans.find("1")!= string::npos) {
        out << cal(ans, '1'); // Calculate and print the result for character '1'
    } else {
        out << cal(ans, '2') * 2; // Calculate and print the result for character '2', multiplied by 2
    }
}

// Static variables for output and input handling
static ostream out;
static istream cin;

// Main method to execute the program
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

