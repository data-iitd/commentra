#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    // Declare a string variable to hold the input
    string s;
    
    // Read the input string from the user
    cin >> s;
    
    // Get the size of the input string
    int n = s.size();
    
    // Initialize an array to count occurrences of each character (a-z)
    int v[26] = {};
    
    // Count the frequency of each character in the string
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a']++; // Increment the count for the corresponding character
    }
    
    // Assume the answer is "Yes" initially
    string ans = "Yes";
    
    // Check if each character's count is even
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 != 0) { // If any character has an odd count
            ans = "No"; // Set answer to "No"
            break; // Exit the loop early as we found an odd count
        }
    }
    
    // Output the result
    cout << ans << endl;
}
