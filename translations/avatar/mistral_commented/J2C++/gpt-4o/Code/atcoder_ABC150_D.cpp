#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using vectors
using namespace std; // Using the standard namespace

// Function to find the greatest common divisor of two numbers
long getGCD(long a, long b) {
    if (b == 0) { // Base case: if b is 0, return a as the gcd
        return a;
    } else {
        return getGCD(b, a % b); // Recursive call: finding the gcd of b and the remainder of a divided by b
    }
}

int main() { // Starting the main function
    int n, m; // Declaring variables n and m
    cin >> n >> m; // Reading the first integer n and the second integer m from standard input
    vector<int> a(n); // Creating a vector a of size n

    // Initializing the vector a with input values
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Reading an integer value
        a[i] /= 2; // Dividing it by 2 before storing it in the vector
    }

    long gcd; // Declaring a variable gcd to store the greatest common divisor
    long lcd = 1; // Declaring and initializing a variable lcm to store the least common multiple

    // Finding the least common multiple of all vector elements
    for (int i = 0; i < n; i++) {
        gcd = getGCD(lcd, a[i]); // Finding the greatest common divisor of lcm and the current vector element
        lcd = lcd * a[i] / gcd; // Updating the value of lcm

        // Checking if lcm is greater than m
        if (lcd > m) {
            cout << 0 << endl; // If true, printing 0 and returning from the function
            return 0;
        }
    }

    // Checking if any vector element is a factor of lcm
    for (int i = 0; i < n; i++) {
        if ((lcd / a[i]) % 2 == 0) { // Checking if the remainder of lcm divided by the current vector element is 0 and even
            cout << 0 << endl; // If true, printing 0 and returning from the function
            return 0;
        }
    }

    // Printing the result
    cout << (m / lcd + 1) / 2 << endl;

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
