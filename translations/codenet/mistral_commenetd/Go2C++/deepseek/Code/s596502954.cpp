#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Function to read a single word as a string from the input
string next() {
    string word;
    cin >> word;
    return word;
}

// Function to read an integer from the input
int nextInt() {
    int number;
    cin >> number;
    return number;
}

// Function to read a float64 from the input
double nextFloat64() {
    double number;
    cin >> number;
    return number;
}

// Function to read n integers from the input and return as a vector
vector<int> nextInts(int n) {
    vector<int> slice(n);
    for (int i = 0; i < n; i++) {
        cin >> slice[i];
    }
    return slice;
}

// Main function
int main() {
    // Read the first three integers from the input
    int a = nextInt();
    int b = nextInt();
    int c = nextInt();

    // Check if the condition is true
    if (a + b >= c) {
        // If true, print "Yes" to the output
        cout << "Yes" << endl;
    } else {
        // If false, print "No" to the output
        cout << "No" << endl;
    }

    // End of code
    return 0;
}
