#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements in the array
    vector<int> a(n); // Vector to store the elements
    bool f = false; // Flag to indicate if the triplet is found

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k = 0, j = 0, i = 0; // Initialize indices

    // Outer loop to iterate over each element as a potential a[k]
    for (k = 0; k < n; k++) {
        int t = a[k]; // Current element as t

        // Inner loops to find two indices i and j such that a[i] + a[j] = t
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1; j++) {
                if (i != j && t == (a[i] + a[j])) {
                    f = true; // Set flag to true if triplet is found
                    break; // Break out of the inner loop
                }
            }
            if (f) break; // Break out of the outer loop if triplet is found
        }
        if (f) break; // Break out of the main loop if triplet is found
    }

    // Check if a triplet was found and print the result
    if (f)
        cout << k + 1 << " " << j + 1 << " " << i + 1 << endl;
    else
        cout << "-1" << endl;

