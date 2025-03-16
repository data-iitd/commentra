#include <iostream>
#include <string>

using namespace std;

// Initialize an empty string variable named S
string S;

// Read a string input from the user
int main() {
    cin >> S;

    // Initialize a variable i with value 2
    int i = 2;

    // Start a for loop that runs as long as i is less than or equal to the length of the string S
    while (i <= S.length()) {

        // Check if the first half of the string S (from index 0 to (len(S)-i)/2) is equal to the second half of the string S (from index (len(S)-i)/2 to len(S)-i)
        if (S.substr(0, (S.length() - i) / 2) == S.substr((S.length() - i) / 2, (S.length() - i) / 2)) ) {

            // If the condition is true, print the length of the substring (len(S) - i) and break out of the loop
            cout << (S.length() - i) << endl;
            break;
        }

        // Increment the value of i by 2
        i += 2;
    }

    return 0;
}

// <END-OF-CODE>
