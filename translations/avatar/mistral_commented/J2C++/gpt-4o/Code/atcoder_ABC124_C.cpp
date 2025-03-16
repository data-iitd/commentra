#include <iostream> // For standard input and output
#include <string>   // For using strings
#include <algorithm> // For using std::min
#include <sstream>  // For string stream
#include <vector>   // For using vectors

using namespace std;

class CColoringColorfully {
public:
    void solve(int testNumber) {
        string x;
        cin >> x; // Read the input string
        string a = x; // Create a copy of the string 'x' as 'a'
        string b = x; // Create a copy of the string 'x' as 'b'
        int a1 = 0; // Initialize counter for number of consecutive '1's in string 'a'
        int a2 = 0; // Initialize counter for number of consecutive '1's in string 'b'

        // Loop through each character in string 'a' starting from index 1
        for (size_t i = 1; i < x.length(); i++) {
            if (a[i] == a[i - 1]) { // Check if current character is same as previous character
                a[i] = (a[i] == '1') ? '0' : '1'; // Toggle the character
                a1++; // Increment counter for number of consecutive '1's
            }
        }

        // Loop through each character in string 'b' starting from the last character
        for (size_t i = x.length() - 1; i > 0; i--) {
            if (b[i] == b[i - 1]) { // Check if current character is same as previous character
                b[i - 1] = (b[i - 1] == '1') ? '0' : '1'; // Toggle the character
                a2++; // Increment counter for number of consecutive '1's
            }
        }

        // Print the minimum number of consecutive '1's in strings 'a' and 'b'
        cout << min(a1, a2) << endl;
    }
};

int main() {
    CColoringColorfully solver; // Initialize solver object
    solver.solve(1); // Solve the problem and print the output
    return 0; // Return success
}

// <END-OF-CODE>
