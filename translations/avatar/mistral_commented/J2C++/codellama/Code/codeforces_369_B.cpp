
#include <iostream> // Including the iostream header for input and output
#include <cmath> // Including the cmath header for mathematical functions
#include <algorithm> // Including the algorithm header for sorting

using namespace std; // Using the standard namespace

int main() {
    int n, k, l, r, sAll, sk; // Declaring the variables n, k, l, r, sAll, and sk

    // Reading input values from the user
    cin >> n >> k >> l >> r >> sAll >> sk;

    // Creating an integer array ans of size n to store the updated scores of all points
    int ans[n];

    // Filling the initial scores of all points with the value l
    for (int i = 0; i < n; i++) {
        ans[i] = l;
    }

    // Calculating the remaining score after removing the given k points and segments of length l
    sAll -= sk + (n - k) * l;

    // Removing the score of the given k points
    sk -= k * l;

    // Finding the indices of the points to be increased in the first while loop
    int idx = n - 1;
    while (sk > 0 && idx >= n - k) {
        ans[idx--]++; // Increasing the score of the current point by 1
        sk--; // Decreasing the remaining score by 1
    }

    // Finding the indices of the points to be increased in the second while loop
    while (sAll > 0) {
        idx = 0;
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++; // Increasing the score of the current point by 1
            sAll--; // Decreasing the remaining score by 1
        }
    }

    // Printing the updated scores of all points
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " "; // Printing each updated score followed by a space
    }

    cout << endl; // Printing a newline after printing all scores

    return 0;
}

