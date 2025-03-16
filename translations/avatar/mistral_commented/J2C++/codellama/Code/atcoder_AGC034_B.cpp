
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Main method that starts the program

    string s; // Input string
    cin >> s; // Read input string

    long cnt = 0; // Initialize counter for the number of "D"s
    long tmp = 0; // Initialize temporary variable for counting consecutive "A"s

    for (int i = 0; i < s.length(); i++) {
        // Loop through each character in the string

        if (s[i] == 'A') {
            // If the character is "A", increment the temporary counter
            tmp++;
        } else if (s[i] == 'D') {
            // If the character is "D", add the temporary counter to the total count
            cnt += tmp;
        } else {
            // If the character is neither "A" nor "D", reset the temporary counter
            tmp = 0;
        }
    }

    // Print the result
    cout << cnt << endl;

    return 0;
}

