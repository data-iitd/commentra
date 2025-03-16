#include <algorithm> // Include the algorithm library for sorting
#include <iostream>  // Include the iostream library for input and output
#include <vector>    // Include the vector library to use the vector container
using namespace std;

int main() {
    int n, k; // Declare variables for the number of elements and the number of largest elements to sum
    cin >> n >> k; // Read the values of n and k from standard input

    vector<int> l(n); // Create a vector of size n to store the elements
    for (int i = 0; i < n; i++) {
        cin >> l[i]; // Read each element into the vector
    }

    sort(l.begin(), l.end()); // Sort the vector in ascending order

    int ans = 0; // Initialize a variable to hold the sum of the largest k elements
    for (int i = 0; i < k; i++) {
        ans += l[n - 1 - i]; // Add the largest k elements to ans
    }

    cout << ans << endl; // Output the result
}

