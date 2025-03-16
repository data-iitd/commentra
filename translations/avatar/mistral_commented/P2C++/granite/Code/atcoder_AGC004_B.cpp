
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Take input of number of test cases and number of elements in each test case
    int n, x;
    cin >> n >> x;

    // Initialize an empty vector 'a' to store the given elements
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Initialize a 2D vector 'b' of size n x n with None values
    vector<vector<int>> b(n, vector<int>(n, 0));

    // Iterate through each row of vector 'a'
    for (int i = 0; i < n; i++) {
        // Initialize a variable'm' to store the minimum element in the current row
        int m = a[i];

        // Iterate through each column of vector 'b'
        for (int j = 0; j < n; j++) {
            // Calculate the index 'k' based on the current row and column indices
            int k = i - j;

            // If the index 'k' is negative, add the size of vector 'n' to make it positive
            if (k < 0) {
                k += n;
            }

            // Update the minimum value of'm' with the minimum value of 'a[k]'
            m = min(m, a[k]);

            // Update the corresponding cell in vector 'b' with the minimum value of'm'
            b[j][i] = m;
        }
    }

    // Initialize a variable'm' with a large value to keep track of the minimum sum
    int m = 1000000000;

    // Iterate through each row of vector 'b'
    for (int i = 0; i < n; i++) {
        // Calculate the sum of elements in the current row and add 'x * i' to it
        int sum_row = accumulate(b[i].begin(), b[i].end(), 0) + x * i;

        // Update the minimum value of'm' with the sum of the current row
        m = min(m, sum_row);
    }

    // Print the minimum sum
    cout << m << endl;

    return 0;
}
