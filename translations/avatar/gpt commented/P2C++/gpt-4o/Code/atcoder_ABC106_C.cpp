#include <iostream>
#include <string>
using namespace std;

// Function to read a single integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single string from input
string readString() {
    string s;
    cin >> s;
    return s;
}

// Main function to process the input and return the result
int main() {
    // Reading a string from input
    string s = readString();
    // Reading an integer k from input
    int k = readInt();
    int l = 0;  // Initialize a counter for leading '1's

    // Count the number of leading '1's in the string
    for (char c : s) {
        if (c != '1') {
            break;
        }
        l++;
    }

    // If the count of leading '1's is greater than or equal to k, return 1
    if (l >= k) {
        cout << 1 << endl;
        return 0;
    }

    // Otherwise, return the character at position l in the string
    cout << s[l] << endl;
    return 0;
}

// <END-OF-CODE>
