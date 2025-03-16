#include <iostream> // Include the iostream library for input and output
using namespace std; // Use the standard namespace

int main() { // Entry point of the program
    int n, k; // Declare integer variables n and k
    cin >> n; // Read the first integer `n` from the standard input
    cin >> k; // Read the second integer `k` from the standard input
    n++; // Increment the value of `n` by 1
    int z = 0; // Initialize an integer variable `z` to 0
    if (n % k != 0) { // Check if the remainder of `n` divided by `k` is equal to 0
        z = k - n % k; // If the remainder is not equal to 0, calculate the difference between `k` and the remainder and assign it to `z`
    }
    cout << n + z << endl; // Print the value of `n` plus the value of `z`
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
