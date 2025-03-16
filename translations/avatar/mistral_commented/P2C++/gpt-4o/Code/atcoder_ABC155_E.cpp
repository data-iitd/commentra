#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// Define modulus constant
const int mod = 1000000007;

// Define main function 'main_b'
void main_b() {
    // Read input string 's'
    string s;
    cin >> s;

    // Initialize variables 'pp' and 'na'
    int pp = 0;
    int na = 0;

    // Iterate through each character in the input string 's' in reverse
    for (int i = s.size() - 1; i >= 0; --i) {
        char c = s[i];
        // Calculate current character value 'cc'
        int cc = na + (c - '0');
        na = 0;

        // Update 'pp' based on the current character value 'cc'
        if (cc <= 4) {
            pp += cc;
        } else {
            // If current character is the last character, add 1 to 'pp'
            if (i == s.size() - 1) {
                pp += 1;
            }
            // Otherwise, add 10 - 'cc' to 'pp'
            pp += 10 - cc;
        }
    }

    // Print the result 'pp'
    cout << pp << endl;
}

// Define main function 'main'
int main() {
    // Read input string 's'
    string s;
    cin >> s;

    // Initialize variables 'pmin' and 'mmin' with large initial values
    int pmin = 1000;
    int mmin = 0;

    // Add a leading zero to the input string 's'
    s = '0' + s;

    // Iterate through each character in the input string 's' in reverse
    for (int i = s.size() - 1; i >= 0; --i) {
        char c = s[i];
        // Calculate new minimum values 'npmin' and 'nmmin' based on current character value 'v' and previous minimum values 'pmin' and 'mmin'
        int npmin = min(pmin + 10 - (c - '0' + 1), mmin + 10 - (c - '0'));
        int nmmin = min(pmin + (c - '0' + 1), mmin + (c - '0'));

        // Update 'pmin' and 'mmin' with the new minimum values
        pmin = npmin;
        mmin = nmmin;
    }

    // Return the minimum value between 'pmin' and 'mmin'
    cout << min(pmin, mmin) << endl;

    return 0;
}

// Main program execution starts here
// Note: Clipboard and file input handling is omitted for simplicity

// <END-OF-CODE>
