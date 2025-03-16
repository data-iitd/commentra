// Importing necessary libraries
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Defining a static inner class FastReader for reading input
class FastReader {
public:
    // Method for reading next token
    string next() {
        string str;
        getline(cin, str);
        return str;
    }

    // Methods for reading specific types of input
    int nextInt() {
        int x;
        cin >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }

    double nextDouble() {
        double x;
        cin >> x;
        return x;
    }

    // Method to clear the input buffer
    void clearBuffer() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};

// Function for reversing a number
int reverse(int n) {
    // Base case for numbers less than 10
    if (n < 10)
        return n * 10;

    // Initializing variables
    int t = n, r = 0;

    // Reversing the number
    while (t > 0) {
        // Adding the digit to the reversed number
        r = (r * 10) + t % 10;

        // Moving to the next digit
        t = t / 10;
    }

    // Returning the reversed number
    return r;
}

// Main function
int main() {
    // Creating an instance of FastReader
    FastReader sc;

    // Reading input for number of test cases
    int n = sc.nextInt();

    // Reading input for number of operations
    int m = sc.nextInt();
    sc.clearBuffer(); // Clear the buffer after reading integers

    // Calling reverse function for m and adding it to n
    int t = reverse(m);
    cout << (t + n) << endl;

    return 0;
}

// <END-OF-CODE>
