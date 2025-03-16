#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

// Function to read a single string from stdin
string Scanner() {
    string line;
    getline(cin, line);
    return line;
}

// Function to read an integer from stdin
int intScanner() {
    string line = Scanner();
    return stoi(line);
}

// Function to read a floating point number from stdin
double floatScanner() {
    string line = Scanner();
    return stod(line);
}

// Function to convert a string to an integer
int stringToInt(const string& s) {
    return stoi(s);
}

// Initialize the modulus value
const int mod = 1000000007;

// Initialize a vector to store the unique elements
vector<int> buf;

// Function to read input and process it
int main() {
    // Initialize the scanner buffer and split function for the scanner
    buf.reserve(mod);

    // Read the number of elements in the array
    int n = intScanner();

    // Initialize a vector of size n to store the elements
    vector<int> as(n);

    // Read the elements of the array into the as vector
    for (int i = 0; i < n; i++) {
        as[i] = intScanner();
    }

    // Initialize an empty vector xs to store the unique elements
    vector<int> xs = {as[0]};

    // Iterate through the array and add unique elements to the xs vector
    for (int j = 1; j < n; j++) {
        // Binary search to find the index where the current element should be inserted in the xs vector
        int idx = lower_bound(xs.begin(), xs.end(), as[j]) - xs.begin();

        // If the current element is not already present in the xs vector, append it
        if (idx == xs.size()) {
            xs.push_back(as[j]);
        } else {
            // Otherwise, replace the element at the found index with the current element
            xs[idx] = as[j];
        }
    }

    // Print the length of the xs vector
    cout << xs.size() << endl;

    return 0;
}
