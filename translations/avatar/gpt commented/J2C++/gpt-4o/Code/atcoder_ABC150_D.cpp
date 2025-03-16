#include <iostream>
#include <vector>

using namespace std;

// Function to compute the greatest common divisor (gcd) using recursion
long getGCD(long a, long b) {
    if (b == 0) {
        return a;
    } else {
        return getGCD(b, a % b); // Recursive call to find gcd
    }
}

int main() {
    // Create a variable to read input
    int n, m;
    
    // Read the first integer n, which represents the number of elements
    cin >> n;
    
    // Read the second integer m, which represents the upper limit
    cin >> m;
    
    // Initialize a vector to hold the processed values
    vector<int> a(n);
    
    // Read n integers from input, divide each by 2, and store in vector a
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] /= 2; // Divide by 2
    }
    
    long gcd;
    long lcd = 1; // Initialize the least common denominator (lcd) to 1
    
    // Calculate the least common multiple (lcd) of the array elements
    for (int i = 0; i < n; i++) {
        gcd = getGCD(lcd, a[i]); // Get the greatest common divisor (gcd) of lcd and current element
        lcd = lcd * a[i] / gcd; // Update lcd using the formula: lcd = (lcd * a[i]) / gcd
        
        // If lcd exceeds m, print 0 and exit
        if (lcd > m) {
            cout << 0 << endl;
            return 0;
        }
    }
    
    // Check if the condition for each element in the array is satisfied
    for (int i = 0; i < n; i++) {
        // If lcd divided by the current element is even, print 0 and exit
        if ((lcd / a[i]) % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    
    // Calculate and print the final result based on the value of m and lcd
    cout << (m / lcd + 1) / 2 << endl;
    
    return 0;
}

// <END-OF-CODE>
