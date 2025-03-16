#include <iostream>
using namespace std;

int main() {
    int n, i, j, m, s, t;
    // Read the size of the array
    cin >> n;
    // Declare an array of size n
    int a[n];
    // Read n integers and store them in the array a
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Initialize t to 0, which will store the final sum of products
    t = 0;
    // Outer loop to iterate over each element in the array a
    for (i = 0; i < n; i++) {
        // Initialize s to 0, which will store the sum of products for the current element
        s = 0;
        // Inner loop to iterate over each element in the array a, skipping the current element
        for (j = 0; j < n; j++) {
            if (j <= i) {
                continue; // Skip the current element being processed by the outer loop
            }
            // Calculate the product of the current element and the current element in the inner loop
            m = a[i] * a[j];
            // Add the product to the sum s
            s = s + m;
        }
        // Add the sum s to the final sum t
        t = t + s;
    }
    // Print the final sum of products
    cout << t << endl;
    return 0;
}

