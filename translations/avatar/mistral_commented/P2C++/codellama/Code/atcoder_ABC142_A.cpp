#include <iostream>
#include <cmath>
using namespace std;

// Define a function to read an integer input from the user
int next_int() {
    // Read an integer input from the user and convert it to an integer
    int n;
    cin >> n;
    return n;
}

// Define a function to read a list of integers from the user
int* next_ints(int n) {
    // Read a list of integers from the user and convert each element to an integer
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

int main() {
    // Read an integer `n` from the user
    int n = next_int();
    // Initialize a variable `t` to zero
    int t = 0;
    // Iterate through the range of integers from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Check if the index i is odd
        if (i + 1 & 1) {
            // If it is odd, increment the variable t by 1
            t += 1;
        }
    }
    // Print the result t/n as the output
    cout << t / n << endl;
    return 0;
}

