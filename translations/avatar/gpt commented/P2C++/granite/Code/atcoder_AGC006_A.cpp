
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s, t;
    
    // Read the integer input which represents the length of the strings
    cin >> n;
    
    // Read the first string
    cin >> s;
    
    // Read the second string
    cin >> t;
    
    // Check if both strings are identical
    if (s == t) {
        // If they are the same, print the length of the strings
        cout << n << endl;
    } else {
        int cnt = 0;
        
        // Iterate over each character in the first string
        for (int i = 0; i < n; i++) {
            // For each character, check the subsequent characters in the second string
            for (int j = 0; j < n - i; j++) {
                // If characters at the current position do not match, break the inner loop
                if (s[i + j]!= t[j]) {
                    break;
                }
                
                // If we have matched all characters from this starting point
                if (j == n - i - 1) {
                    // Update the count of matching characters
                    cnt = n - i;
                }
            }
        }
        
        // Print the result based on the number of matching characters found
        cout << 2 * n - cnt << endl;
    }
    
    return 0;
}
