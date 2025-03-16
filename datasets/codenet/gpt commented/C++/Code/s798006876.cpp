#include<iostream>

using namespace std;

// Define a constant for the maximum number of elements
const int MAX_N = 1e3;

// Array to hold input data
int data[MAX_N];

int main() {
    int m, nmi, nma;

    // Read inputs m, nmi, and nma until nmi is not equal to 0
    while (cin >> m >> nmi >> nma && nmi != 0) {
        // Read m elements into the data array
        for (int i = 0; i < m; i++) {
            cin >> data[i];
        }

        // Initialize variables to track the maximum difference and the answer index
        int ma = 0; // Maximum difference found
        int ans = 0; // Index of the element that gives the maximum difference

        // Loop through the specified range from nmi-1 to nma-1
        for (int i = nmi - 1; i < nma - 1; i++) {
            // Check if the current difference is greater than the maximum found so far
            if (ma <= data[i] - data[i + 1]) {
                ans = i + 1; // Update the answer index
                ma = data[i] - data[i + 1]; // Update the maximum difference
            }
        }

        // Output the index of the element that produced the maximum difference
        cout << ans << endl;
    }
}
