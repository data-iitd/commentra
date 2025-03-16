
#include <iostream>
#include <string>

using namespace std;

// Define a constant string "abcd"
const string LUCKY = "abcd";

int main() {
    // Ask the user to input an integer n
    int n;
    cin >> n;

    // Initialize an empty string s
    string s;

    // Use a for loop to iterate through the range of integers from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Add the character at index i % 4 of the string LUCKY to the string s
        s += LUCKY[i % 4];
    }

    // Print the final string s
    cout << s << endl;

    return 0;
}

