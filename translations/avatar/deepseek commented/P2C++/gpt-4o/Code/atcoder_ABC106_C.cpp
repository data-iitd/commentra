#include <iostream>
#include <string>
using namespace std;

// Function to read an integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Main function to execute the program
int main() {
    string s;  // Declare a string to hold the input
    cin >> s;  // Read the input string
    int k = readInt();  // Read the integer k
    int l = 0;  // Initialize a counter for leading '1's

    // Loop through each character in the string
    for (char c : s) {
        if (c != '1') {  // Check if the character is not '1'
            break;  // Exit the loop if a non-'1' character is found
        }
        l++;  // Increment the counter for each '1' found
    }

    // Check if the number of leading '1's is greater than or equal to k
    if (l >= k) {
        cout << 1 << endl;  // Print 1 if true
    } else {
        cout << s[l] << endl;  // Print the character at the position of the first non-'1' character
    }

    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
