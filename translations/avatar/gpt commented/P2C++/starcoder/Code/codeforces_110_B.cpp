#include <iostream>
using namespace std;

int main() {
    // Define a constant string containing the characters 'a', 'b', 'c', and 'd'
    const string LUCKY = "abcd";

    // Read an integer input from the user, which determines the length of the output string
    int n;
    cin >> n;

    // Initialize an empty string to store the result
    string s;

    // Loop through a range of 'n' to build the output string
    for (int i = 0; i < n; i++) {
        // Append the character from LUCKY based on the current index modulo 4
        // This ensures that the characters 'a', 'b', 'c', 'd' are repeated in the output
        s += LUCKY[i % 4];
    }

    // Print the final constructed string
    cout << s << endl;

    return 0;
}
