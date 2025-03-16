#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Function to read an integer from input
int readInt() {
    int i;
    cin >> i;
    return i;
}

// Function to read a float64 from input
double readFloat64() {
    double f;
    cin >> f;
    return f;
}

// Function to read a string from input
string readString() {
    string s;
    cin >> s;
    return s;
}

int main() {
    // Set the input to split by whitespace
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    // Read two integers n and m from input
    int n = readInt();
    int m = readInt();

    // Initialize a vector to hold m integers
    vector<int> a(m);

    // Initialize a variable to hold the sum of the integers read
    int sum = 0;

    // Read m integers from input and calculate their sum
    for (int i = 0; i < m; i++) {
        a[i] = readInt(); // Read an integer and store it in the vector
        sum += a[i]; // Add the integer to the sum
    }

    // Check if the sum of the integers exceeds n
    if (sum > n) {
        cout << "-1" << endl; // Print -1 if the sum is greater than n
        return 0; // Exit the function
    }

    // Print the difference between n and the sum of the integers
    cout << n - sum << endl;

    return 0;
}
