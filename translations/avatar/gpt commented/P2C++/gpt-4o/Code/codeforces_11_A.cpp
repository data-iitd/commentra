#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Read two integers n and d from input
    int n, d;
    cin >> n >> d;

    // Initialize a vector to store the elements
    vector<int> x(n);
    // Initialize variables to keep track of the total adjustments (m) and the current adjustment count (q)
    long long m = 0; // Use long long to avoid overflow
    int q = 0;

    // Read the elements of the list from input
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Iterate through the list to compare adjacent elements
    for (int a = 0; a < n - 1; a++) {
        // Check if the current element is greater than or equal to the next element
        if (x[a] >= x[a + 1]) {
            // Calculate how many increments of d are needed to make x[a + 1] greater than x[a]
            q = (x[a] - x[a + 1]) / d + 1;
            // Update the total adjustments made
            m += q;
            // Adjust the next element by adding the necessary increments of d
            x[a + 1] += q * d;
        }
    }

    // Print the total number of adjustments made
    cout << m << endl;

    return 0;
}

// <END-OF-CODE>
