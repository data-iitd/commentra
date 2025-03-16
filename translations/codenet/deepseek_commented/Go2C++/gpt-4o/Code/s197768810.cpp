#include <iostream>
#include <vector>

using namespace std;

// Function to read an integer from standard input
int readInt() {
    int i;
    cin >> i;
    return i;
}

// Main function to execute the program
int main() {
    // Read two integers n and m from the input
    int n = readInt();
    int m = readInt();

    // Initialize a vector to hold m integers
    vector<int> a(m);
    int sum = 0;

    // Read m integers into the vector a and calculate their sum
    for (int i = 0; i < m; i++) {
        a[i] = readInt();
        sum += a[i];
    }

    // Check if the sum of integers exceeds n
    if (sum > n) {
        // Print -1 if the sum exceeds n and exit
        cout << "-1" << endl;
        return 0;
    }

    // Print the difference between n and the sum if it's within bounds
    cout << (n - sum) << endl;

    return 0;
}

// <END-OF-CODE>
