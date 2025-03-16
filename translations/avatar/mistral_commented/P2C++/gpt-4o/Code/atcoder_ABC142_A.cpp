#include <iostream>
using namespace std;

// Function to read an integer input from the user
int next_int() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from the user
void next_ints(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int main() {
    // Read an integer `n` from the user
    int n = next_int();
    // Initialize a variable `t` to zero
    int t = 0;

    // Iterate through the range of integers from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Check if the index i is odd
        if ((i + 1) & 1) {
            // If it is odd, increment the variable t by 1
            t += 1;
        }
    }
    // Print the result t/n as the output
    cout << static_cast<double>(t) / n << endl;

    return 0;
}

// <END-OF-CODE>
