#include <bits/stdc++.h>
using namespace std;

// Define the modulo constant
const int mod = 1000000007;

// Function to calculate the value of a
int calc_a(int b) {
    return (2 * b) % mod;
}

// Function to calculate the value of b
int calc_b(int n) {
    return pow(2, 2 * n - 2, mod);
}

// Function to calculate the answer
int calc_ans(int n, vector<int> c) {
    // Initialize the answer variable
    int ans = 0;

    // Iterate through the sorted list
    for (int i = 0; i < n; i++) {
        // Update the answer by adding the product of the current element and (a + i * b)
        ans += c[i] * (calc_a(calc_b(n)) + i * calc_b(n));
        // Ensure the answer remains within the modulo
        ans %= mod;
    }

    // Return the final result
    return ans;
}

// Main function
int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the list of integers and convert them to a list of integers
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    // Sort the list in descending order
    sort(c.begin(), c.end(), greater<int>());

    // Print the final result
    cout << calc_ans(n, c) << endl;

    // Return from the main function
    return 0;
}

