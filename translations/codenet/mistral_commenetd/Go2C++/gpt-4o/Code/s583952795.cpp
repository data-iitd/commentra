#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

// Function to convert an integer to its string representation
string i2s(int i) {
    return to_string(i);
}

// Function to read an integer from standard input
int readInt() {
    int read;
    cin >> read;
    return read;
}

// Function to convert a number to its base-10 string representation with digit count K
string TenToN(int number, int n) {
    string s;
    int tmp = number; // Initialize temporary variable

    // Repeat the following process until the number becomes less than N
    while (true) {
        // Append the remainder of the division by N to the result string
        s = i2s(tmp % n) + s;

        // If the number is less than N, break the loop
        if (tmp < n) {
            break;
        }

        // Divide the number by N
        tmp /= n;
    }

    // Return the result string
    return s;
}

// Main function entry point
int main() {
    // Read input numbers N and K
    int N = readInt();
    int K = readInt();

    // Calculate the base-10 representation of N up to digit count K
    string s = TenToN(N, K);

    // Print the length of the calculated string
    cout << s.length() << endl;

    return 0;
}

// <END-OF-CODE>
