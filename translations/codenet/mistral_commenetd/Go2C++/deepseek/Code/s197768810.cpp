#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Function to read an integer from standard input
int readInt() {
    string line;
    getline(cin, line);
    return stoi(line);
}

// Function to read a float64 from standard input
double readFloat64() {
    string line;
    getline(cin, line);
    return stod(line);
}

// Function to read a string from standard input
string readString() {
    string line;
    getline(cin, line);
    return line;
}

// Main function
int main() {
    // Set the scanner to read words as input
    // Read the number of elements n and the number of queries m from standard input
    int n = readInt();
    int m = readInt();
    // Allocate a vector a of size n
    vector<int> a(n);
    // Initialize a variable sum to keep track of the sum of elements in the array
    int sum = 0;
    // Process each query
    for (int i = 0; i < m; i++) {
        // Read an integer from standard input and add it to the vector a
        a[i] = readInt();
        // Add the current element to the sum
        sum += a[i];
        // Check if the sum is greater than the size of the array
        if (sum > n) {
            // If so, print -1 and exit the program
            cout << "-1" << endl;
            return 0;
        }
    }
    // Print the result, which is the difference between the size of the array and the sum of its elements
    cout << n - sum << endl;
    return 0;
}
