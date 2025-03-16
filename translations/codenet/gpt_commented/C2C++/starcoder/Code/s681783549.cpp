#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // Declare an integer variable for iteration and a character array to store input
    int i;
    char S[6];

    // Read a string input from the user
    cin >> S;

    // Iterate through each character in the string until the null terminator is reached
    for(i = 0; S[i]!= '\0'; i++) {
        // Check if the current character is 'A' and the next character is 'C'
        if(S[i] == 'A' && S[i + 1] == 'C') {
            // If the condition is met, print "Yes" and exit the program
            cout << "Yes" << endl;
            return 0;
        }
    }

    // If the loop completes without finding "AC", print "No"
    cout << "No" << endl;
    return 0;
}

