#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declare variables for iteration, sum, and a flag
    int i, sum = 0;
    int flag = 0; // Note: 'flag' is declared but not used in this code
    string x; // String to store input strings

    // Read the first input string
    cin >> x;

    // Loop to process input until the termination condition is met
    do {
        // Iterate through the characters of the input string
        for (i = 0; i < x.length(); i++) {
            // Check for the end of the string (null character)
            if (x[i] == '\0') {
                // Print the sum of the digits in the string
                cout << sum << endl;
                break; // Exit the loop if end of string is reached
            } else {
                // Convert character to integer and add to sum
                sum += x[i] - '0'; // '0' is represented by 0x30 in ASCII
            }
        }
        
        // Reset sum for the next input
        sum = 0;

        // Read the next input string
        cin >> x;
    } while (x[0]!= '0'); // Continue until the first character is '0'

    return 0; // Exit the program
}

