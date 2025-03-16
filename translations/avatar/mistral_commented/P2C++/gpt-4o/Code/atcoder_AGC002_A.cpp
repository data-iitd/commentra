#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a helper function to read a list of integers from the standard input stream
vector<int> readIntegers() {
    int a, b;
    cin >> a >> b;
    return {a, b};
}

int main() {
    // Define two variables and initialize them with the values read from the standard input stream
    vector<int> input = readIntegers();
    int a = input[0];
    int b = input[1];

    // Check if 'a' is positive
    if (a > 0) {
        // If it is, print the string 'Positive'
        cout << "Positive" << endl;
    }
    // If 'a' is not positive, check if 'b' is non-negative
    else if (a <= 0 && b >= 0) {
        // If it is, print the string 'Zero'
        cout << "Zero" << endl;
    }
    // If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
    else {
        // If it is, print the string 'Negative'
        if ((a + b) % 2 == 0) {
            cout << "Negative" << endl;
        }
        // Otherwise, print the string 'Positive'
        else {
            cout << "Positive" << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
