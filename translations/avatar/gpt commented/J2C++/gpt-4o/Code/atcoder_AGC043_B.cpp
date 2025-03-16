#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

class Main {
public:
    // Method to calculate a specific value based on the input string and character
    int cal(const string& s, char c) {
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
        int n;
        cin >> n; // Read the integer input for the length of the string
        string s;
        cin >> s; // Read the string input
        stringstream sb; // Initialize a stringstream to build the new string
        
        // Build a new string based on the absolute differences between adjacent characters
        for (int i = 1; i < n; i++) {
            sb << abs(s[i] - s[i - 1]); // Append the absolute difference
        }
        
        // Special case when the length of the string is 2
        if (n == 2) {
            cout << sb.str()[0] << endl; // Print the first character of the new string
            return; // Exit the method
        }
        
        // Convert the stringstream to a string
        s = sb.str(); 
        
        // Check if the new string contains the character '1'
        if (s.find('1') != string::npos) {
            cout << cal(s, '1') << endl; // Calculate and print the result for character '1'
        } else {
            cout << cal(s, '2') * 2 << endl; // Calculate and print the result for character '2', multiplied by 2
        }
    }
};

int main() {
    Main().solve(); // Create an instance of Main and call the solve method
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
