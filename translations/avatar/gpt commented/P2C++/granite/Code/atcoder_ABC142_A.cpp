
#include <iostream>
#include <cmath>

using namespace std;

// Function to read a single integer from input
int next_int() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from input
vector<int> next_ints(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

int main() {
    // Read the number of iterations or elements
    int n = next_int();

    // Initialize a counter for odd indices
    int t = 0;

    // Loop through the range of n
    for (int i = 0; i < n; i++) {
        // Check if the current index (i + 1) is odd
        if ((i + 1) % 2 == 1) {
            t++;  // Increment the counter for odd indices
        }
    }

    // Calculate and print the ratio of odd indices to total elements
    cout << (double)t / n << endl;

    return 0;
}

